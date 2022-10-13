class Solution {
    public int maxProduct(int[] nums) {
        int ans=nums[0];
        int mx=ans;
        int mn=ans;
        for(int i=1;i<nums.length;i++){
            if(nums[i]<0){
                int temp=mn;
                mn=mx;
                mx=temp;
            }
            
            mx=Math.max(nums[i],mx*nums[i]);
            mn=Math.min(nums[i],mn*nums[i]);
            ans=Math.max(ans,mx);
        }
        return ans;
    }
}