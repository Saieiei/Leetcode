class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> ls;
        for(int i = 1; i <= n; i++) {
            ls.push_back(i);
        }

        auto index = ls.begin();
        while(ls.size() > 1) {
            // Move iterator k-1 steps ahead, because we already considering 1 atleady
            for(int i = 1; i < k; i++) {
                index++;
                if(index == ls.end()) index = ls.begin(); // wrap around
            }
            // Erase the k-th friend
            index = ls.erase(index);
            if(index == ls.end()) index = ls.begin(); // wrap around if reached end
        }

        return ls.front();
    }
};