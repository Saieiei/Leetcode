class Solution {
public:
    bool isValid(string s) {
        ////we can solve this q using recurssion
        ////what we have to do is we will find is the string has abc in it
        ////if it has then we will group the left side of the abc
        ////and we will group the right side of the abc
        ////then we will make new string which will be the combination of left side and the right side
        ////now this will go in recurssion untill the string becomes 0, if not then not possible 
//
        //if(s.size() == 0) return true;
        ////what we have to do is we will find is the string has abc in it
        //if(s.find("abc") != string::npos) //which means that the index of abc should not be outside the strings indexes
        //{
        //    string tLeft = s.substr(0, s.find("abc"));
        //    string tRight = s.substr(s.find("abc")+3, s.size());
        //    //s = tLeft + tRight;
        //    return isValid(tLeft + tRight);
        //}
        //return false;


        //u can also solve this using stack
        //thik it of like a candy crush saga game
        //if u get abc in order then that will be removed from the stack
        // in the end if the stack is empty then return true
        stack<char> st;
        if(s[0] != 'a') return false; //if the 1st character of th estring is not a then we cannot make it
        for(char ch : s)
        {
            if(ch == 'a') st.push(ch); //simply push it in the stack
            else if(ch == 'b')
            {
                if(!st.empty() && st.top() == 'a') st.push(ch); // if ur char is b and in the stack, if the top is not a then we cannot match it, but if the top is a then simply push b in the stack
                else return false;// top is not a 
            }
            else //now if the ch is c then we have to check if the top is b, if b then simply pop the a and b from the stack, if the top is not b then return false
            {
                if(!st.empty() && st.top() == 'b') st.pop();
                else return false;
                if(!st.empty() && st.top() == 'a') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};