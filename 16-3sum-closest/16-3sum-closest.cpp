class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
                if(abs(sum-target)<min){
                    min=abs(sum-target);
                    ans=sum;
                }
            }
            
        }
        return ans;
    }
};