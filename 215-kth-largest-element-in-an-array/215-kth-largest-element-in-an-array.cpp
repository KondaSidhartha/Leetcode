class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mp;
        for(int i=0;i<k;i++){
            mp.insert(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(*(mp.begin())<nums[i]){
                mp.erase(mp.begin());
                mp.insert(nums[i]);
            }
        }
        return *(mp.begin());
    }
};