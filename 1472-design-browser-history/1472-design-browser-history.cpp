//this can be done using vectors and stacks, we will be doing this using stacks
//we will take the advantage of LIFO of stacks


class BrowserHistory {
//i am creating this private 1 for getting the tools
private:
    stack<string>history; // back stack, top = current page
    stack<string>front; // forward stack
public:
//ctor
    BrowserHistory(string homepage) {
        //this is the very 1st case of creating the object with the homepage 
        history.push(homepage);
    }
    
    void visit(string url) {
        // drop any forward history
        if (!front.empty()) {
            while(!front.empty()) front.pop();
        }
        // now append the new page
        history.push(url);
    }
    
    string back(int steps) {
        while(history.size()>1 && steps)
        {

            string temp = history.top(); history.pop();
            front.push(temp);
            steps--;

        }
        return history.top();
    }
    
    string forward(int steps) {
        while(!front.empty() && steps){

            string temp = front.top(); front.pop();
            history.push(temp);
            steps--;

        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */