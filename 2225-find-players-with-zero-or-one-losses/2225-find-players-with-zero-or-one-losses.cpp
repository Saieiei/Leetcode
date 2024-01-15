#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> freqMatches;
        set <int> W, L; //only 1 and in order

        // Finding frequencies and separting winners and loosers
        for (auto match : matches) {
            freqMatches[match[1]]++; // Increment the count for the loser
            W.insert(match[0]); //winners in 1 set
            L.insert(match[1]); //loosers in 1 set
        }

        // 2 new vectors
        vector<int> noLoss;
        vector<int> oneLoss;
        vector<vector<int>> ans;

        //no loss
        for(auto winner:W)
        {
            if(freqMatches.find(winner)==freqMatches.end()) //not found in the loser freq
            {
                noLoss.push_back(winner);
            }
        }

        //one loss
        for(auto loosers:L )
        {
            if(freqMatches[loosers]==1)
            {
                oneLoss.push_back(loosers);
            }
        }

        // Sorting
        sort(noLoss.begin(), noLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        ans.push_back(noLoss);
        ans.push_back(oneLoss);

        return ans;
    }
};
