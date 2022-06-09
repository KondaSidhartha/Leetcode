class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> ans(2,1);
        int i=0;
        int j=a.size()-1;
        while(i<j){
            if(a[i]+a[j]==target){
                ans[0]+=i;
                ans[1]+=j;
                break;
            }
            else if(a[i]+a[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
       return ans; 
    }
};