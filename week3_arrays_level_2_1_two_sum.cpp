#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
    int nums[]={3,2,4};
    int target=6;
    int indxs[2]; 
        int i=0, j = 2;

        while(i<j && j>=0){
                
                if(nums[i]+nums[j]==target){
                    indxs[0]=i;
                    indxs[1]=j;
                    break;
                }
                else{
                    i++;
                }
                
                if(i==j){
                i=0;
                j--;
            }
            
        }

}