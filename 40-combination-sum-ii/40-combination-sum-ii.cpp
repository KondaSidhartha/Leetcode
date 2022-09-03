class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &arr,vector<int> a,int target,int curr,int idx){
        if(curr==target){
            ans.push_back(a);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1])continue;
            if(arr[i]+curr>target)return ;
            a.push_back(arr[i]);
            solve(arr,a,target,curr+arr[i],i+1);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums,int target) {
        vector<int> a;
        sort(nums.begin(),nums.end());
        solve(nums,a,target,0,0);
        return ans;
    }
};