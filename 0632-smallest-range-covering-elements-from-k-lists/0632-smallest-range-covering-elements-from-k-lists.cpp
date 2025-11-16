class info{
    public:
    int val;
    int row;
    int col;
    info(int data, int rowIndex, int colIndex): val(data), row(rowIndex), col(colIndex) {}
};

class compare{
    public:
    bool operator()(info* a, info* b){
        return a->val > b->val;
    }
};


//to do this we will make use of min heap
//so the idea is that we will have a custome data structure (info) which will have the value, the col and the row 
//then we will push in the 1st element (info) of each vector into the pq
//keep track of the minAns and maxAns
//as we keep inserting and poping we need to keep track of maxi and mini
//then we will compare it with the diff of maxAns-minAns and maxi-mini, which ever is small we will update the minAns and maxAns
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<info*, vector<info*>, compare> pq;
        vector<int> ans;
        int minAns = INT_MAX;
        int maxAns = INT_MIN;

        //so the idea is that we will have a custome data structure (info) which will have the value, the col and the row 
        for(int i=0; i<nums.size(); i++){
            int elementToPush = nums[i][0];
            //before we push we will keep the track of minAns and maxAns as this could be the 1st ans 
            minAns = min(minAns, elementToPush);
            maxAns = max(maxAns, elementToPush);
            info* toPush = new info(elementToPush, i, 0);
            pq.push(toPush);
        }

        //this is for the comparison
        int mini = minAns;
        int maxi = maxAns;

        while(!pq.empty()){
            info* front = pq.top(); pq.pop();

            //now in min heap we can keep the track of the min element with the top (mini)
            int frontElement = front->val;
            mini = frontElement;

            //compare for now (maxAns, minAns)
            if(maxi-mini < maxAns-minAns){
                maxAns=maxi;
                minAns=mini;
            }

            //now we check if we can insert and check if that can be maxi
            if(front->col + 1 < nums[front->row].size()){
                info* temp = new info(nums[front->row][front->col + 1], front->row, front->col + 1);
                pq.push(temp);
                maxi = max(maxi, nums[front->row][front->col + 1]);
            }
            else  break; //we need eleemts from all the vectors, so we can just leave any1
        }
        ans.push_back(minAns);
        ans.push_back(maxAns);
        return ans;
        //return {minAns, maxAns;
    }
};