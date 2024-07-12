class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        //u can solve this q using 2 queues, 
            //push what ever elements into q1
            //now push all the elements from q1 to q2
            //then push all the elements from q2 to q1
            //ur final q1 will behave like a stack now
        //put we will solve it using 1 queue only

        //just push the element into q
        //then pop and push the element q.size()-1 times
        q.push(x);
        for(int i=0; i<q.size()-1; i++)
        {
            int tempNum = q.front();
            q.pop();
            q.push(tempNum);
        }
    }
    
    int pop() {
        //return q.pop(); //dont do this, it wont woek
        int popNum = q.front();
        q.pop();
        return popNum;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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