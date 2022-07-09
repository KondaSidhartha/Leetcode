class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int count=0;
        while(r<nums.size()-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,nums[i]+i);
            }
            count++;
            l=r;
            r=farthest;
        }
        return count;
    }
};