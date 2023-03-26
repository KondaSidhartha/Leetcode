//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string tar, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({startWord,1});
        s.erase(startWord);
        while(!q.empty()){
            string w=q.front().first;
            int d=q.front().second;
            q.pop();
            if(w==tar)return d;
            for(int i=0;i<w.size();i++){
                    char org=w[i];
                    for(char ch='a';ch<='z';ch++){
                        w[i]=ch;
                        if(s.find(w)!=s.end()){
                            s.erase(w);
                            q.push({w,d+1});
                        }
                    }
                    w[i]=org;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends