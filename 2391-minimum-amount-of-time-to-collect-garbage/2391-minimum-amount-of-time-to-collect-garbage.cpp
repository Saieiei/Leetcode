//easy problem staight forward
//week5 cl 3
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //we will 1st calculate picking time for each type of unit
        //then we will calculate travelling time for each type of unit

        int pickM=0, pickP=0, pickG=0;
        int travelM=0, travelP=0, travelG=0;

        //this is needed to know to understand till where the trck should go to (the last house where this unit is present)
        //this will help us in the travel time find
        int lastM=0, lastP=0, lastG=0;

        //calculating the pickup time and fiding where the type of truck need to go till which house end
        for(int i=0;i<garbage.size();i++)
        {
            string s=garbage[i];
            for(int j=0;j<s.size();j++)
            {
                char ch=s[j];
                if(s[j]=='M')
                {
                    pickM++;
                    lastM=i;
                }
                if(s[j]=='P')
                {
                    pickP++;
                    lastP=i;
                }
                if(s[j]=='G')
                {
                    pickG++;
                    lastG=i;
                }
            }

        }

        //calculating travel time
        for(int i=0;i<lastM;i++)
        {
            travelM=travelM+travel[i];
        }
        for(int i=0;i<lastP;i++)
        {
            travelP=travelP+travel[i];
        }
        for(int i=0;i<lastG;i++)
        {
            travelG=travelG+travel[i];
        }

        int ans=(pickM+travelM)+(pickP+travelP)+(pickG+travelG);
        return ans;
    }
};