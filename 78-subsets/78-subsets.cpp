class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums,vector<int> a,int l){
        ans.push_back(a);
        for(int i=l+1;i<nums.size();i++){
            a.push_back(nums[i]);
            solve(nums,a,i);
            a.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        solve(nums,a,-1);
        return ans;
    }
};