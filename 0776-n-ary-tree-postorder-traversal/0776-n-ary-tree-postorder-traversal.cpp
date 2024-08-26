/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    // Function to perform postorder traversal
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }

private:
    // Helper function to recursively perform postorder traversal
    void postorderTraversal(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return; // Base case: if the node is null, return
        }

        // Recursively traverse all children
        for (Node* child : node->children) {
            postorderTraversal(child, result);
        }

        // Add the node's value to the result after visiting all children
        result.push_back(node->val);
    }
};