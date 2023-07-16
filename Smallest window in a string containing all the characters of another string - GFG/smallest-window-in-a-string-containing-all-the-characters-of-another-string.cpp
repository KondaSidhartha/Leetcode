//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        if(t.size()>s.size())return "-1";
        if(s==t)return s;
        vector<int> v(26,0);
        int cnt=0;
        for(auto it:t){
            if(v[it-'a']==0)cnt++;
            v[it-'a']++;
        }
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int start=0;
        while(j<s.size()){
            v[s[j]-'a']--;
            if(v[s[j]-'a']==0)cnt--;
            if(cnt==0){
                while(cnt==0){
                    if(j-i+1<ans){
                        start=i;
                        ans=j-i+1;
                    }
                    v[s[i]-'a']++;
                    if(v[s[i]-'a']==1)cnt++;
                    i++;
                }
            }
            j++;
        }
        if(ans==INT_MAX)return "-1";
        return s.substr(start,ans);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends