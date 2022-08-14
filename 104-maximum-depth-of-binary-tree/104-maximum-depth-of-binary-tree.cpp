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
    int find(TreeNode* root,int a){
        if(root==NULL)return a-1;
        
        a=max(find(root->left,a+1),find(root->right,a+1));
        return a;
    }
    int maxDepth(TreeNode* root) {
        return find(root,1);
    }
};