class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        bool fromLeft = true;
        while (n > 1) {
            if (fromLeft || n % 2 == 1)
                head += step;
            n /= 2;
            step *= 2;
            fromLeft = !fromLeft;
        }
        return head;
    }
};   