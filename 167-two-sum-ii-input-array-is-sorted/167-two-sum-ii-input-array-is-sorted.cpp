class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int> ans(2);
        int i=0;
        int j=a.size()-1;
        while(i<j){
            if(a[i]+a[j]==target){
                ans[0]+=i+1;
                ans[1]+=j+1;
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