class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty())s1.push(x);
        else {
            while(!s1.empty()) {
                int top = s1.top();
                s2.push(top);
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty())
            {
                int top = s2.top();
                s1.push(top);
                s2.pop();
            }
        }
    }

    int pop() {
        if(!s1.empty()) {
            int top = s1.top();
            s1.pop();
            return top;
        }
        else return -1;

    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};