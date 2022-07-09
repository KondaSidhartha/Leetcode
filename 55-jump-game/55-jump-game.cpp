class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,nums[i]+i);
            }
            if(r==farthest)
            {
                return false;
            }
            l=r;
            r=farthest;
        }
        return true;
    }
};