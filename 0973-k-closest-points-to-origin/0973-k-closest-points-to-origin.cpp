class compare{
    public:
    bool operator()(vector<int>& point1, vector<int>& point2){
        int dist1 = point1[0]*point1[0] + point1[1]*point1[1];
        int dist2 = point2[0]*point2[0] + point2[1]*point2[1];
        return dist1<dist2;
    }
};

//we will be using MaxHeap and pop the ones thats kargest (top)
//we will keep on poping if it goes beyound the size k
//so yes we will be using a custome operator
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <vector<int>, vector<vector<int>>, compare>pq;  
        vector<vector<int>> ans;

        //push the points in the heap
        for(int i=0; i<points.size(); i++){
            pq.push(points[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            vector<int> ToPush = pq.top();
            pq.pop();
            ans.push_back(ToPush);
        }

        return ans;
    }
};