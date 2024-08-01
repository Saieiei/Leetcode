class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string& s: details)
        {
            //int age  = stoi(s.substr(11, 2)); convertion from string to char makes it sloe
            int age = ((s[11]-'0')*10) + (s[12]-'0');
            if (age > 60) ans++;
        }
        return ans;
    }
};