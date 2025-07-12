class Solution {
public:
    string removeOccurrences(string s, string part) {
        //dont break ur head with stacks or recurssions
        //use inbuild functions
        while(s.find(part) != string::npos) 
            s.erase(s.find(part), part.length());
        return s;
    }
};