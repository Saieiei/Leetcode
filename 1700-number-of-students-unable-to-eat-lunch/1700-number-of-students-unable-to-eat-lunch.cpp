class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        //1st we will check the number of sq and rou sadwiches that we have
        int sq=0,rou=0, total=0;
        for(int i=0;i<students.size();i++)
        {
            if(students[i]==1)
            {
                sq++;
            }
            else
            {
                rou++;
            }
        }
        total=students.size();
        //now we will see if every1 is getting what they want, if not return the number of remaining students
        for(int i=0;i<sandwiches.size();i++)
        {
            if(sandwiches[i]==1 )
            {
                if(sq>0)
                {
                    sq--;
                    total--;
                }
                else
                    return total;
            }
            else
            {
                if(rou>0)
                {
                    rou--;
                    total--;
                }
                else
                    return total;
            }
            
        }
        return 0;
    }
};