class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        q1= {};
        q2= {};
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n= q1.size();
        while (n> 1){
            q2.push(q1.front());
            q1.pop();
            n--;
        }
        int qe= q1.front();
        q1.pop();
        swap(q1, q2);
        return qe;
    }
    
    int top() {
        while (q1.size()> 1){
            q2.push(q1.front());
            q1.pop();
        }
        int qe= q1.front();
        q2.push(qe);
        q1.pop();
        swap(q1, q2);
        return qe;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */