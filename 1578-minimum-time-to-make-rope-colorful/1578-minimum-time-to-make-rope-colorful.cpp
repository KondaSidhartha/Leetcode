class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){  
            int mx=cost[i],tsum=cost[i];
            while (i<n-1&&s[i]==s[i+1]){
                mx=max(cost[i+1],mx);
                tsum+=cost[i+1];
                i++;
            }
            ans+=(tsum-mx);
        }    
        return ans;
        
    }
};