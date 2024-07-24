class Solution {
public:
    int mapper(int num, vector<int>& mapping)
    {
        ////we will try to map the numbers by converting it to string 
        ////u can also do it using remainder and quortient technique
        //string convertedNum = "";
        //string stringNum = to_string(num);
        //for(char digit: stringNum)
        //{
        //    int index = digit - '0';
        //    convertedNum = convertedNum + to_string(mapping[index]);
        //}
        //return stoi(convertedNum);
        //TLE

        //we will solve using  remainder and quortient technique
        int mappedNum = 0;
        int factor = 1;
        if(num == 0) return mapping[0]; 
        while(num > 0)
        {
            int remainder = num % 10;
            mappedNum = mappedNum + mapping[remainder] * factor;
            factor = factor*10;
            num = num/10;
        }
        return mappedNum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //we will solve this based on a comparator, whoch will be the index
        vector<int> indexes(nums.size());
        for(int i=0; i<nums.size(); i++) indexes[i] = i; //u can also do the same line using this function, iota(indexes.begin(), indexes.end(), 0);

        //custom comparator
        sort(indexes.begin(), indexes.end(), [&](int i, int j)
        {
            int mappedNumi = mapper(nums[i], mapping);
            int mappedNumj = mapper(nums[j], mapping); 
            if(mappedNumi != mappedNumj) return mappedNumi < mappedNumj;
            return i<j;
        });

        //the values in the ans
        vector<int> ans;
        for(int index: indexes) ans.push_back(nums[index]);
        return ans;
    }

};