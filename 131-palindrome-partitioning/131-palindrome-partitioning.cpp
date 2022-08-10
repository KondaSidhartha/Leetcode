class Solution {
public:
    vector<vector<string>> ans;
    bool palin(string S)
{
    for (int i = 0; i < S.length() / 2; i++) {
        if (S[i] != S[S.length() - i - 1]) {
            return false;
        }
    }
    return true;
}
    void find(string s,vector<string> &temp,int idx){
        
        if(idx==s.size()){ans.push_back(temp); return ;}
        for(int i=idx;i<s.size();i++){
                if(palin(s.substr(idx,i-idx+1))){
                    temp.push_back(s.substr(idx,i-idx+1));
                    find(s,temp,i+1);
                    temp.pop_back();
                }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        find(s,temp,0);
        return ans;
    }
};