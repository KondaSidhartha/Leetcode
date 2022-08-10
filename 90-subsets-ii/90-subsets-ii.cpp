class Solution {
public:
    vector<vector<int>> ans;
    void findsubsets(vector<int> &nums,int i,vector<int> &temp){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])continue;
            temp.push_back(nums[j]);
            findsubsets(nums,j+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        findsubsets(nums,0,temp);
        return ans;
    }
};