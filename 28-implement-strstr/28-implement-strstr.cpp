class Solution {
public:
    int strStr(string s, string t) {
        int m=s.size(); 
        int n=t.size();
        if(!n)return 0;
        
        vector<int> lps=kmp(t);
        
        for(int i=0,j=0;i<m;){
              if(s[i]==t[j]){
                  i++;
                  j++;
              }
            if(j==n){
                return i-j;
            }
            if(i<m && s[i]!=t[j]){
                j?j=lps[j-1]:i++;
            }
        }
        return -1;
    }
    
    vector<int> kmp(string p){
        vector<int> lps(p.size(),0);
        for(int i=1;i<p.size();i++){
             int j=lps[i-1];
             while(j>0 && p[i]!=p[j]){
                 j=lps[j-1];
             }
            lps[i]=(j+=p[i]==p[j]);
        }
        return lps;
    }
};