class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreachable=nums[0];
        for(int i=0;i<nums.size();i++){
             if(i>maxreachable)break;
             maxreachable=max(maxreachable,nums[i]+i);
        }
        return maxreachable>=nums.size()-1;
    }
};