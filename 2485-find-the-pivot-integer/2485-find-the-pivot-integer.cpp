//https://www.youtube.com/watch?v=2JNe1QZI7KE
class Solution {
public:
    int pivotInteger(int n) {
        int sum = ((n * (n + 1)) / 2), sumLeft = 0;

        for (int i = 0; i <= n; i++) {
            sumLeft += i;
            int sumRight=sum-sumLeft+i;
            if (sumLeft==sumRight) {
                return i;
            }
        }

        return -1;
    }
};