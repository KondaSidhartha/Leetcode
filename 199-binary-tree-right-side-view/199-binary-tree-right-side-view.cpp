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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        find(root,ans,1);
        return ans;
    }
    void find(TreeNode* root,vector<int> &ans,int len){
        if(root==NULL)return;
        if(len>ans.size()){
            ans.push_back(root->val);
        }
        find(root->right,ans,len+1);
        find(root->left,ans,len+1);
    }
};