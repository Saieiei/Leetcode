class Solution {
public:
    //string removeOccurrences(string s, string part) {
    //    while(s.find(part)!=string::npos) //which means found
    //    {
    //        s.erase(s.find(part), part.length());
    //    }
    //    return s;
    //}

    //we will try to solve this using recurssion
    //week7

    //1st we will find 

    void removeOccurRF(string &s, string part)
    {
        //1st we will find the index of the part in the string
        //calclulaions
        int FoundIndex=s.find(part);
        if(FoundIndex!=string::npos) //which means that it is actually there in the string, and did not exceed the string s
        {
            //now we will focus on removing the part from the string
            s.erase(FoundIndex, part.length()); //s.earse(erase from which index, length to be erased)
            //if u dont wish to use erase, then u can split it from left part and right part, then later on combine it
                //string left_part=s.substr(0, FoundIndex);
                //string right_part=s.substr(FoundIndex+part.length(), s.length());
                //s=left_part+right_part;      
                
            //recurssion for the rest
            removeOccurRF(s, part);
        }
        //base case
        return; //if the part is not founnd
    }

    string removeOccurrences(string s, string part) {
        //we will do manupulation on the string itself, so need of any return datatype
       removeOccurRF(s, part);
       return s;
    }
};