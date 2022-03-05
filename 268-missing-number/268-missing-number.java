class Solution {
    public int missingNumber(int[] nums) {
        boolean ans[]=new boolean[nums.length+1];
        for(int i=0;i<nums.length;i++){
            ans[nums[i]]=true;
        }
        int i=0;
        for(i=0;i<ans.length;i++){
            if(!ans[i]){
                break;
            }
        }
        return i;
    }
}