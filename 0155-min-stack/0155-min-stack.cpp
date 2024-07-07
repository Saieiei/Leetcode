class MinStack {
public:
    // we will solve this using vector<pair<>>as a stck concept, where the rightmot element will give the minimu element
    vector<pair<int, int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        //if we r inerting the element for the 1t time, that mean our left and right will be the same
        if(st.empty())
        {
            //so we will create a pair, and put that pair inside the vector
            pair<int, int> pr;
            pr.first = val; //dont put first(), its wrong
            pr.second = val; //dont put second(), its wrong
            //now we will put the val into the vector
            st.push_back(pr);
        }
        else //if we r not inserting the element for the 1st time, then we will have to find the min and update the rightmost pair
        {
            pair<int, int> pr;
            pr.first = val;
            pr.second = min(val, st.back().second); //dont do st.back(.second)
            //now push the elemnt in the vector
            st.push_back(pr);
            //and so we r able to keep track of min value if, elements r getting inserted
        }
    }
    
    void pop() {
        //before popping we have to check if the stack(vector) is empty or not
        if(!st.empty()) st.pop_back(); //dont do st.pop(), as this is not a stack, we r popping a vector here 
        
    }
    
    int top() {
        //we will have to display the 1st element of the pair
        pair<int, int> pr;
        pr = st.back();
        return pr.first;
    }
    
    int getMin() {
        //we have to simply display the second element of the pair of the vector
        pair<int, int> pr;
        pr = st.back();
        return pr.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */