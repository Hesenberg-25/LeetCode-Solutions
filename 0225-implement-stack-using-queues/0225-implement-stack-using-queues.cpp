class MyStack {
private:
    queue<int> que;

public:
    MyStack() {
    }
    
    void push(int x) {
        int sized = que.size();
        que.push(x);
        for (int i = 0; i < sized; i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int frontElement = que.front();
        que.pop();
        return frontElement;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};