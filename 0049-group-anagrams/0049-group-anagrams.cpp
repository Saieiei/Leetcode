//week5_ass_6
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //we have to use map
            //if u do not know map then map is like, there are 2 things in map(fisrt, second), u will be able to assign multiple values in second and   map it to 1 value to first
                //first         second
                //key           values
                ////map<string, vector<string>> mp      mp[str].push_back(st)   
                //for(auto it=mp.begin(); it!=mp.end(); i++)
                //{
                //  ans.push_back(it->second) //basically i am pushing back the vales of a mapped strings in a new vector called ans
                //}
        
        vector<vector<string>> ans;
        map<string, vector<string>> mp;

        for(auto word:strs)
        {
            string value=word;
            string key=sort(word.begin(), word.end()); //key
            mp[key].push_back(value);
        }

        for(auto it=mp.begin();it!=mp.end();it++) //iterator, to travel through each i of map
        {
            ans.push_back(it->second);
        }
        return ans;
        
    }

};