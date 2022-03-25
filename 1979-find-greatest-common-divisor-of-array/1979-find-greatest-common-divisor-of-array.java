class Solution {
    public int findGCD(int[] nums) {
        int small=nums[0];
        int big=nums[0];
        int ans=1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<small){
                small=nums[i];
            }
            if(nums[i]>big){
                big=nums[i];
            }
        }
        for(int i=2;i<=small;i++){
            if((small%i)==0&&(big%i)==0){
               ans=i; 
            }
        }
        return ans;
    }
}