class Solution {
private:
    int pre(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    long long doCal(long long a, long long b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') {
            if (b == 0) return 0;
            return a / b;
        }
        return 0;
    }

public:
    int calculate(string s) {
        stack<long long> storeVal;
        stack<char> storeOp;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;

            if (s[i] >= '0' && s[i] <= '9') {
                long long val = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    val = (val * 10) + (s[i] - '0');
                    i++;
                }
                storeVal.push(val);
                i--;
            } else if (s[i] == '(') {
                storeOp.push(s[i]);
            } else if (s[i] == ')') {
                while (!storeOp.empty() && storeOp.top() != '(') {
                    long long val2 = storeVal.top(); storeVal.pop();
                    long long val1 = storeVal.top(); storeVal.pop();
                    char op = storeOp.top(); storeOp.pop();
                    storeVal.push(doCal(val1, val2, op));
                }
                if (!storeOp.empty()) storeOp.pop();
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int prev = i - 1;
                while (prev >= 0 && s[prev] == ' ') prev--;
                if (prev < 0 || s[prev] == '(') {
                    storeVal.push(0);
                }

                while (!storeOp.empty() && pre(storeOp.top()) >= pre(s[i])) {
                    long long val2 = storeVal.top(); storeVal.pop();
                    long long val1 = storeVal.top(); storeVal.pop();
                    char op = storeOp.top(); storeOp.pop();
                    storeVal.push(doCal(val1, val2, op));
                }
                storeOp.push(s[i]);
            }
        }

        while (!storeOp.empty()) {
            long long val2 = storeVal.top(); storeVal.pop();
            long long val1 = storeVal.top(); storeVal.pop();
            char op = storeOp.top(); storeOp.pop();
            storeVal.push(doCal(val1, val2, op));
        }

        return storeVal.empty() ? 0 : storeVal.top();
    }
};