class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26),temp(26);
        for(auto &c:words2){
           temp=counter(c);
           for(int i=0;i<26;i++){
               count[i]=max(count[i],temp[i]);
           }
        }
        vector<string> res;
        for(auto &c: words1){
            int i=0;
            temp=counter(c);
            for(i=0;i<26;i++){
                if(temp[i]<count[i])break;
            }
            if(i==26)res.push_back(c);
        }
        return res;
    }
    vector<int> counter(string s){
        vector<int> count(26);
        for(char c:s)count[c-'a']++;
        return count;
    }
};