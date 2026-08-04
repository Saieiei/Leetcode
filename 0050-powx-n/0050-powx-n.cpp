class Solution {
public:
    double recursion(double x, long long n){
        //bc
        if(n == 0){
            return 1.0;
        }
        //x * x^(n-1)

        //half the exponent
        long long halfExponent = n/2;
        double halfAns = recursion(x, halfExponent);
        double ans = halfAns * halfAns;

        //but what of the exponent is not even, then we have to simply mul 1 again
        if(n%2 != 0){
            ans = ans*x;
        }
        return ans;
    }
    double myPow(double x, int n) {
        //recursion2 - little optimized
        //divide teh process in 2
        //check if the exponenet is - then we have to reciprocal it
        //we have to convert it to long long because if u convert the highest - to +
        //then it will cause overflow, -2147483648 +2147483647
        long long exponent = n;
        if(exponent < 0){
            x = (1.0/x);
            exponent *= -1;
        }
        double ans = recursion(x, exponent);
        return ans;
    }
};