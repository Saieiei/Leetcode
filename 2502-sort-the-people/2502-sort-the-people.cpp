class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //we can solve this problem by using a hash map to associate each name with its corresponding height. Then, we can sort the heights in descending order and use the sorted heights to retrieve the names in the required order
        //letc create hash_map
        unordered_map<int, string> heightNameMP;
        //we will use the hrights as the index to store the names of the poeple
        for(int i=0; i<names.size(); i++)
        {
            heightNameMP[heights[i]] = names[i];
        }

        //now we will sort the heights in decending order
        sort(heights.begin(), heights.end(), greater<int> ());

        //now we will push the names in decending order, in vector ans
        vector<string> ans;
        for(int height : heights)
        {
            ans.push_back(heightNameMP[height]);
        }
        return ans;
    }
};