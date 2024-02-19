class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false; //0->2^
        while(n%2==0)
        {
            n=n/2;
        }
        if(n==1) return true;
        return false;
    }
};