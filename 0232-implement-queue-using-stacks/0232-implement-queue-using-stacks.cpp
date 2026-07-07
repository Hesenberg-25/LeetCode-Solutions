class MyQueue {
private:
    stack<int> st1, st2;

    void shifter() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        shifter();
        int frontElement = st2.top();
        st2.pop();
        return frontElement;
    }
    
    int peek() {
        shifter();
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};