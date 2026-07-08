class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        //this is more like a systematic way of approaching the q
        //1st we have to deal with space, then sign then digits then overflow
        int ans = 0;
        //by default its positive
        int sign = 1 ;
        int index = 0;
        //skip spaces
        while(index < n && s[index] == ' '){
            //skip it
            index++;
        }
        //next is the sign, and only 1 should be accepted
        if(index<n && (s[index] == '-' || s[index] == '+')){
            //sign presense has been confirmed
            //now use it
            sign = (s[index] == '-')? -1 : 1;
            index++;
        }
        //now go for the digits but also keep buffer overflow in mind
        //if the ans > 21,38,37,83,64,7 then 
        //return INT_MAX or INT_MIN depending on sign 
        while(index < n && isdigit(s[index])){
            int digit = s[index] - '0';
            //digit confirmed
            //check overflow
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7)){
                return (sign == -1)? INT_MIN : INT_MAX;
            }
            ans =  ans*10 + digit;
            index++;
        }
        return ans * sign;
    }
};