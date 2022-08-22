class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> pp(n);
        for(int i=0;i<p.size();i++){
            pp[p[i][0]].push_back(p[i][1]);
        }
        vector<int> indeg(n);
        
        for(int i=0;i<n;i++){
            for(auto j:pp[i]){
                indeg[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            for(auto j:pp[i]){
                indeg[j]--;
                if(indeg[j]==0)q.push(j);
            }
        }
        for(int i=0;i<n;i++){
            if(indeg[i]!=0)return false;
        }
        return true;
    }
};