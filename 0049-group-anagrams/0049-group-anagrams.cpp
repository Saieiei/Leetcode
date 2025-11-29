//week5_ass_6
//method 2 map(hash)
class Solution {
public:

    std::array<int, 256>hash(string str) 
    {
        std::array<int, 256>hash={0}; //the function name and the variable name both r hash
        for(char i:str)
        {
            hash[i]++;
        }
        return hash;
        //everytime u will return a new hash

    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //we have to use map(sorting-hashing(mapping))
            //if u do not know map then map is like, there are 2 things in map(fisrt, second), u will be able to assign multiple values in second(groups) and   map it to 1 value to first
                //first         second
                //key           values
                //e=1
                //a=1
                //t=1         {"eat","tea","ate"}
                //map<std::array<int, 256>, vector<string>> mp      mp[hash(str)].push_back(st), over here    std::array<int, 256> is same as int array[256]={0}, and hash is a function 
                //for(auto it=mp.begin(); it!=mp.end(); i++)
                //{
                //  ans.push_back(it->second) //basically i am pushing back the values of a mapped strings in a new vector called ans
                //}
        
        vector<vector<string>> ans;
        map<std::array<int, 256>, vector<string>> mp;

        //everytime u will ask to hash the word
        for(auto word:strs)
        {
            mp[hash(word)].push_back(word);
            //if that hash table is already present it will get mapped accordingly
        }

        for(auto it=mp.begin();it!=mp.end();it++) //iterator, to travel through each i of map
        {
            ans.push_back(it->second);
        }
        return ans;
        
    }

};