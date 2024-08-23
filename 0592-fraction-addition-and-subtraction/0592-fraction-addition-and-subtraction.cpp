class Solution {
public:
    int GCD(int num, int den)
    {
        return den == 0 ? num : GCD(den, num%den);
    }
    string fractionAddition(string expression) {
        //this 1 is simply bruteforce only
        //nothing can be done about this
        //its just string manupulation and finding GCD for the last part

        int num = 0;
        int den = 1;
        int n = expression.length();
        int i = 0;

        while(i<n)
        {
            int curNum = 0;
            int curDen = 0;
            bool isNega = false;
            //1st find the sign
            if(expression[i] == '-' || expression[i] == '+')
            {
                if(expression[i] == '-') isNega = true;
                i++;
            }

            //now we will find the numerator part
            int start = i;
            while(isdigit(expression[i])) i++;
            curNum = stoi(expression.substr(start, (i-start)));
            if(isNega) curNum = curNum*-1;

            i++; // as it is /(division)

            //now we will find the denomenator part
            start = i;
            while(i<n && isdigit(expression[i])) i++;
            curDen = stoi(expression.substr(start, (i-start)));

            //ok now so we have 1 pair, we will do the adding of fractions
            num = num * curDen + curNum * den;
            den = den * curDen;
            //and soo on the loop goes on 
        }

        //now we have the final value but we have to simplyfi it
        //this can be done by finding out its GCD value
        //and then dividing both the num and the den, with the GCD term

        int gcd = abs(GCD(num, den));
        num = num/gcd;
        den = den/gcd;

        string ans = to_string(num) + "/" + to_string(den);
        return ans;
    }
};