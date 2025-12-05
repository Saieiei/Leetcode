
class MyComparator{
    public:
    bool operator()(pair<int, string>& p1, pair<int, string>& p2){
        //incase the freq is same then alphabetic order
        if(p1.first == p2.first) return p1.second<p2.second;
        //else return base on higher freq
        else return p1.first>p2.first;
    }
};

//there are 2 ways to do this (hahsmaps + pq) or with tries
//here we will go with prior 1
//u can solve this with maxheap, but we will do it minheap with our custome comparator
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        //frequency of the word
        for(string word: words){
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComparator>pq;

        //push all of them from map to pq
        for(auto it: mp){
            pq.push({it.second, it.first});

            //now the top elements of pq will be the least freq
            //so if the size of pq > k then pop them
            if(pq.size()>k) pq.pop();
        }
        
        //now we have top k pairs but in decending order (min heap)
        int index = k-1;
        vector<string> ans(k);
        while(!pq.empty()){
            pair<int, string> front = pq.top(); pq.pop();
            ans[index--] = front.second;
        }

        return ans;

    }
};