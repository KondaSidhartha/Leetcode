class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
    int i=0;
    int j=0;
    int ans=0;
    while(j<s.size()){
         if(mp[s[j]]==0){
            mp[s[j]]=j+1;
         }
         else{
            while(i<=mp[s[j]]){
                mp[s[i]]=0;
                i++;
            }
            mp[s[j]]=j+1;
         }
         ans=max(j-i+1,ans);
         j++;
    }
        return ans;
    }
};