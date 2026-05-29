auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        //optimal sol N
        //keep 1 pointer to the start and another to the end
        //this will help us maximise width, which is in our hands
        //to get the maximum area we also need maximum ht
        //we can to convert the 1 with th least ht to a greater ht
        //it can be done by moving the pointer inside
        //and hoping to land a bigger ht, hence bigger area
        int leftPointer = 0;
        int rightPointer = n-1;
        int maxArea = 0;
        while(leftPointer <= rightPointer){
            int width = rightPointer - leftPointer;
            int height = min(heights[leftPointer], heights[rightPointer]);
            int area = width * height;
            maxArea = max(maxArea, area);
            //now move the pointers
            if(heights[leftPointer] < heights[rightPointer]){
                //move left pointer
                leftPointer++;
            }
            else{
                //rightPointer bigger or same, move it
                rightPointer--;
            }
        }
        return maxArea;
    }
};