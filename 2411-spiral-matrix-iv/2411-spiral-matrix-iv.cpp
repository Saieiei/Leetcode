/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        //its easy only
        // u can do it

        //so 1st we will create a matrix where everything is innitialised to -1
        //this will help us cover up the part where  If there are remaining empty spaces, fill them with -1.
        vector<vector<int>> matrix (m, vector<int>(n, -1));

        //we will use this pointer as i do not wish to disturb the head position
        ListNode* curr = head;

        //now we will use the below as indexes for the matrix (boundries)
        int top = 0, right = n - 1, bottom = m -1, left = 0;

        //now we will keep filling up the matrix with the correct value, unless these boundries cross each other
        while(top<=bottom && left<=right && curr != NULL)
        {
            //1st we will cover up the top part (1st row)
            for(int i = left; i<= right && curr != NULL; i++)
            {
                matrix[top][i] = curr->val;
                curr = curr->next;
            }
            //move the top to 1 step down
            top++;

            //2nd we will cover up the right part
            for(int i = top; i<=bottom && curr!= NULL; i++)
            {
                matrix[i][right] = curr->val;
                curr = curr->next;
            }
            //move right 1 step to left
            right--;

            //3rd we will cover up the bottom part
            for(int i = right; i>=left && curr!= NULL; i--)
            {
                matrix[bottom][i] = curr->val;
                curr = curr->next;
            }
            //move up 1 step from bottom
            bottom--;

            //4th we will cover the left part
            for(int i = bottom; i>=top && curr!= NULL; i--)
            {
                matrix[i][left] = curr->val;
                curr = curr->next;
            }
            //move right 1 step from left
            left++;
        }

        //now return the final matrix
        return matrix;

    }
};