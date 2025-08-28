class Solution {
public:
    string simplifyPath(string path) {
        //this aint easy it may seem simple but it is not
        //so 1st we have to capture each directory
        //and then compare it with // or .. or .
            //if something else then simply push it into the stack
        
        string token;
        stack<string> dir;

        //iterate through the path
        for(int i=0; i<path.size(); i++)
        {
            char ch = path[i];
            if(path[i] == '/') // this means it cound be the begining of the token, or the end of the token, which we should insert
            {   //we will check on the token that we formed
                if(!token.empty())
                {
                    if(token == ".") 
                    {
                        //ignore, we dont have to do anything
                    }
                    else if(token == "..")
                    {
                        //we need to pop
                        if(!dir.empty()) dir.pop();
                    }
                    else //its a valid directory, push it into the stack
                    {
                        dir.push(token);
                    }
                    //since we r done with the tokens from the operations above, we cam cleasr it of
                    token.clear();

                    //if its '/', ignore off
                    //forget about '//'
                }
                
            }
            else // the char is not a /, then its part of the directory only
            {
                //its a part of the token
                token.push_back(ch);
            }
        }

        //but for this case "/a/.//.." as u can see the last part will not be processed because we dont hit the '/' condition
        if(!token.empty())
        {
            if(token == ".") 
            {
                //ignore, we dont have to do anything
            }
            else if(token == "..")
            {
                //we need to pop
                if(!dir.empty()) dir.pop();
            }
            else //its a valid directory, push it into the stack
            {
                dir.push(token);
            }
            //since we r done with the tokens from the operations above, we cam cleasr it of
            token.clear();

            //if its '/', ignore off
            //forget about '//'
        }

        // Build canonical path
        if (dir.empty()) return "/";

        //now lets make the correct path
        vector<string> parts;
        parts.reserve(dir.size());
        while (!dir.empty()) { parts.push_back(dir.top()); dir.pop(); }

        string res;
        for (int i = (int)parts.size() - 1; i >= 0; --i) {
            res.push_back('/');
            res += parts[i];
        }
        return res;
    }
}; 