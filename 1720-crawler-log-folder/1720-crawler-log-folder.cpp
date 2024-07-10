class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(string log : logs)
        {
            cout<<"Level = "<< level<<endl;
            cout<<"log = "<<log<<endl;
            if(log == "../") //which means go behind
            {
                if(level != 0) level --; //u cannot go behind the root level
                
            }
            else if (log == "./") continue; //do nothing
            else level++;
        }
        cout<<"Level = "<< level<<endl;
        return level;
    }
};