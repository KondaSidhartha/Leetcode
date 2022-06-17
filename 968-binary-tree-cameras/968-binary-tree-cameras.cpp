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
    int ans(TreeNode* root,int &n){
        if(root==NULL){
            return 1;
        }
        int l=ans(root->left,n);
        int r=ans(root->right,n);
        if(l==-1 || r==-1){
            n++;
            return 0;
        }
        if(l==0 || r==0){
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int n=0;
        if(ans(root,n)==-1){
            n++;
        }
        return n;
    }
};