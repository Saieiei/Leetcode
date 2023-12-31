class Solution {
public:
    int myAtoi(string s) {
       
        int i=0; //iterate through each charcter
        int num=0; //final answer builder
        int sign=1; //this will tell us if the number should be + || -
        //lets omit white spaces 1st
        while(i<s.size() && s[i]==' ') //found the space
        {
            i++;
        }
        //now lets check if the number is + || -
        while(i<s.size() && (s[i]=='+' || s[i]=='-')) //foud the sign
        {
            sign=(s[i]=='+')?1:-1;
            i++;
            break;
        }
        //now if we get numbers then we will add accordingly but we also have to check [-2^(31), 2^(31) - 1] condition
        //we should know that INT_MAX=2^(31)-1=2147483647 and INT_MIN=-2^31=-2147483648, so we will have to clamp it to these values if tthey are exceeding
        while(i<s.size() && isdigit(s[i]))
        {
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7')) //checking for [-2^(31), 2^(31) - 1] condition
                                                              //num>214748365, num>214748364 +8, num>214748364 +9
            {
                return (sign==-1)?INT_MIN:INT_MAX;
            }
            num=num*10+(s[i]-'0');
            i++;

        }
        return (sign==-1)?-num:num;

    }
};