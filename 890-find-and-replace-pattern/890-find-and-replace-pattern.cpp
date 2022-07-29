class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> v;
        p=standard(p);
        for(auto a:words){
            if(standard(a)==p)v.push_back(a);
        }
        return v;
    }
    string standard(string s){
        unordered_map<char,int> mp;
        for(auto a:s){
            if(mp[a]==0){
                mp[a]=mp.size();
            }
        }
        for(int i=0;i<s.size();i++){
            s[i]='a'+mp[s[i]];
        }
        return s;
    }
};