class Solution {
    int bns(vector<int>&nums,int low,int high){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                   return bns(nums,mid+1,high);
                }
                else{
                   return  bns(nums,low,mid-1);
                }
            }
            else if(nums[mid]==nums[mid-1]){
                if(mid%2==1){
                   return bns(nums,mid+1,high);
                }
                else{
                    return bns(nums,low,mid-1);
                }
            }
            else{
                return nums[mid]; 
            }
        }
        return -1;
     }
    
public:
    int singleNonDuplicate(vector<int>& nums) {
     int n=nums.size();
     if(n==1)return nums[0];
     if(nums[0]!=nums[1])return nums[0];
     if(nums[nums.size()-1]!=nums[nums.size()-2])return nums[nums.size()-1];
     return bns(nums,0,n-1);
    }
};