//this is easy if we use custom sort comparator, but custom sort comparator has a different format in strings
//week5_cl3
class Solution {
public:
    static string globalOrder;
    static bool customComparator(char ch1, char ch2)//we cannot pass a string in this fucntion, hence we have to use global variable, but we come wirh static problems, so we have to define static at 2 places
    {
        return (globalOrder.find(ch1) < globalOrder.find(ch2));
    }
    string customSortString(string order, string s) {

        globalOrder=order;
        sort(s.begin(), s.end(), customComparator);
        return s;
    }
};
string Solution::globalOrder;