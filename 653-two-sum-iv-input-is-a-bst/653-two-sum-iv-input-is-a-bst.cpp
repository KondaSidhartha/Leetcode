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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        order(root,v);
        
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k)return true;
            else if(v[i]+v[j]>k)j--;
            else i++;
        }
        return false;
        
    }
    void order(TreeNode* root, vector<int> &v){
        if(root==NULL)return ;
        
        order(root->left,v);
        v.push_back(root->val);
        order(root->right,v);
    }
};