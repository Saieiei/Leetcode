class Solution {
public:
    int findTheWinner(int n, int k) {
        std::list<int> vec;
        for(int i = 1; i <= n; i++) {
            vec.push_back(i);
        }

        auto index = vec.begin();
        while(vec.size() > 1) {
            // Move iterator k-1 steps ahead, because we already considering 1 atleady
            for(int i = 1; i < k; i++) {
                index++;
                if(index == vec.end()) index = vec.begin(); // wrap around
            }
            // Erase the k-th friend
            index = vec.erase(index);
            if(index == vec.end()) index = vec.begin(); // wrap around if reached end
        }

        return vec.front();
    }
};