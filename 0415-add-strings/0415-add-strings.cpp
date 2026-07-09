class Solution {
public:
    string addStrings(string num1, string num2) {
        //this is simple school grade problem
        //we will start from right side and move to left side
        //wee will keep travelling until all of them have no digits 
        //in the end we have to reverse it as well
        string ans = "";
        int index1 = num1.size()-1;
        int index2 = num2.size()-1;
        int carry = 0;
        while(index1>=0 || index2>=0 || carry>0){
            //now we dont know if any of these have the digit
            //if they dont, then we have to mark them as 0
            int digit1 = 0;
            int digit2 = 0;
            if(index1<0){
                digit1 = 0;
            }
            else{
                digit1 = num1[index1] - '0';
                index1--;
            }
            if(index2<0){
                digit2 = 0;
            }
            else{
                digit2 = num2[index2] - '0';
                index2--;
            }
            int sum = digit1 + digit2 + carry;
            //the remainder will go in the ans
            //the rest will go as carry
            char rem = sum%10 + '0';
            ans += rem;
            carry = sum/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};