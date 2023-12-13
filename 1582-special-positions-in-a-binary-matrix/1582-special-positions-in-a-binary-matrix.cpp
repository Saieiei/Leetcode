class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int flag=0;
        int row=0;
        int col=0;
        int ans=0;
        for(int i=0;i<mat.size();i++) //iterate through ech row
        {
            flag=0;
            for(int j=0;j<mat[i].size();j++) //iterating through each col to find 1
            {
                if(mat[i][j]==1)
                {
                    flag=1;
                    row=i;
                    col=j;

                    int sum=0;
                    if(flag==1)
                    {
                        //we have to go through each col to find if there is more 1s
                        for(int k=0;k<mat[i].size();k++)
                        {
                            sum=sum+mat[row][k];
                        }
                        //we have to go through each row to find if there is more 1s
                        for(int k=0;k<mat.size();k++)
                        {
                            sum=sum+mat[k][col];
                        }
                        if(sum==2)
                        {
                            ans++;
                            break;
                        }
                    }
                }

            }

        }
        return ans;
        
    }
};