class Solution {
public:
    string removeDuplicates(string s, int k) {
        //special 2 pointers approach (all will be done inplace)
        //we will use i where the element has to be inserted
            //we will use j will keep on iterating through the string
            //1st s[i]=s[j]
            //2nd count[i]=1;
            //3rd if(i>0 && s[i]==s[i-1])
                //count[i]=count[i-1]
            //if(count[i]==k)
                //i=i-k (we dont have yo pop anything, automatically it will be overridden)
            //i++; j++;
            //finally when j becomes out of bound then we can return the ans that is from 0 to i (substring)

        int i=0, j=0;
        vector<int>count(s.size());
        //You are using the vector<int> count without initializing its size. This can lead to undefined behavior when you try to access elements using the index. You should either initialize the vector with a specific size or use push_back to dynamically grow the vector. Hence mention the size
        while(j<s.size())
        {
            s[i]=s[j];
            count[i]=1;
            if(i>0 && s[i]==s[i-1])
            {
                count[i]=count[i]+count[i-1];
            }
            if(count[i]==k)
            {
                i=i-k;
            }
            i++; j++;
        }
        string ans=s.substr(0, i);
        return ans;

    }
};