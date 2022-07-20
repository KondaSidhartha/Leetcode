class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        int ans=0;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(subseq(s,it->first)){
                ans+=it->second;
            }
        }
        return ans;
    }
    int subseq(string &a,string b){
        int i=0,j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                
                i++;
            }
        }
        return j==b.size();
    }
};