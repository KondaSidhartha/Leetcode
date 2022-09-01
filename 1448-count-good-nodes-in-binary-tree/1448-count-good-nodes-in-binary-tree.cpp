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
    int ans=0;
    void solve(TreeNode* root,int mx){
        if(root==NULL)return;
        if(root->val>=mx)ans++;
        solve(root->left,max(root->val,mx));
        solve(root->right,max(root->val,mx));
    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return ans;
    }
};