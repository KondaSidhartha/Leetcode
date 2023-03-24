//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        unordered_map<char,int> mp;
        for(auto i:s)mp[i]++;
        bool f=0;
        int i=0;
        int j=s.size()-1;
        char ch;
        string a="";
        string b="";
        int cnt=0;
        while(i<=j){
            if(f){ch=s[j]; j--;}
            else {ch=s[i]; i++;}
            
            if(mp[ch]>1){
                mp[ch]--;
                f=!f;
                cnt++;
            }
            else{
                if(f)b=ch+b;
                else a+=ch;
            }
        }
        string ans=a+b;
        if(cnt%2==1)reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends