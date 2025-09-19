class RecentCounter {
    //week 11
    //we should solve this q using queues, as it makes more scence to do so 
    queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        //if the value i out of range, then pop
        while(!q.empty() && q.front() < t-3000) q.pop();

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */