class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        //priority queue (maxHeap)
        //take the top 2 freq chars
        //put them adjacent
        //decrease  their freq
        //push back into the priorty queue
        //repeat until its empty
        //N N
        //populate the freq
        vector<int> freq(26, 0);
        //travese through the string
        for(char ch: s){
            freq[ch - 'a']++;
        }
        //poplate the pq
        priority_queue<pair<int, char>> pq; //freq, char
        //becase, it will sort based on .first
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                //push it in pq
                pq.push({freq[i], i+'a'});
            }
        }
        //mathematical property
        //in a 5 chars, only 3 can be distinct
        //take the max freq
        int maxFreq = pq.top().first;
        if(maxFreq > (n+1)/2){
            //not possible
            return "";
        }
        //start filling now
        //always make sure 2 remains
        int index = 0;
        while(pq.size()>=2){
            pair<int, char> p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();
            //place them
            s[index] = p1.second;
            p1.first--;
            index++;
            s[index] = p2.second;
            p2.first--;
            index++;
            //push back in only if more freq remain
            if(p1.first > 0){
                pq.push(p1);
            }
            if(p2.first > 0){
                pq.push(p2);
            }
        }
        //if something remains because of odd
        if(!pq.empty()){
            s[index] = pq.top().second;
            pq.pop();
        }
        return s;
    }
};