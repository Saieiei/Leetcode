class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        //we shall use mapping 
        unordered_map<int, int>freqArray;
        for(int num: nums)
        {
            freqArray[num]++;
        }

        //now we shall find the maximum frequency
        int maxFreq=0;
        for(auto num:freqArray)
        {
            maxFreq=max(maxFreq, num.second);
        }

        int count = 0;
        for (const auto& num : freqArray) {
            if (num.second == maxFreq) {
                count += num.second;
            }
        }

       return count;
    }
};