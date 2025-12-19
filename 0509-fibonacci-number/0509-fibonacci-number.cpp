//we will be doing it using recustion 1st
class Solution {
public:

    int recursionFib(int n){
        //basecase
        if(n==0 || n==1) return n;

        //recursion
        return recursionFib(n-1) + recursionFib(n-2);
    }

    int fib(int n) {
        int ans = recursionFib(n);
        return ans;
    }
};