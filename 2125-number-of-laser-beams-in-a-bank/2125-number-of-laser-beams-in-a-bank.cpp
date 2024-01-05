class Solution {
public:

    int total_laser_present_in_row(string& str)
    {
        int total_lasers=0;
        for(int i=0;i<str.size();i++)
        {
            if (str[i] == '1')
            {
                total_lasers++;
            }
        }
        return total_lasers;
        
    }


    int numberOfBeams(vector<string>& bank) {
        //1st we will calculate how many lazers rr present in each row
            //we will take the 1st string and take each char and see if its 1, if so add it to rows and return the value
        //2nd we will use 2 pointers approach i at 0, and j at i+1; 
            //we will simply multiply the the values (i and j) if j is 0 we will move j ahead
    
        vector<int>rows;
        for(string row:bank) 
        {
            rows.push_back(total_laser_present_in_row(row));
        }// after u have found the no of lasers in each rows its time to calculate the no of beams

        int ans=0;
        for(int i=0;i<rows.size();i++)
        {
            int j=i+1;
            while(j<rows.size())
            {
                ans=ans+rows[i]*rows[j];
                if(rows[j]==0)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;


    }

};