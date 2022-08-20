class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //just understand the pattern by seeing exapmle where to reverse and why
        int n=nums.size();
        int i,j;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])break;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(j=n-1;j>i;j--){
                if(nums[j]>nums[i])break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
        return ;
    }
};