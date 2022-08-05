class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      vector<unsigned int> dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int a:nums){
                if(i>=a){
                    dp[i]+=dp[i-a];
                }
            }
        }
        return dp[target];
}
};


// class Solution {
// public:
//     int combinationSum4(vector<int>& N, int T) {
//         vector<unsigned int> dp(T+1, 0);
//         dp[0] = 1;
//         for (int i = 1; i <= T; i++)
//             for (int num : N)
//                 if (num <= i) dp[i] += dp[i-num];
//         return dp[T];
//     }
// };