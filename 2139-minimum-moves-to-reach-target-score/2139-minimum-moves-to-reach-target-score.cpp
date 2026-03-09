//M3
//no need recursion, just greedy
//1st we will try out with moves
//trying form target to 1
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while(target > 1){
            if(maxDoubles == 0){
                int remaining = target - 1;
                moves = moves + remaining;
                target = 1;
                break;
            }
            else{ //maxDoubles>0 
                if(target & 1){//if odd
                    moves++;
                    target--;
                }
                else{//maxDoubles>0 && even
                    moves++;
                    target = target >> 1; //divide by 2
                    maxDoubles--;
                }
            }
        }
        return moves;
    }
};