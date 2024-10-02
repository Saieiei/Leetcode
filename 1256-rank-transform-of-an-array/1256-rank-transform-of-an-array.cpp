class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    //// Step 1: Create a sorted copy of the original array
    //vector<int> sortedArr = arr;
    //sort(sortedArr.begin(), sortedArr.end());
    //
    //// Step 2: Use a map to assign ranks to each unique element
    //unordered_map<int, int> rankMap;
    //int rank = 1;
    //
    //// Assign ranks to the sorted elements, ensuring unique elements get unique ranks
    //for (int i=0; i<sortedArr.size();  i++) {
    //    if (rankMap.find(sortedArr[i]) == rankMap.end()) {  // Only assign rank if not already assigned
    //        rankMap[sortedArr[i]] = rank;
    //        rank++;
    //    }
    //}
    //
    //// Step 3: Replace each element in the original array with its rank
    //vector<int> result;
    //for (int i=0; i<arr.size(); i++) {
    //    result.push_back(rankMap[arr[i]]);
    //}
    //
    //return result;

    //it is even faster if u use a vector pair
    vector<pair<int, int>> indexVecPair(arr.size());
    vector<int> result(arr.size());

    //store the index of each of each element (key, value)
    for(int i=0; i<arr.size(); i++)
    {
        indexVecPair[i] = {arr[i], i};
    }

    //sort the indexVecPair on the basis of the key
    sort(indexVecPair.begin(), indexVecPair.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first<b.first;
    });

    int rank = 0;
    for(int i=0; i<arr.size(); i++)
    {
        int key = indexVecPair[i].first;
        int value = indexVecPair[i].second;
        if(i == 0 || indexVecPair[i-1].first != key)
        {
            rank++;
        }
        result[value] = rank;
    }
    return result;
}
};