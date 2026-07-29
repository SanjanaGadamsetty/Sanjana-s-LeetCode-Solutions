class MinStack {
public:
    stack<int> St;
    stack<int> minStack;
    MinStack() {
        St= {};
        minStack= {};
    }
    
    void push(int value) {
        St.push(value);
        if (minStack.empty() || minStack.top()>= value) minStack.push(value);
    }
    
    void pop() {
        if (St.top()== minStack.top()){
            St.pop();
            minStack.pop();
        }
        else St.pop();
    }
    
    int top() {
        return St.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */