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
    int mx=INT_MIN;
    int find(TreeNode* root){
        if(root==NULL)return 0;
        
        int left=max(find(root->left),0);
        int right=max(find(root->right),0);
        
        mx=max(left+right+root->val,mx);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        find(root);
        return mx;
    }
};