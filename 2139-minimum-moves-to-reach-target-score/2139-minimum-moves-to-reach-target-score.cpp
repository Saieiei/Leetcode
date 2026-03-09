//M2
//this is basic recursion + greedy optimal choices
//1st we will try out with direct ans
//trying form target to 0
class Solution {
public:
    int solve(int target, int maxDoubles){
        //basecase
        if(target == 1){
            return 0; //no operation was done here
        }
        if(maxDoubles == 0){ 
            return target - 1; //these many operations r needed
        }
        //DFS
        if(maxDoubles > 0 && target%2 == 1){
            return 1 + solve(target-1, maxDoubles);
        }
        //if(maxDoubles > 0){
            return 1 + solve(target/2, maxDoubles-1);
        //}
    }
    int minMoves(int target, int maxDoubles) {
        return solve(target, maxDoubles);
    }
};