auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
};
//dfs
class Solution {
public:
    bool dfs(vector<int>& arr, int index, vector<bool>& isVisited){
        //if this index is safe or not
        if(index<0 || index>=arr.size()){
            return false;
        }
        //check if we have reached the target
        if(arr[index] == 0){
            return true;
        }
        //check if already visited
        if(isVisited[index] == true){
            return false;
        }

        //all safe now
        //1st mark it as visited
        isVisited[index] = true;

        //2 options to explore
        int rightIndex = index + arr[index];
        int leftIndex = index - arr[index];
        bool rightPath = dfs(arr, rightIndex, isVisited);
        bool leftPath = dfs(arr, leftIndex, isVisited);

        return (rightPath||leftPath);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> isVisited(n, false);
        bool ans = dfs(arr, start, isVisited);
        return ans;
    }
};