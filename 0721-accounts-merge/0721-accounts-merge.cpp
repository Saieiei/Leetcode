class Solution {
public:
//to solve this u should know kruskals algo (Union, findParent)
//convert accounts into a map <string, int>
//proper union will be done in preAns <int, set<string>>
//convert preAns into ans (which pushes the nodeName) and return
    int findParent(vector<int>& parents, int node){
        if(parents[node] == node){
            return node;
        }
        //path compression
        return parents[node] = findParent(parents, parents[node]);
    }
    void unionSet(vector<int>& parents, vector<int>& ranks, int u, int v){
        int uParent = findParent(parents, u);
        int vParent = findParent(parents, v);

        if(ranks[uParent] > ranks[vParent]){
            parents[vParent] = uParent;
            ranks[uParent]++;
        }
        else if(ranks[vParent] > ranks[uParent]){
            parents[uParent] = vParent;
            ranks[vParent]++;
        }
        else{
            parents[vParent] = uParent;
            ranks[uParent]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parents(n);
        //self parents
        for(int i=0; i<n; i++){
            parents[i] = i;
        }
        vector<int> ranks(n, 0);
        unordered_map<string, int> mp;
        int i = 0;
        for(vector<string> account: accounts){
            for(int j=1; j<account.size(); j++){
                string emailID = account[j];
                auto it = mp.find(emailID);
                if(it == mp.end()){
                    mp[emailID] = i;
                }
                else{
                    unionSet(parents, ranks, i, it->second);
                }
            }
            i++;
        }
        //componets have been built here
        unordered_map<int, set<string>> preAns;
        for(auto it: mp){
            int accountNO = it.second;
            string emailID = it.first;
            int parent = findParent(parents, accountNO);
            preAns[parent].insert(emailID);
        }
        //final ans
        vector<vector<string>> ans;
        for(auto it: preAns){
            int accountNO = it.first;
            set<string> emailIDs = it.second;
            vector<string> temp;
            string accountName = accounts[accountNO][0];
            temp.push_back(accountName);
            for(string emailID: emailIDs){
                temp.push_back(emailID);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};