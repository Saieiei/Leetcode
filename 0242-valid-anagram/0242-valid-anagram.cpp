//week5_ass_1
//we will use freq table, main aim is to check the number of then letters r same or not
//the vector freqTable will go upto 256(random)and will staore all as 0
//we will parse through each element of s, we will access the element in the freqTable(by converting it to int) and inc the value
//we will parse through each element of s, we will access the element in the freqTable(by converting it to int) and dec the value
//in the end if all the elements in freqTable ==0 then it is anagram else it is not

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTable[256]={0}; //calles as hashing table also

        //access each charcter in string s
        for(auto i:s)
        {
            freqTable[i]++; //automatic convertion of char to int
        }
        //access each charcter in string t
        for(auto i:t)
        {
            freqTable[i]--;//automatic convertion of char to int
        }
        //checking all th elements in freqTable == 0 or not
        for(int i=0;i<256;i++)
        {
            if(freqTable[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};