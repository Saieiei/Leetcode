//simple bfs
class Solution {
public:
    bool bfs(vector<int>& arr, int start, vector<bool>& visited, queue<int>& q){
        //keep doing until q is empty
        while(!q.empty()){
            //mark it as visited
            int frontEle = q.front();
            q.pop();
            visited[frontEle] = true;
            //check if 0
            if(arr[frontEle] == 0){
                return true;
            }
            //push the rest
            int leftBFS = frontEle-arr[frontEle];
            int rightBFS = frontEle+arr[frontEle];
            if(leftBFS>=0 && !visited[leftBFS]){
                q.push(leftBFS);
            }
            if(rightBFS<arr.size() && !visited[rightBFS]){
                q.push(rightBFS);
            }
        }
        //not found
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        queue<int> q;
        q.push(start);
        return bfs(arr, start, visited, q);
    }
};