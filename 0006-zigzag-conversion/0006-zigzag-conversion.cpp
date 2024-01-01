//week5_ass_10
class Solution {
public:
    string convert(string s, int numRows) {
        //the main idea ios to go with the direction
        //1st is to go in a downward direction-> lets say that is denoted by 1
            //after we reach the last row(numRows-1) and input the character we will also be incrementing the row
            //but since the row has exceeded the numRows, we will have to reset the row to 1 before the last row, i.e (numRows-1)
        //make sure the direction is going upwards now so lets denote that by -1
            //after we reach the 1st row again and input the character the row will be decrased by 1 so it will be in negative, so stop
        //change the direction and so on it goes
        //when does it stop?, it stops when the index iterating through each chacter of s comes to an end

        vector<string>ans(numRows); //setting up the vector size
        if(numRows==1) return s; //this is a special case
        int i=0; //index
        int direction=1; //1st we will go downwards
        int row=0;//this will tell us new strings, diff row, diff string
        while(i<s.size())
        {
            if(direction==1)//going downwards
            {
                while(row<numRows && i<s.size())//this will keep on going down
                {
                    ans[row].push_back(s[i]);
                    row++;i++;
                }//after we have reached the bottom we have to chnage the direction(upwards)
                direction=-1;
                row=numRows-2;
            }
            else //direction==-1 going upwards
            {
                while(row>=0 && i<s.size())//this will keep going upwatds
                {
                    ans[row].push_back(s[i]);
                    row--;i++;
                }//after we have reached the top we have to chnage the direction(downwards)
                direction=1;
                row=1;
            }
        }
        //now lets print the ans
        string ansString="";
        for(int i=0;i<numRows;i++)
        {
            ansString=ansString+ans[i];
        }
        return ansString;
        
    }
};