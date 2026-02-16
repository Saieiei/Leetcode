//simple dfs
class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<bool>& visited){
        //basecase
        if(start >= arr.size() || start <= -1 || visited[start]){
            return false;
        }
        // Target found
        if (arr[start] == 0) {
            return true;
        }
        //mark it as visited
        visited[start] = true;
        //2 options
        int leftDFS = dfs(arr, start-arr[start], visited);
        int rightDFS = dfs(arr, start+arr[start], visited);
        return (leftDFS || rightDFS);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }
};