class Solution {
public:
    bool last_k_digits_same(string& ans, char& newChar, int k_1)
    {
        int it=ans.size()-1; //pointer pointing to the last char
        for(int i=0;i<k_1;i++)
        {
            if(ans[it]!=newChar) 
            {
                return false;

                
            }
            it--;
        }
        return true;
    }

    string removeDuplicates(string s, int k) {
        //everything is based on k-1 as we will b starting from 0
        //1st we will check if the string ans is less than k-1 size, if not then we will simply push in 
            //if not then we will have to check if the last (k-1) char r same, if same then we will simple pop k-1 chars
                //else we will simple push in
        //finally we will return the ans

        string ans;
        for(int i=0;i<s.size();i++)
        {
            char& newChar=s[i];
            if(ans.size()<k-1) //no need to worry just simply push
            {
                ans.push_back(newChar);
            } 
            else //checking if the last 2 chars in string ans r same to newChar if k=3(eg)
            {
                if(last_k_digits_same(ans, newChar, k-1)) //if they r same, then we will have to remove k-1 chars from ans
                {
                    for(int j=0;j<k-1;j++)
                    {
                        ans.pop_back(); //u can also use erase fuction but u should know the indexs
                    }
                }
                else //if the last 2 chars r not the same as the newChar then we can simply push it in if k=3(eg)
                {
                    ans.push_back(newChar);
                }
            }
        }
        return ans;
    }
};