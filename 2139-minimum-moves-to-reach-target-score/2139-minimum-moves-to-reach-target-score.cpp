//ulta q = greedy
//dfs
class Solution {
public:
    void dfs(int target, int maxDoubles, int& moves){
        //bc
        if(target == 1){
            //got the ans, now return
            return;
        }
        if(maxDoubles == 0 && target > 1){
            moves = moves + (target - 1);
            target = 1;
            //got the ans, now return
            return;
        }
        else{ //maxDoubles > 0
            //check if odd, make it even
            if((target & 1) == 1){
                moves++;
                target--;
            }
            else{
                //its even, use maxDoubles
                target = target >> 1;
                moves++;
                maxDoubles--;
            }
        }

        dfs(target, maxDoubles, moves);
    }
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        //bc
        if(target == 1){
            return moves;
        }
        if(maxDoubles == 0 && target > 1){
            //-1 because we have to reach 1 and not 0
            moves = target - 1;
            target = 1;
            return moves;
        }
        dfs(target, maxDoubles, moves);
        return moves;
    }
};