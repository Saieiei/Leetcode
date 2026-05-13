//kruskals algo
class Solution {
public:
    int parentFind(int node, vector<int>& parents){
        //check if self parents
        if(parents[node] == node){
            return node;
        }
        //path compression
        return parents[node] = parentFind(parents[node], parents);
    }
    void unionFind(int node1, int node2, vector<int>& parents, vector<int>& ranks){
        //find the parent
        int node1Parent = parentFind(node1, parents);
        int node2Parent = parentFind(node2, parents);
        //ranks
        int node1ParentRank = ranks[node1Parent];
        int node2ParentRank = ranks[node2Parent];
        //update
        if(node1ParentRank >= node2ParentRank){
            ranks[node1Parent]++;
            parents[node2Parent] = node1Parent;
        }
        else{
            ranks[node2Parent]++;
            parents[node1Parent] = node2Parent;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parents(n);
        vector<int> ranks(n, 0);
        //self parents
        for(int i=0; i<n; i++){
            parents[i] = i;
        }

        unordered_map<string, int> mp;
        //traverse through the accounts
        int rowID = 0;
        for(vector<string> data: accounts){
            int colSize = data.size();
            string title = data[0];
            //characteristics
            for(int i=1; i<colSize; i++){
                string characteristic = accounts[rowID][i];
                //check if its already there in the mp
                auto it = mp.find(characteristic);
                if(it != mp.end()){
                    //its already present
                    //unionFind
                    unionFind(rowID, it->second, parents, ranks);
                }
                else{
                    //did not find
                    //push it in the mp
                    mp[characteristic] = rowID;
                }
            }
            rowID++;
        }

        unordered_map<int, set<string>> preAns;
        //traverse through the map
        for(pair<const string, int> data: mp){
            int rowId = data.second;
            string characteristic = data.first;
            int parentRowId = parentFind(rowId, parents);
            preAns[parentRowId].insert(characteristic);
        }

        vector<vector<string>>ans;
        for(pair<const int, set<string>> data: preAns){
            int rowID = data.first;
            set<string> characteristics =  data.second;
            string title = accounts[rowID][0];
            vector<string> temp;
            temp.push_back(title);
            for(string character: characteristics){
                temp.push_back(character);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};