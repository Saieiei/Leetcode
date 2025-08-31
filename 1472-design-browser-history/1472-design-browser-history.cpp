//this can be done using vectors and string, we will be doing this using vectors
//we will keep the track of the maxIndex because incase we go back and go to a nex page then we need to update history completely
//other than that its all fine
//we will also keep the track of the currIndex

class BrowserHistory {
//i am creating this private 1 for getting the tools
private:
    vector<string>history;
    int maxIndex;
    int currIndex;
public:
//ctor
    BrowserHistory(string homepage) {
        //this is the very 1st case of creating the object with the homepage 
        history.push_back(homepage);
        currIndex = 0;
        maxIndex = currIndex;
    }
    
    void visit(string url) {
        // drop any forward history
        if (currIndex + 1 < (int)history.size()) {
            history.resize(currIndex + 1);
        }
        // now append the new page
        history.push_back(url);
        currIndex++;
        maxIndex = currIndex;  // new tail
    }
    
    string back(int steps) {
        //incase he presses too many backs than the required no of urls present in the history
        currIndex = max(0, currIndex-steps);
        //no need to update the maxIndex
        return history[currIndex];
    }
    
    string forward(int steps) {
        //incase he presses too many forward button than the required no of urls present in the history
        currIndex = min(maxIndex, currIndex+steps);
        //no need to update the maxIndex
        return history[currIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */