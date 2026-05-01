//kruskals algo
class Solution {
public:
    int findParent(vector<int>& parents, int node){
        //check if same
        if(parents[node] == node){
            return node;
        }
        //path compression
        return parents[node] = findParent(parents, parents[node]);
    }
    void findUnion(vector<int>& parents, vector<int>& ranks, int currentRowID, int alreadyRowID){
        int parentCurrentRowID = findParent(parents, currentRowID);
        int parentAlreadyRowID = findParent(parents, alreadyRowID);

        //start the process
        int rankCurrentRowID = ranks[parentCurrentRowID];
        int rankAlreadyRowID = ranks[parentAlreadyRowID];
        if(rankCurrentRowID >= rankAlreadyRowID){
            ranks[parentCurrentRowID]++;
            parents[parentAlreadyRowID] = parentCurrentRowID;
        }
        else{
            ranks[parentAlreadyRowID]++;
            parents[parentCurrentRowID] = parentAlreadyRowID;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //1st create mp
        unordered_map<string, int> mp;
        int n = accounts.size();
        vector<int> ranks(n, 0);
        vector<int> parents(n);
        for(int i=0; i<n; i++){
            parents[i] = i;
        }
        //process givenData -> mp
        int rowID = 0;
        for(vector<string> account: accounts){
            int colSize = account.size();
            //we dont require the title here -> account[0]
            for(int j=1; j<colSize; j++){
                //check if the characteristics is already there in the mp
                string characteristic = accounts[rowID][j];
                auto it = mp.find(characteristic);
                if(it == mp.end()){
                    //did not find it in the mp
                    //push it in the mp
                    mp[characteristic] = rowID;
                }
                else{
                    //already there in the mp
                    //do findUnion
                    int currentRowID = rowID;
                    int alreadyRowID = it->second;
                    findUnion(parents, ranks, currentRowID, alreadyRowID);
                }
            }
            rowID++;
        }

        //create the preAns
        unordered_map<int, set<string>> preAns;
        //traverse through the mp
        for(pair<const string, int> data: mp){
            string characteristic = data.first;
            int rowID = data.second;
            //forgot this step
            int parentRowID = findParent(parents, rowID);
            preAns[parentRowID].insert(characteristic);
        }

        //create ans
        vector<vector<string>> ans;
        //traverse through preAns
        for(pair<const int, set<string>> data: preAns){
            int parentRowID = data.first;
            set<string> characteristics = data.second;
            string title = accounts[parentRowID][0];
            vector<string> temp;
            temp.push_back(title);
            for(string characteristic: characteristics){
                temp.push_back(characteristic);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};