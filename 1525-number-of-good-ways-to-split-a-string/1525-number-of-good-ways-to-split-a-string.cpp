class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mp1;
        for(int i=0;i<s.size();i++)mp1[s[i]]++;
        int ans=0;
        unordered_map<char,int> mp2;
        for(int i=0;i<s.size();i++){
            mp2[s[i]]++;
            mp1[s[i]]--;
            if(mp1[s[i]]==0){
                mp1.erase(s[i]);
            }
            if(mp1.size()==mp2.size()){
                ans++;
            }
        }
        return ans;
    }
};