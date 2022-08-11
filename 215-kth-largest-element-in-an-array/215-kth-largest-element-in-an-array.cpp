class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> a;
        for(int i=0;i<k;i++){
            a.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(a.top()<nums[i]){
                a.pop();
                a.push(nums[i]);
            }
        }
        return a.top();
    }
};