//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool match(string &s,string &p){
        if(s.size()<p.size())return false;
        for(int i=0;i<p.size();i++){
            if(s[i]!=p[i])return false;
        }
        return true;
    }
    vector<string> CamelCase(int N, vector<string> Dick, string P) {
        map<string,pair<string,int>> mp;
        
        for(int i=0;i<Dick.size();i++){
            mp[Dick[i]].second++;
            for(int j=0;j<Dick[i].size();j++){
                if(isupper(Dick[i][j])){
                    mp[Dick[i]].first+=Dick[i][j];
                }
            }
        }
        vector<string> ans;
        for(auto it:mp){
            if(match(it.second.first,P)){
                for(int i=0;i<it.second.second;i++){
                    ans.push_back(it.first);
                }
            }
        }
        if(ans.size()==0)return {"-1"};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends