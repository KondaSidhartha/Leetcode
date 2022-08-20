class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i+1)i++;
            else{
                int actpos=nums[i]-1;
                //means the extra actual element in their in the position just understand
                if(nums[actpos]==nums[i]){
                    return nums[i];
                }
                else {
                    swap(nums[i],nums[actpos]);
                }
            }
        }
        return -1;
    }
};