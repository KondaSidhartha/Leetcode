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
    bool sym(TreeNode* lef,TreeNode* righ){
        if(lef==NULL && righ==NULL)return true;
        if(lef==NULL || righ==NULL)return false;
        
        if(lef->val!=righ->val)return false;
        return sym(lef->left,righ->right) && sym(lef->right,righ->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return sym(root->left,root->right);
    }
};