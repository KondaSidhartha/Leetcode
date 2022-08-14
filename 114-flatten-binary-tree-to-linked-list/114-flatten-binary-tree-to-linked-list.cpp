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
        if(root)solve(root);
    }
    TreeNode* head;
    void solve(TreeNode* root){
        
        if(root->right)solve(root->right);
        if(root->left)solve(root->left);
        
        root->left=NULL;
        root->right=head;
        head=root;
        
    }
};