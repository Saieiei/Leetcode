class Solution {
public:
    string makeFancyString(string s) {
        //i tried to do this without using any extra space
        //this was because teh string was rewritting itself using k index
        int freq = 0;
        int k = 0;
        int i = 0;
        int j = 1;
        //i and j will be used for camparing and to find out the freq of that char
        while(i<s.size()) //iterate through the string, no need to check for the last string 
        {
            freq = 0;
            bool same = true;
            while(same)
            {
                if(s[i] == s[j])  //if the letters r same then increase the freq
                {
                    freq++;
                    j++; //this will move the pointer j untill it finds a letter which is not same as s[i]
                }
                else break; //if the letters are not same the break the loop and 
            }
            if(freq>=2) //if the freq of the s[i] is more than 2
            {
                s[k] = s[i];
                k++;
                s[k] = s[i];
                k++;
                //max we can do is have only 2 same letters consecutively
            }
            else
            {
                if(freq == 0)  //is no same letters
                {
                    s[k] = s[i];
                    k++;
                }
                if(freq == 1) //is same letters but only 1
                {
                    s[k] = s[i];
                    k++;
                    s[k] = s[i];
                    k++;
                }
            }
            i = j; //after all transactions, update i to j, then put j 1 step forward
            j++;
        }
        s = s.substr(0, k); //we r doing substring because some times k can be lagging behind than i, it is not necessary that always k and i will be on the same index
        return s;
    }
};