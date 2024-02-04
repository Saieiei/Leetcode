//https://www.youtube.com/watch?v=3Bp3OVD1EGc
//we will use map on t to check if we need those letters or not, 
//we will use the concept of sliding window
//we need to make user that all the eleemnts of t r present in s so we will use cound required that will be the length of the t
//ur i and j will be at the benginging, j will go forward if ur count required is >1
//ur i will move forward if ur count required<=0
//the program will end if ur j goes out of bonds
//the length of teh substring will be j-i+1
//everythime when u get countrequired=0 find the length of the substring, if the substring is less than the previous value then u can keep it else discard
//count required will be manupulated based on the map
    //if j corsses the  required the letter then -1 on the map of the element and so countrequired=countrequired-1
    //if i crosses the required letter then +1 on the the map of the element and so count required=countrequired+1 
class Solution {
public:
    string minWindow(string s, string t) {

        int minLength=INT_MAX;
        int start_i=0;//we will be neededing this to clear out unwanted chars while shrinking.
        int currentLength=0;
    
        //lets create a map
        unordered_map<char, int>mp;
        //lets map the chars in the map
        for(char i:t)
        {
            mp[i]++;
        }

        int countRequired=0;
        countRequired=t.length();

        //innitial termination condition
        if(s.length()<t.length())
            return ""; //not possible

        int j=0,i=0; //make sure to put both as 0
        
        while(j<s.length())
        {
            char ch=s[j];

            if(mp[ch]>0) //element present in the map
            {
                countRequired--;
            }
            mp[ch]--; //we have to anyway decrease it anyway irrespective of the fact that it is present in the map or not. so dont keep it inside the if condition

            while(countRequired==0) //noting down the value of the length of the substring and shrinking
            {
                currentLength=j-i+1;
                if(currentLength<minLength)
                {
                    minLength=currentLength;
                    start_i=i; //we will be neededing this to clear out unwanted chars while shrinking. //make sure this is in side the if statement
                }
                
                mp[s[i]]++; //we have to anyway increase it anyway irrespective of the fact that it is present in the map or not. so dont keep it inside the if condition
                //dont worry the value that is not required in t can never be greater than 0.
                if(mp[s[i]]>0)
                {
                    countRequired++;
                }
                i++;
            }
            j++;
        }
        return minLength==INT_MAX ? "" : s.substr(start_i, minLength);
    }
};