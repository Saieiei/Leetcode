class Solution {
public:
//https://www.youtube.com/watch?v=k_rtL5iUp-A
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        //we will save the min element of every rown in 1 set
        //we will save the max element of every col in 1 set
        //then if the same element is there in voth the set, then that is the lucky number of the matrix
        //there cannot be any duplicates, so this method will work

        unordered_set<int> minRow;
        unordered_set<int> maxCol;
        int minEle = 0;
        int maxEle = 0;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> ans;

        //now lets do this
        //we will save the min element of every rown in 1 set
        for(int i=0; i<rowSize; i++)
        {
            //just take the 1st element of every row as minEle
            minEle = matrix[i][0];
            for(int j=0; j<colSize; j++)
            {
                minEle = min(minEle, matrix[i][j]);
            }
            //for that row, push the min element iin the set
            minRow.insert(minEle);
        }

        //now lets do this
        //we will save the max element of every col in 1 set, but instead of saving them and checking later, we can directly check if that element is present in the minRow or not
        for(int j=0; j<colSize; j++)
        {
            //just take the 1st element of every col as maxEle
            maxEle = matrix[0][j];
            for(int i=0; i<rowSize; i++)
            {
                maxEle = max(maxEle, matrix[i][j]);
            }
            ////for that col, push the max element iin the set
            //maxCol.insert(maxEle);
            if(minRow.count(maxEle)) ans.push_back(maxEle);
        }

        
        //now we will try to find the common element, if found push it in the ans vector
        //for(int ele: minRow) if(maxCol.count(ele)) ans.push_back(ele);    
        ////for(int i=0; i<rowSize; i++)
        ////{
        ////    for(int j=0; j<colSize; j++)
        ////    {
        ////        if(minRow.count(matrix[i][j]) && maxCol.count(matrix[i][j])) ans.push_back(matrix[i][j]);
        ////    }
        ////}
        return ans;
    }
};