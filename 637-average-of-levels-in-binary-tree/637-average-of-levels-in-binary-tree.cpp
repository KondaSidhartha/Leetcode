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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            int len=q.size();
            int i=0;
            long sum=0;
            while(i<len){
                auto it=q.front();
                q.pop();
                sum+=it->val;
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
                i++;
            }
            ans.push_back((double)sum/len);
        }
        return ans;
    }
};