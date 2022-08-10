class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        search(nums,temp);
        return ans;
    }
    void search(vector<int> &nums, vector<int> &temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }
        
        for(int i=0;i<nums.size();i++){
            auto it=find(temp.begin(),temp.end(),nums[i]);
            if(it!=temp.end())continue;
            
            temp.push_back(nums[i]);
            search(nums,temp);
            temp.pop_back();
        }
    }
};