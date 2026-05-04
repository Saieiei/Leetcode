//ulta q
//bfs
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        //bc
        if(maxDoubles == 0){
            //-1 because the traget should reach 1 and not 0
            moves = target - 1;
            //now my target becomes 1
            target = 1;
            return moves;
        }
        if(target == 1){
            return moves;
        }
        while(true){
            if(maxDoubles == 0 && target > 1){
                //-1 because the traget should reach 1 and not 0
                moves = moves + (target - 1);
                //now my target becomes 1
                target = 1;
                return moves;
            }
            else{
                //if target is odd, then make it even
                if(target & 1){
                    moves++;
                    target --;
                }
                else{
                    //if even then use maxDoubles
                    maxDoubles--;
                    moves++;
                    target = target >> 1;
                    if(target == 1){
                        return moves;
                    }
                }
            }
        }
    }
};