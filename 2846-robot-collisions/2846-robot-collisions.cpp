class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<pair<int, int>> robots;
    for (int i = 0; i < n; ++i) {
        robots.push_back({positions[i], i});
    }
    sort(robots.begin(), robots.end());
    
    stack<int> stk; // stack to keep track of indices of robots moving to the right
    vector<bool> survived(n, true);
    
    for (auto& robot : robots) {
        int pos = robot.first;
        int idx = robot.second;
        
        if (directions[idx] == 'R') {
            stk.push(idx);
        } else {
            while (!stk.empty() && healths[idx] > 0) {
                int rightIdx = stk.top();
                
                if (healths[rightIdx] < healths[idx]) {
                    healths[idx]--;
                    survived[rightIdx] = false;
                    stk.pop();
                } else if (healths[rightIdx] > healths[idx]) {
                    healths[rightIdx]--;
                    survived[idx] = false;
                    break;
                } else {
                    survived[idx] = survived[rightIdx] = false;
                    stk.pop();
                    break;
                }
            }
        }
    }
    
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (survived[i]) {
            result.push_back(healths[i]);
        }
    }
    
    return result;
}
};