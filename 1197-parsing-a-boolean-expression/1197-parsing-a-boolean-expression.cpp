class Solution {
    //https://www.youtube.com/watch?v=7MODP3hx3yw
public:
//this is not a hard q, its medium level only and little lengthy
//we have to use stacks, FILO  or LIFO
    //helper function
    char evaluator(vector<char>& charV, char& op)
    {
        //there r 3 things to do in here (&, |, !)
        if(op == '&')
        {
            //if there is 1 'f', then it will return 'f', else return 't'
            if(find(charV.begin(), charV.end(), 'f') != charV.end())
            {
                return 'f';
            }
            else return 't';
        }
        else if(op == '|')
        {
            //if there is 1't', then it will return 't', else return 'f'
            if(find(charV.begin(), charV.end(), 't') != charV.end())
            {
                return 't';
            }
            else return 'f';
        }
        else //op == !, there can be only 1 element in the charV
        {
            return charV[0]=='f'?'t':'f';
        }
    }
    bool parseBoolExpr(string expression) {
        //1st we will simply put all the elements in the stack
        //we will ignore ','
        stack<int> st;
        for(char ch: expression)
        {
            if(ch!=')' || st.size() == 0) //then simply push it in the stack
            {
                if(ch != ',')  st.push(ch); //ignore ','
            }
            else // ch == ')'
            {
                //now we will start popping until we reach the ) and also pop 1 element after it 'operator'
                vector<char> charsV;
                while(st.top() != '(') //keep pushing it in the vector
                {
                    charsV.push_back(st.top());
                    st.pop();
                }
                //now we have a (, hence pop that
                st.pop();
                //now we need to store the operator
                char op = st.top();
                //pop that as well
                st.pop();
                //now we evaluete the expression that we have, and push it back into the stack
                st.push(evaluator(charsV, op));
            }
        }
        //now, we will return the last ele in the stack
        if(st.top() == 't') return true;
        else return false;
    }
    //proud of u brother
};