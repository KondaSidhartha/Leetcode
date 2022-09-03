class Solution {
public:
    vector<vector<int>> ans;
    void solve(int len,int target,vector<int> a,int idx,int curr){
        if(a.size()>len)return ;
        if(curr==target && a.size()==len){
            ans.push_back(a);
        }
        //cout<<curr<<" ";
        for(int i=idx;i<=9;i++){
            if(i+curr>target)return ;
            a.push_back(i);
            solve(len,target,a,i+1,curr+i);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        solve(k,n,a,1,0);
        return ans;
    }
};