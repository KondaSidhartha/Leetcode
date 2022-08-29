/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            if(tmp->left){
                parent[tmp->left]=tmp;
                q.push(tmp->left);
            }
            if(tmp->right){
                parent[tmp->right]=tmp;
                q.push(tmp->right);
            }
        }
        q.push(target);
        int level=0;
        unordered_map<TreeNode*,bool> visit;
        visit[target]=true;
        while(!q.empty()){
            int size=q.size();
            if(level==k)break;
            level++;
            for(int i=0;i<size;i++){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left && !visit[tmp->left]){
                    q.push(tmp->left);
                    visit[tmp->left]=true;
                    
                }
                if(tmp->right && !visit[tmp->right]){
                    q.push(tmp->right);
                    visit[tmp->right]=true;
                }
                if(parent[tmp] && !visit[parent[tmp]]){
                    q.push(parent[tmp]);
                    visit[parent[tmp]]=true;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};