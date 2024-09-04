class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //it is simple only
        //we will 1st set up direction, make sure u see it in rows and colum perspective and not x, y points
        //the directions will be in this order only N, E, S, W
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //xy
        //this will be used as an index to access the direction vector
        int dir = 0;
        //we will now do the innitial stuff
        int x = 0;
        int y = 0;
        //this we will use to check if the next point is blocked or not
        int next_x = 0;
        int next_y = 0;
        //this will help us keep the track of the final ans
        int max_squared_index = 0;
        int squared_index = 0;
        //we will also store the obstacle in a set for a quick loop up set.find(__)
        //u can also check with a simple if else condition too
        set<pair<int, int>> obstacle_coor;
        for(auto obsCoor: obstacles)
        {
            obstacle_coor.insert({obsCoor[0], obsCoor[1]});
        }

        //ok now lets begin processing the commands
        for(int command: commands)
        {
            if(command == -1) //to go right
            {
                dir = (dir + 1) % 4;
            }
            else if (command == -2) //to go left
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                for(int i=0; i<command; i++)
                {
                    next_x = x + directions[dir].first;
                    next_y = y + directions[dir].second;
                    //now we will check if there is a obstacle or not
                    if(obstacle_coor.find({next_x, next_y}) != obstacle_coor.end()) // obstacle found, break the loop
                    {
                        break;
                    }
                    else // did not find the obstacle, move forward
                    {
                        x = next_x;
                        y = next_y;
                        squared_index = x*x + y*y;
                        max_squared_index = max(max_squared_index, squared_index);
                    }
                }
            }
        }
        return max_squared_index;
    }
};