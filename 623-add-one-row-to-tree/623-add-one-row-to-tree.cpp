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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if(d==1) return new TreeNode(val,root,NULL);
        
        queue<TreeNode*> q;
        q.push(root);
        while(d--){
            int len=q.size();
            while(len--){
                if(d>1){
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right)q.push(q.front()->right);
                }
                else{
                    q.front()->left=new TreeNode(val,q.front()->left,NULL);
                    q.front()->right=new TreeNode(val,NULL,q.front()->right);
                }
                q.pop();
            }
        }
        return root;
    }
};