class Solution {
public:
//https://www.youtube.com/watch?v=ZGFKR1EXvnU
//its eay only 
//2 pointers
    string compressedString(string word) {
        string comp = "";
        int cnt = 1; char ch = word[0];
        int n = word.size();
        for(int i=1;i<n;i++){
            if(word[i] == ch && cnt < 9)cnt++;
            else{ //resetter
                comp.push_back(cnt+'0');
                comp.push_back(ch);
                ch = word[i];
                cnt = 1; //always 1 because it is the 1st element, regardless of matching or not
            }
        }
        comp.push_back(cnt+'0');
        comp.push_back(ch);
        return comp;
    }
};