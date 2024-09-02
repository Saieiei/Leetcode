class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        //this is a easy problem only 
        //u can do this with %, which saves u many rounds

        //1st we will find out the total sum
        long long int totalSum = 0;
        for(int i=0; i<chalk.size(); i++)
        {
            totalSum += chalk[i];
        }

        //now after u have found out the total sum
        //we will reduce the number of rounds by %
        int rem = 0;
        rem = (int) k % totalSum;

        //now after we have reduced the rounds
        //we have to find which student will take the bait now
        for(int i=0; i<chalk.size(); i++)
        {
            if(chalk[i]>rem) return i;
            else rem = rem - chalk[i];
            //cout<<rem<<endl;
        }

        return -1;
    }
};