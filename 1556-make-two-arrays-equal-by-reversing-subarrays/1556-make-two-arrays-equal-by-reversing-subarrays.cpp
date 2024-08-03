class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        //sort(target.begin(), target.end());
        //sort(arr.begin(), arr.end());
        //for(int i=0;i<target.size();i++)
        //{
        //    if(target[i] != arr[i]) return false;
        //}
        //return true;

        //u can also solve it based on freq
        unordered_map<int, int> targetFreq;
        unordered_map<int, int> arrFreq;

        //finding freq
        for(int i=0;i<target.size();i++)
        {
            targetFreq[target[i]]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            arrFreq[arr[i]]++;
        }

        //now eliminating
        if(targetFreq.size() != arrFreq.size()) return false;

        for(auto pair: targetFreq)
        {
            if(arrFreq[pair.first] != pair.second) return false;
        }
        return true;
    }
};