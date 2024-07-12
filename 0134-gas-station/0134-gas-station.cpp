class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //this q is like, u will have to reach few checkpoints, by which u will be awarderd(gas) to go even further
        //so, such qs can be solved this deficit method
            //so, basically u will start with a index as a starting point
            //u wil traverse the entier checkpoints,
            //in cases ur not able to meet the checkpoint (-balance)
                //then u will have to find, by how much i have missed the checkpoint, that is ur deficit
                //keep adding ur deficit, until u find an index, where ur balance - deficit > 0
        
        int start = 0;
        int balance = 0;
        int deficit = 0;
        for(int i=0; i<gas.size(); i++)
        {
            balance = balance + gas[i] - cost[i];

            if(balance < 0)
            {
                deficit = deficit + abs(balance);
                balance = 0;
                start = i+1;
            }
        }
        if(balance - deficit >=0) return start; //found the ans
        else return -1; //coudnt find
        //by tthis method, u dont have worry about circular cases, etc

    }
};