class Solution {
public:
    int binarysearch(vector<int>& nums, int target,int s,int e){
        while(s<=e){
            int mid=s+(e-s)/2;
           if(nums[mid]==target){
            return mid;
           }
           else if(nums[mid]>target){
               e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
    int findpivot(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
         while(s<=e){
            int mid=s+(e-s)/2;
            if(mid<e && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(mid>s&&nums[mid]<nums[mid-1]){
                return mid-1;
            } 
            if (nums[mid] <= nums[s]) {
                e= mid - 1;
            } else {
                s= mid + 1;
            } 
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=findpivot(nums);
        int s=0;
        if(pivot==-1){
            return binarysearch(nums,target,0,nums.size()-1);
        }
        if(nums[pivot]==target){
            return pivot;
        }
        if(target>=nums[s]){
            return binarysearch(nums,target,0,pivot-1);
        }
        return binarysearch(nums,target,pivot+1,nums.size()-1);
    }
};