//we will be doing it using recustion 1st and then DP(tabulation) + space opti
class Solution {
public:

    int recursionFibTabulationSpace(int n){
        //instead of basecase 
        if(n==0 || n==1) return n;
        int curr=0, prev1=1, prev2=0;

        //bottom up approach
        for(int i=2; i<=n; i++){
            curr = prev2 + prev1;

            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }

    int fib(int n) {
        //for DP
        return recursionFibTabulationSpace(n);
    }
};