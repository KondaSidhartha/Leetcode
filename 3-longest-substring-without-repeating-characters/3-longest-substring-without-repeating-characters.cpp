class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        vector<int> nextIndex(128);
        int l=0;
        for(int r=0;r<s.size();r++){
            l=max(nextIndex[s[r]],l);
            ans=max(ans,r-l+1);
            nextIndex[s[r]]=r+1;
        }
        return ans;
    }
};