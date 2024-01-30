class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //we will use the concept of stacks
        //but we careful whne we do '-' and '/'
        //3
        //2  ->2-3 or 2/3
        //5

        stack<int>s;
        for(string x:tokens)
        {
            if(x=="+")
            {
                int a = s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int ans=a+b;
                s.push(ans);
            }
            else if(x=="*")
            {
                int a = s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int ans=a*b;
                s.push(ans);
            }
            else if(x=="-")
            {
                int a = s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int ans=b-a;
                s.push(ans);
            }
            else if(x=="/")
            {
                int a = s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int ans=b/a;
                s.push(ans);
            }
            else //incase just a number an dno symbol then simple put in stack
            {
                int a =stoi(x);
                s.push(a);
            }
        }
        return (s.top());
        
    }
};