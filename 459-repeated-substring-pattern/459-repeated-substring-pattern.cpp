class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ans=s+s;
        string sub=ans.substr(1,ans.size()-2);
        if(sub.find(s)!=-1)return true;
        else return false;
    }
};