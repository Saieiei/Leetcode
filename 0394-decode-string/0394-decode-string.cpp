class Solution {
public:
    string decodeString(string s) {
        //its not easy, ik u will think of stacks, but how will u implement it is the real q
        //so the idea is that u will pass everythign in the stack as the char and only start compuatation if the char is ]
        //for the number, in the end, for example , 10[x]
            // in the stack we will have 1,0 
                //so all that have to be taken into consideration and finally do stoi(number)
        //do the computation 2[a] = aa, and push it back into the stack
        //dw about the reverse and shit (2[ab]), for now just add is like, temp = temp + st.top()
        // we will do reverse in the end to return the final ans

        stack<string>st;

        //iterate through the string
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            //push everythign except ']'
            if(ch != ']') //just push
            {
                //convert char to string
                string temp(1, ch);
                st.push(temp);

            }
            else //ch == ']'
            {
                string temp = "";
                //1st we r trying to get the alpahabets
                while(!st.empty() && !isdigit(st.top()[0])){ // this is because isdigit(char) expects a char and not string (st.top()[0])
                    string top = st.top();
                    top == "[" ? top="" : top;
                    temp = temp + top;
                    st.pop();
                }

                //now we will try to get the numbers
                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){ // this is because isdigit(char) expects a char and not string (st.top()[0])
                    numericTimes = numericTimes + st.top();
                    st.pop();
                }
                //we need to reverse it to get the correct number
                reverse(numericTimes.begin(), numericTimes.end());

                // now we will do the computation where 3[a] = aaa
                int n = stoi(numericTimes);
                string currentDecode = "";
                while(n--){
                    currentDecode = currentDecode + temp;
                }
                //push the decoded string back to the stack
                st.push(currentDecode);
            }
        }
        //now we have the ans in the stack
        //we just have to extract it all and reverse it to get it in the correct order

        //extract all
        string ans = "";
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        //get it in the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};