class Solution {
public:
    int passThePillow(int n, int time) {
        int index = 1;
        while(time)
        {
            while(index < n && time)
            {
                index++;
                time--;
            }
            while(index > 1 && time)
            {
                index--;
                time--;
            }
        }
        return index;
    }
};