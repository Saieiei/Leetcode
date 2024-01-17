class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //method1 we can use unordered_map to calculate the frequencies and unordered_set to check if the elemrnt is already present or not(by inserting and .second)

        unordered_map<int, int>freqArr;
        unordered_set<int> Checker;

        for(int num:arr)
        {
            freqArr[num]++;
        }

        for(auto entry: freqArr)
        {
            if(!Checker.insert(entry.second).second) //flase * flase = true
            {
                return false;
            };
        }
        return true;

    }
};