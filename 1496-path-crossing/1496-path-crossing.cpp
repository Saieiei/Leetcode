class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        char c1, c2;
        string s1;
        s1="0,0";
        set<string> set1;
        set1.insert(s1);
        int flag=0;
        //printing the set
        //cout<<"set1: ";
        // for(auto i:set1)
        //{
        //        cout<<i<<" ";
        //}
        //cout<<endl;
        for(int i=0;i<path.length();i++)
        {
            //printing the set
            //cout<<"set1: ";
            //for(auto j:set1)
            //{
            //        cout<<j<<" ";
            //}
            //cout<<endl;
            if(path[i]=='N')
            {
                y++;
            }
            else if(path[i]=='S')
            {
                y--;
            }
            else if(path[i]=='E')
            {
                x++;
            }
            else if(path[i]=='W')
            {
                x--;
            }
            c1 = char(x);
            c2 = char(y);
            s1 = to_string(x) + "," + to_string(y);  // Convert x and y to strings
            //cout << s1 << endl;
            //checking if the string is present in the set
            for(auto i:set1)
            {
                if(i==s1)
                {
                    flag=1;
                    break;
                }
            }

            set1.insert(s1);
        }
        if(flag==1)
        {
            //cout<<"true";
            return 1;
        }
        else{
            //cout<<"false";
            return 0;
        }


        return 0;
    }
};