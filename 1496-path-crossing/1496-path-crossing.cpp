class Solution {
public:
    bool isPathCrossing(string path) {
        //string s;
        //s = "NESW";
        int x = 0, y = 0;
        pair<int, int> currentPos = make_pair(x, y);
        list<pair<int, int>> visitedPositions;
        visitedPositions.push_back(currentPos);
        int flag = 0;

        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'N') {
                y++;
            } else if (path[i] == 'S') {
                y--;
            } else if (path[i] == 'E') {
                x++;
            } else if (path[i] == 'W') {
                x--;
            }

            currentPos = make_pair(x, y);

            auto it = find(visitedPositions.begin(), visitedPositions.end(), currentPos);
            if (it != visitedPositions.end()) {
                flag = 1;
                break;
            } else {
                visitedPositions.push_back(currentPos);
            }
        }

        if (flag == 1) {
            return 1;
        } else {
            return 0;
        }

        return 0;
    }
};