class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        //just build a vector with a lots of space
        vector<int> freq(*max_element(nums.begin(), nums.end()) + nums.size()+1, 0);
        //now take frequency
        for(auto el: nums) freq[el]++;
        
        //now we will play th game only with frequency
        //if a index has 2 numbers, it means that we will keep only 1 to that index and push teh rest to the next index(+1)
        //so if index 3 has 4 elemts then we will keep that index as 1 elemnt an push the rest to the next index
            //that is index 4 now has the elemnts it already has +(3 elemtnst (4-1))
        int ans=0;
        for(int i =0;i<freq.size();i++)
        {
            if(freq[i]<=1) //basiaclly 0 and 1 u dont have to do anything
                continue;
            
            int extra=freq[i]-1; // let that index have only 1 element and push this extra numbers to the next index
            freq[i+1]=freq[i+1]+extra;
            //make sure to update the number of movies
            ans=ans+extra;
        }
        return ans;
    }
};