class Solution {
public:
    string customSortString(string order, string s) {
        //NlogM
        //use custome sorting lambda function
        //there will be no statiuc problem
        //this is better than global static fun because
        //it avoids the race condition cuzed by the global static var
        //creat the ranking system for the custom lambda sorting
        //every1 ranked the lowest 0th postion = high, 25th postion = low
        vector<int> ranks(26, 26);
        //give them the ranks based on the order
        for(int i=0; i<order.size(); i++){
            char chOrder = order[i];
            ranks[chOrder - 'a'] = i;
        }
        //custom lambda sorting
        sort(s.begin(), s.end(), [&](const char& a, const char& b){
            return ranks[a - 'a'] < ranks[b - 'a'];
        });
        return s;
    }
};