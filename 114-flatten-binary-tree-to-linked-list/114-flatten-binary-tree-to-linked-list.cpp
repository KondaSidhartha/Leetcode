/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root)reverseinorder(root);
    }
 private:
    TreeNode* head=nullptr;
    void reverseinorder(TreeNode* node){
        if(node->right)
            reverseinorder(node->right);
        if(node->left)
            reverseinorder(node->left);
        node->left=nullptr;
        node->right=head;
        head=node;
    }
};