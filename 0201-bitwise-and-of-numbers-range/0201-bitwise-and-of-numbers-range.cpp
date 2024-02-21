//let me explain how its done
//5->101
//7->111
//4->100
//how is this possible?
//basically the bits that has never been changed/manupulated to reach right digit from left digit should be always to 1 and the bits that has been chnaged / altered is 0

//ok since now u uk how to do it lets see how to approach the problem 
//we shall have a counter, that will count the number of bits that has been altered to reach right digit from left digit
    //this will be done using left shift operator
//now we have the number of digits that has been altered
    //now we will find the final ans, using the counter we will find the final anser. We will do this with the help of right shift.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int counter=0;
        while(left!=right)
        {
            left=left>>1;
            right=right>>1;
            counter++;
        }
        //u can take left or right, it does not matter
        int ans=left<<counter;
        return ans;
    }
};