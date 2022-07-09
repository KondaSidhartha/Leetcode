class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> p;
        fun(s,ans,p,0);
        return ans;
    }
    void fun(string s,vector<vector<string>> &ans,vector<string> &p,int index){
        if(index==s.size()){
            ans.push_back(p);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(palindrome(s,index,i)){
                p.push_back(s.substr(index,i-index+1));
                fun(s,ans,p,i+1);
                p.pop_back();
            }
        }
    }
    bool palindrome(string s,int start,int last){
        while(start<=last){
            if(s[start++]!=s[last--])return false;
        }
        return true;
    }
};