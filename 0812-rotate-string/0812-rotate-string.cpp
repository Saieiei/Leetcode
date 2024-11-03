class Solution {
public:
    bool rotateString(string s, string goal) {
        //its easy only
        //u dont have to use 2 pointers arrouch or kmp or lsp etc
        //just be a little smart

        if(s.size() != goal.size()) return false;
        return (s+s).find(goal) != string::npos;
    }
};