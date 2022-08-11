class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.size()==0)return "";
        int n=str.size();
        string ans="";
        sort(str.begin(),str.end());
        for(int i=0;i<str[0].size();i++){
             if(str[0][i]==str[n-1][i]){
                 ans+=str[0][i];
             }
            else break;
        }
        return ans;
    }
};