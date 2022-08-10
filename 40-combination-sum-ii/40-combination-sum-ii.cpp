class Solution {
public:
    vector<vector <int>> ans;
    void find(vector<int>& candidates, int target,int curr,vector<int> temp,int idx){
        if(curr==target)ans.push_back(temp);
        
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1])continue;
            if(curr+candidates[i]>target)return ;
            temp.push_back(candidates[i]);
            find(candidates,target,curr+candidates[i],temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        find(candidates,target,0,temp,0);
        return ans;
    }
};