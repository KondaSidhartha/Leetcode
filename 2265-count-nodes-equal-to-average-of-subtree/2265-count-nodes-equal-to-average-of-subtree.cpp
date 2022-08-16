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
    
    pair<int,int> find(TreeNode* root,int count){
        if(root==0)return {0,count};
        
        pair<int,int> left=find(root->left,count);
        pair<int,int> right=find(root->right,count);
        
        int sum=left.first+right.first+root->val;
        if(sum/(left.second+right.second+1)==root->val)ans++;
        
        return {sum,left.second+right.second+1};
        
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)return 0;
        
        pair<int,int> left=find(root->left,0);
        pair<int,int> right=find(root->right,0);
        
        int sum=left.first+right.first+root->val;
        if(sum/(left.second+right.second+1)==root->val)ans++;

        return ans;
    }
};