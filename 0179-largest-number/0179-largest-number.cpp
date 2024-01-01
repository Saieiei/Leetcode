//week5_ass_11
class Solution {
public:

    static bool customSort(string a, string b)
    {
        string combi1=a+b;
        string combi2=b+a;
        return combi1>combi2; //this will auto maticallt return the largest value combination
    }


    string largestNumber(vector<int>& nums) {
        //we will put all these values in a vector of string
        //then we will sort that in such a away that we will take 2 strings and do a+b and b+a, we will see which 1 is greater and return that accordingly using a custom comparator
        //do not sort it in decending order if ur thinking because if u have 30, 3 it will return the final ans as 303 which is wrong, it has to written 330 as 330>303
        //ok so lets begin
        vector<string> ans;
        //storing it in string format in the vector ans
        for(auto i:nums)
        {
            ans.push_back(to_string(i));
        }

        //custom sort
        sort(ans.begin(), ans.end(), customSort);
        if(ans[0]=="0") return "0"; //corner testcase

        string finalAns="";
        for(int i=0;i<ans.size();i++)
        {
            finalAns=finalAns+ans[i];
        }
        return finalAns;

        
    }
};