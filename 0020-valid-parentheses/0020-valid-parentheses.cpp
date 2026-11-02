class Solution {
public:
    bool isValid(string s) {
        //push the open brackets inside stack
        //if the starting is not a opening bracket then return false
        //if its a closing bracket then check if the top is a closing braket of teh same kind
        //if not resturn false
        //if it comes outside of the loop (traversing the string) then check if the the stack is empty
        //if so return true else false
        stack<char> stk;
        for(char ch: s){
            //simply push in the opening brackets and we will pop them with the closing brackets
            if(ch == '(' || ch == '{' || ch == '['){
                stk.push(ch);
            }
            else{
                //closing brackets now
                //if the stack is empty then return false, we cannot solve them no matter what
                if(stk.empty()){
                    return false;
                }
                else if(ch == ')' && stk.top() == '('){
                    stk.pop();
                }
                else if(ch == '}' && stk.top() == '{'){
                    stk.pop();
                }
                else if(ch == ']' && stk.top() == '['){
                    stk.pop();
                }
                //they dont match so return false
                else{
                    return false;
                }
            }
        }
        //exhausted the string s
        return (stk.empty()) ? true : false;
    }
};