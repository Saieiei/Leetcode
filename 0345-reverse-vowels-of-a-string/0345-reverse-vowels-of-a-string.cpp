class Solution {
public:
bool fun(char c){
    c=tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        string st;


        while(start<end){
            if(!fun(s[start])) //false false is true
            {
                start++;
                continue;
                
                  }
           if(!fun(s[end])) //false false is true
            {  
                end--;
                continue;
                
                
            }
           else{ //both vowels
            
                swap(s[start],s[end]);
                start++;
                end--;
           }

            
        }


return s;
        
        
    }
};