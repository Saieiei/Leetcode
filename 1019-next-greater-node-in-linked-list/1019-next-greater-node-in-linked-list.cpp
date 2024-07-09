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
//week 11
    vector<int> nextLargerNodes(ListNode* head) {
        //we will solve this usng stacks
        //the intuition is that we will 1st put all the linked lists into an vector
        //then we will create a vector ans, which will be returned, innitially all the values are 0
        //we will create a stack and will keep on putting the index of the element in the stack untill we get a elemnt that is greater 
        //like if the elements are monotonous decreasing and suddenly a large value comes up, then we will pop thos elements from the stack and mark them with the sudden high elemnet in the ans
        
        vector<int> llv;
        
        // Traverse the linked list and store values in the vector
        while (head) {
            llv.push_back(head->val);
            head = head->next;
        }

        // Initialize the answer vector with 0s
        vector<int> ans(llv.size(), 0);

        // Stack to store the indices of the elements in the vector
        stack<int> st;

        // Iterate through the vector to find the next greater elements
        for (int i = 0; i < llv.size(); i++) {
            // While the stack is not empty and the current element is greater than the element at the index stored at the top of the stack
            while (!st.empty() && llv[i] > llv[st.top()]) {
                // Get the index from the top of the stack
                int index = st.top();
                // Update the answer vector with the current element as the next greater element
                ans[index] = llv[i];
                // Pop the index from the stack
                st.pop();
            }
            // Push the current index onto the stack, if the stack is empty
            st.push(i);
        }
        return ans;
    }
};