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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return vector<vector<int> > ();
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool rev=true;
        while(!q.empty()){
             rev=!rev;
             vector<int> temp;
             int len=q.size();
              while(len--){
                  TreeNode* curr=q.front();
                  q.pop();
                  temp.push_back(curr->val);
                  if(curr->left)q.push(curr->left);
                  if(curr->right)q.push(curr->right);
              }
              if(rev)reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};