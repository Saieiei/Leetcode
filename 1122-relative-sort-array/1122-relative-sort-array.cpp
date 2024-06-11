class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int>freq;
        for(int c:arr1)
        {
            freq[c]++;
        }

        vector<int> ans;

        for(int c: arr2)
        {
            while(freq[c]--)
            {
                ans.push_back(c);
            }
        }

        
        for(auto & [ch, freqq]: freq)
        {
            if(freqq>0)
            {
                while(freq[ch]--)
                {
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};

//we will not user unordered_map<> because in the question it has been mentioned that, 
//for the characters not in arr2, 
//we will have to print it in ascending order, hence we will use 