//week5_ass_5
//mapping
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //we will use mapping method
        //if u do not know what is mapping, it is basically a array of numbers all(256) initialized to 0
            // ok but how do we map 2 strings with a array?
                //the 1st string characters will act as the index of the arry
                //the 2nd string charcters will act as the values that will be mapped to that index with the help of charcters
        
        //ok so now uk what is mapping
        //After mapping the charcters we also have to make sure that we dont map the characters to some new charcters if its alreay mapped
            //how do we do that?
                //this will also use the concept of mapping
                //we have to create a new array[256], the characters of 2nd string will act as index ans the value will be updated to 1 if already done
        
        //in the end we will use the mapping that we had created and check if we r able to get the characters of t using the mapping
            //if so then true, else false
        
        int mapping[256]={0};
        bool checker[256]={0};

        for(int i=0;i<s.size();i++)
        {
            if(checker[t[i]]==0 && mapping[s[i]]==0  ) //not mapped yet
            {
                mapping[s[i]]=t[i]; //update the mapping
                checker[t[i]]=true; //update the checker
            }
        }
        
        //testing using mapping
        for(int i=0;i<s.size();i++)
        {
            char ch=mapping[s[i]];
            if(ch!=t[i])
            {
                return false;
            }
        }
        return true;
        
    }
};