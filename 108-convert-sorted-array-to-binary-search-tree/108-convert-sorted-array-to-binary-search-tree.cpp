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
    TreeNode* bst(int l,int r,vector<int>& nums){
        if(l>r)return nullptr;
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(-1);
        root->val=nums[mid];
        root->left=bst(l,mid-1,nums);
        root->right=bst(mid+1,r,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(0,nums.size()-1,nums);
    }
};