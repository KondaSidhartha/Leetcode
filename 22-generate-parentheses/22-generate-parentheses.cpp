class Solution {
public:
    vector<string> ans;
    void solve(int n,string s,int a,int b){
        if(s.size()==2*n){ans.push_back(s); return;}
        if(a<n){
            solve(n,s+'(',a+1,b);
        }
        if(b<a){
            solve(n,s+')',a,b+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,"(",1,0);
        return ans;
    }
};