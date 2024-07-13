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

       //week11
       //we can also solve this q using queue
       queue<int> q;

       //ist put all the leemnt in the queu
       for(int i=1;i<=n;i++) q.push(i);

       //now poppin agame
       while(q.size() != 1)
        {
            for(int i=0;i<k;i++)
            {
                if(i == k-1) q.pop();
                else
                {
                    int tempNum = q.front();
                    q.pop();
                    q.push(tempNum);
                }
            }
        }
        return q.front();
    }
};