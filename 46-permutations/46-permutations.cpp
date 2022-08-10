class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        search(nums,temp,0);
        return ans;
    }
    void search(vector<int> &nums, vector<int> &temp,int idx){
        if(idx==nums.size()){
            ans.push_back(temp);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            temp.push_back(nums[idx]);
            search(nums,temp,idx+1);
            temp.pop_back();
            swap(nums[i],nums[idx]);
        }
    }
};