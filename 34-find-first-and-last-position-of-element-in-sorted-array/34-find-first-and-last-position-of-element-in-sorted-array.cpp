class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0]=search(nums,target,true);
        ans[1]=search(nums,target,false);
        return ans;
    }
    int search(vector<int>& nums, int target,bool first){
        int ans=-1;
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]>target){
                e=m-1;
            }
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                ans=m;
                if(first)e=m-1;
                else s=m+1;
            }
        }
        return ans;
    }
};