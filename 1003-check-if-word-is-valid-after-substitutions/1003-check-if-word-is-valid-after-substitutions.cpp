class Solution {
public:
    bool isValid(string s) {
        //we can solve this q using recurssion
        //what we have to do is we will find is the string has abc in it
        //if it has then we will group the left side of the abc
        //and we will group the right side of the abc
        //then we will make new string which will be the combination of left side and the right side
        //now this will go in recurssion untill the string becomes 0, if not then not possible 

        if(s.size() == 0) return true;
        //what we have to do is we will find is the string has abc in it
        if(s.find("abc") != string::npos) //which means that the index of abc should not be outside the strings indexes
        {
            string tLeft = s.substr(0, s.find("abc"));
            string tRight = s.substr(s.find("abc")+3, s.size());
            //s = tLeft + tRight;
            return isValid(tLeft + tRight);
        }
        return false;
    }
};