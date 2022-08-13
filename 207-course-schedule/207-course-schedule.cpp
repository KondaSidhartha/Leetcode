class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(auto i:p){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> in(n);
        for(auto i:adj){
            for(auto e:i){
                in[e]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int k=q.front();
            q.pop();
            for(auto i:adj[k]){
                in[i]--;
                if(in[i]==0)q.push(i);
            }
        }
        for(int i=0;i<n;i++){
             if(in[i]>0)return 0;
        }
        return 1;
        
    }
};