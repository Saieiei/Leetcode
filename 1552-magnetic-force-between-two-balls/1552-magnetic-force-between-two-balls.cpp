class Solution {
public:
    bool helper(int mid, vector<int>& position, int m)
    {
        int countOfBallPlaced = 1;
        int lastPosition = position[0];
        
        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - lastPosition >= mid)
            {
                countOfBallPlaced++;
                lastPosition = position[i];
                if (countOfBallPlaced >= m) 
                {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 1;
        int end = position.back() - position.front();
        int ans = -1;

        // Binary search
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(helper(mid, position, m))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};
