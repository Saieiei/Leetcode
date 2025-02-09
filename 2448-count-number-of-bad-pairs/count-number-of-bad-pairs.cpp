class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //this 1 is quite the challenge
        //so Hint 1 Would it be easier to count the number of pairs that are not bad pairs or basically good pairs?
            //to do so we need to find the total number of pairs possible
            //and that is using the formula that is (n*(n-1))/2 (its basically the sum of n-1 elemets and also possible number of pairs of N elements)
        //so bad pairs = total pairs - good pairs
        //so how do we get good pairs now?
            //Hint 2 Notice that (j - i != nums[j] - nums[i]) is the same as (nums[i] - i != nums[j] - j).
                //so to find the good pair we have to see if nums[i] - i == nums[j] - j
            //before we proceed with that we can not travel against 10^5 in for loops. so for each element i we will store its nums[i] - i as a hashMap with freq[val]++;
            //so if there are 2 elements with the same nums[i] - i value then freq[val]++ becomes 2
                //so now we know there is exists 1 good pair
            //but what is freq[val]++ becomes 3?
                //so now we now know that there exist 3 good pairs
            //so how can we find out how many pairs?
                //its obvious using the same formula (n*(n-1))/2
                    //so using this formual we can add up all the possible good pairs
        //so now we have the number of good pairs and the total pairs possible for N
        //find the bad pairs using bad pairs = total pairs - good pairs

        long long n = nums.size();
        long long totalPairs = (n*(n-1))/2;

        //finding good pairs
        //putting base
        unordered_map<long long, long long>freq;
        for(int i=0; i<n; i++)
        {
            long long val = nums[i] - i;
            freq[val]++;
        }

        //summing up good pairs
        long long goodPairs = 0;
        for(auto& pairs: freq)
        {
            long long secd = pairs.second;
            goodPairs = goodPairs + (secd*(secd-1))/2;
        }

        return  totalPairs - goodPairs;

    }
};