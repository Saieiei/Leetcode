auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
};
//dfs
class Solution {
public:
    void dfs(vector<int>& arr, int index, vector<bool>& isVisited, bool& ans){
        //if this index is safe or not
        if(index<0 || index>=arr.size()){
            return;
        }
        //check if we have reached the target
        if(arr[index] == 0){
            ans = true;
            return;
        }
        //check if already visited
        if(isVisited[index] == true){
            return;
        }

        //all safe now
        //1st mark it as visited
        isVisited[index] = true;

        //2 options to explore
        int rightIndex = index + arr[index];
        int leftIndex = index - arr[index];
        dfs(arr, rightIndex, isVisited, ans);
        dfs(arr, leftIndex, isVisited, ans);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> isVisited(n, false);
        bool ans = false;
        dfs(arr, start, isVisited, ans);
        return ans;
    }
};