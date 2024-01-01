class Solution {
public:
    string reorganizeString(string s) {
        //for this to work we need a hash
        //hash will store all the number of times a charcter has occured
        //then will find the most occuring element
        //we will place that in alternate places and if it is exceeding the length of the string(s) then it is not possible return null ("")
        //if it was possble to store the most repeating elements in alternate places then we will continue to place the rest of the chars in the 
            //available positions

        //creating hash
        int hash[26]={0};

        for(auto ch:s) //updating the frequency of each char using hash table
        {
            int position=ch-'a';
            hash[position]=hash[position]+1;
        }

        //fiding the maxium frequenct charcter
        int max_freq=INT_MIN;
        char max_freq_char;
        for(int i=0;i<26;i++) //for every element in hash
        {
            if(hash[i]>max_freq)
            {
                max_freq=hash[i];
                max_freq_char=i+'a';
            }
        }

        //now lets allocate the max_freq_char in alternate position
        int index=0;
        while(index<s.size() && max_freq>0)
        {
            s[index]=max_freq_char;
            index=index+2;
            max_freq--;
        }

        //if we were not able to allocate the max_freq in alternate positions then its not possible
        if(max_freq>0) return "";
        else //all have been succesfully allocated, now we can procede allocating the rest
        {
             hash[max_freq_char-'a']=0;
            for(int i=0;i<26;i++)
            {
                while(hash[i]>0)
                {
                    index=index>=s.size()?1:index;
                    s[index]=i+'a';
                    hash[i]--;
                    index=index+2;
                }
            }
        }
        return s;
    }
};