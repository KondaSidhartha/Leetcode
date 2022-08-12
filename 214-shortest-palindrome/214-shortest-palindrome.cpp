class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string p=s+"&"+rev;
        
        vector<int> lps(p.size(),0);
        for(int i=1;i<p.size();i++){
             int j=lps[i-1];
             while(j>0 && p[i]!=p[j]){
                 j=lps[j-1];
             }
            lps[i]=(j+=p[i]==p[j]);
        }
        return rev.substr(0,s.size()-lps[p.size()-1])+s;
    }
};