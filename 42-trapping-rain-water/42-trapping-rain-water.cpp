class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxright=0;
        int maxleft=0;
        int ans=0;
        while(left<right){
            maxleft=max(height[left],maxleft);
            maxright=max(height[right],maxright);
            if(maxright>maxleft){
                ans+=(maxleft-height[left]);
                left++;
            }
            else{
                ans+=(maxright-height[right]);
                right--;
            }
        }
        return ans;
    }
};