//ulta
//recursion - optimised - DFS
class Solution {
public:
    int dfs(int target, int maxDoubles){
        if(target == 1){
            int moves = 0;
            return moves;
        }
        if(maxDoubles == 0){
            int moves = target - 1;
            target = 1;
            return moves; 
        }

        //explore 2 options
        //check if odd
        if(target & 1){
            return 1 + dfs(target-1, maxDoubles);
        }
        else{
            //target is even
            return 1 + dfs(target>>1, maxDoubles-1);
        }
    }
    int minMoves(int target, int maxDoubles) {
        //bc
        int moves = 0;
        if(target == 1){
            return moves;
        }
        if(maxDoubles == 0){
            //because it starts from 1 and not 0
            moves = target - 1;
            target = 1;
            return moves;
        }
        //no need of moves here
        return dfs(target, maxDoubles);
    }
};