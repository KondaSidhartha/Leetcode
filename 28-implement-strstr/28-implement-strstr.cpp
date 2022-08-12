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
    
    vector<int> kmp(string t){
         vector<int> lps(t.size(),0);
        int len=0;
        for(int i=1;i<t.size();){
            if(t[i]==t[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else if(len){
                len=lps[len-1];
            }
            else{
                lps[i++]=0;
            }
        }
        return lps;
    }
};