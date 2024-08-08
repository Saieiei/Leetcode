class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        //int index = 1;
        //vector<vector<int>> ans;
        //while(1)
        //{
        //    //we will move col forward
        //    for(int i = 0; i<index; i++)
        //    {
        //        if(cStart<=cols-1 && cStart>=0) //dont add if it goes out of boundry
        //        {
        //            vector<int> vec;
        //            vec.push_back(rStart);
        //            vec.push_back(cStart);
        //            ans.push_back(vec);
        //        }
        //        cStart++;
        //    }
        //    if(ans.size() == rows*cols-1) break;
//
        //    //npw we will move row forward
        //    for(int i = 0; i<index; i++)
        //    {
        //        if(rStart<=rows-1 && rStart>=0) //dont add if it goes out of boundry
        //        {
        //            vector<int> vec;
        //            vec.push_back(rStart);
        //            vec.push_back(cStart);
        //            ans.push_back(vec);
        //        }
        //        rStart++;
        //    }
        //    if(ans.size() == rows*cols-1) break;
        //    
        //    //we have completed 1 interation forward, now we have to do the same but in reverse direction and increasing index By 1
        //    index++;
        //    //we will move col backward
        //    for(int i = index; i>0; i--)
        //    {
        //        if(cStart<=cols-1 && cStart>=0) //dont add if it goes out of bound
        //        {
        //            vector<int> vec;
        //            vec.push_back(rStart);
        //            vec.push_back(cStart);
        //            ans.push_back(vec);
        //        }
        //        cStart--;
        //    }
        //    if(ans.size() == rows*cols-1) break;
//
        //    //now we will move row backward
        //    for(int i = index; i>0; i--)
        //    {
        //        if(rStart<=rows-1 && rStart>=0) //dont add if it goes out of boundry
        //        {
        //            vector<int> vec;
        //            vec.push_back(rStart);
        //            vec.push_back(cStart);
        //            ans.push_back(vec);
        //        }
        //        rStart--;
        //    }
        //    if(ans.size() == rows*cols-1) break;
        //    index++;
        //}
        //return ans;

        vector<vector<int>> directions = {{0,1}, {1, 0}, {0, -1}, {-1, 0}}; //Left, Down, Right, Up
        int n = cols*rows;
        int index = 0;
        int step = 1;
        int count = 0; //this will be checked with the size (n)
        vector<vector<int>> ans;
        //push the 1st coordinates
        ans.push_back({rStart, cStart});
        count++;
        while(count < n)
        {
            for(int times=0; times<2; times++) //one time for row,  time for col
            {
                int drR = directions[index%4][0];
                int drC = directions[index%4][1];

                for(int i=0; i<step; i++) //this is meant for increasing the steps for per row and col
                {
                    rStart += drR;
                    cStart += drC;

                    if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols) //this is to make sure to add the coordinatantes thats only within the border
                    {
                        ans.push_back({rStart, cStart});
                        count++;
                    }
                }
                index++; //chnage the direction now
            }
            step++; //after the row and the col r added up,  imcrease the width by 1 and so on
        }
        return ans;
    }
};