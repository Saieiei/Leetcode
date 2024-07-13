class Solution {
public:
    int findTheWinner(int n, int k) {
       //list<int> ls;
       //for(int i = 1; i <= n; i++) {
       //    ls.push_back(i);
       //}

       //auto index = ls.begin();
       //while(ls.size() > 1) {
       //    // Move iterator k-1 steps ahead, because we already considering 1 atleady
       //    for(int i = 1; i < k; i++) {
       //        index++;
       //        if(index == ls.end()) index = ls.begin(); // wrap around
       //    }
       //    // Erase the k-th friend
       //    index = ls.erase(index);
       //    if(index == ls.end()) index = ls.begin(); // wrap around if reached end
       //}

       //return ls.front();

       //week12
       //we can also solve this q using queue
       queue<int> q;

       //ist put all the leemnt in the queu
       for(int i=1;i<=n;i++) q.push(i);

       //now poppin agame
       while(q.size() != 1) //only 1 element should remain in the queue
        {
            for(int i=0;i<k;i++) //the kth element will be popped
            {
                if(i == k-1) q.pop(); //killed
                else //else push it behind to maintain circularity
                {
                    int tempNum = q.front();
                    q.pop();
                    q.push(tempNum);
                }
            }
        }
        return q.front(); //only 1 element in the queue
    }
};