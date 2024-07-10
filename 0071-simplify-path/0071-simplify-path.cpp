class Solution {
public:
    string simplifyPath(string path) {
        //we will solve this using stack

        stack<string> st;
        //now we will try to find the 1st directory
        int i = 0;
        while(i < path.size())
        {
            int start = i;
            int end = i + 1;
            // now we will keep on moving th eend pointer untill we get a / ,we will not take 2nd / in the directory
            while(end < path.size() && path[end] != '/') end++;
            //now since we have got a directory from the path, we will extract it and put it into a temp string
            string foundDirectory = "";
            foundDirectory = path.substr(start, end - start); //dont do path.substr(start, end); as it will not be able to find the next next directories
            
            //update ur next start
            i = end;
            //now we have to check if this directory is meant to go in the stack, or pop the elements from teh stack or do nothing
            if(foundDirectory == "/" || foundDirectory == "/.") continue; //we have to do nothing, waste it is
            else if(foundDirectory == "/.." && !st.empty()) st.pop(); //remove 1 directory from the stack
            else if(foundDirectory == "/.." && st.empty()) continue; //do nothing
            else st.push(foundDirectory);  //valid directory then push it in the stack
        }

        //if we have come till the end and we r at the root then we have to display /
        string ans= "";
        ans = st.empty() ? "/" : "";

        //now we have to reverse the stack
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};