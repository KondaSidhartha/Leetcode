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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<int,vector<int>> ans;
        q.push({root,0});
        
        while(!q.empty()){
            multiset<pair<int,int>> tmp;
            int len=q.size();
            for(int i=0;i<len;i++){
                auto it=q.front();
                q.pop();
                TreeNode* node=it.first;
                int d=it.second;
                tmp.insert({d,node->val});
                if(node->left)q.push({node->left,d-1});
                if(node->right)q.push({node->right,d+1});
            }
            for(auto p:tmp)ans[p.first].push_back(p.second);
        }
        vector<vector<int>> a;
        for(auto i:ans)a.push_back(i.second);
        return a;
    }
};