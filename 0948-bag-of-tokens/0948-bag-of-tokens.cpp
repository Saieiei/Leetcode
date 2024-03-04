class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int maxscore=0;
        sort(tokens.begin(), tokens.end());
        int i=0;
        int j=tokens.size()-1;
        while(i<=j)
        {
            if(power>=tokens[i]) //face up gaining 1 score to get highest power in the future (trade)
            {
                score++;
                maxscore=max(maxscore,score);
                power=power-tokens[i];
                i++;
            }
            else if(score>0)
            {
                score--;
                power=power+tokens[j];
                j--;
            }
            else
            {
                return maxscore;
            }

        }
        return maxscore;
    }
};