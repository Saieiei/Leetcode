class Solution 
{
public:
    bool isPathCrossing(string path) 
    {
        int a = 0, b = 0;;
        set<vector<int>> x;
        x.insert({0, 0});
        for (char i: path)
        {
            if (i == 'N')
            {
                b++;
            } 
            else if (i == 'E')
            {
                a++;
            } 
            else if (i == 'S')
            {
                b--;
            }
            else 
            {
                a--;
            }
            if (x.find({a, b}) != x.end())
            {
                return true;
            }
            x.insert({a, b});
        }
        return false;
    }
};