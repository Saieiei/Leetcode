static string globalOrder;
class Solution {
public:
    static bool mycmp(const char& a, const char& b){
        return globalOrder.find(a) < globalOrder.find(b);
    }
    string customSortString(string order, string s) {
        //NlogM
        //use custome sorting function
        //make sure of the static problem
        //but if u use a globa variable and a static function
        //this is bad because it will keep chnaging and may cause race cnditions
        globalOrder = order;
        //custome sorting
        sort(s.begin(), s.end(), mycmp);
        return s;
    }
};