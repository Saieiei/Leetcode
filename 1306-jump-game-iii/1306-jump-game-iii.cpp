auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
};
//bfs
class Solution {
public:
    bool isSafe(int index, vector<int>& arr){
        if(index<0 || index>=arr.size()){
            return false;
        }
        return true;
    }
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        vector<bool> isVisited(arr.size(), false);
        q.push(start);
        //mark it visited
        isVisited[start] = true;

        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(arr[index] == 0){
                return true;
            }
            //explore the nbrs
            int leftIndex = index - arr[index];
            int rightIndex = index + arr[index];
            //check if safe
            if(isSafe(leftIndex, arr)){
                //check if visited
                if(!isVisited[leftIndex]){
                    q.push(leftIndex);
                    isVisited[leftIndex] = true;
                }
            }
            if(isSafe(rightIndex, arr)){
                //check if visited
                if(!isVisited[rightIndex]){
                    q.push(rightIndex);
                    isVisited[rightIndex] = true;
                }
            }
        }
        return false;
    }
};