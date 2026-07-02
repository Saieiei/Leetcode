class Solution {
public:
    string removeDuplicates(string s, int k) {
        //stacks
        //N, N
        stack<pair<char, int>> st; //char, freq
        //traverse through the string
        for(const char& ch: s){
            //check is it matched with the previous 1
            if(!st.empty() && st.top().first == ch){
                //increase the freq
                st.top().second++;

                //since freq has increased, check if we met the condition
                if(st.top().second == k){
                    //pop it
                    st.pop();
                }
            }
            else{
                //empty or not matching
                st.push({ch, 1});
            }
        }
        //make the string now
        string ans = "";
        //pop it 1 by 1 then reverse it
        while(!st.empty()){
            pair<char, int> topPair = st.top();
            st.pop();
            char ch = topPair.first;
            int freq = topPair.second;
            while(freq){
                ans += ch;
                freq--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};