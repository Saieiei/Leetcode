class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    // Step 1: Create a sorted copy of the original array
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    // Step 2: Use a map to assign ranks to each unique element
    map<int, int> rankMap;
    int rank = 1;
    
    // Assign ranks to the sorted elements, ensuring unique elements get unique ranks
    for (int i=0; i<sortedArr.size();  i++) {
        if (rankMap.find(sortedArr[i]) == rankMap.end()) {  // Only assign rank if not already assigned
            rankMap[sortedArr[i]] = rank;
            rank++;
        }
    }
    
    // Step 3: Replace each element in the original array with its rank
    vector<int> result;
    for (int num : arr) {
        result.push_back(rankMap[num]);
    }
    
    return result;
}
};