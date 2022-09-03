class Solution {
public:
    unordered_map<char, string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> ans;
    void solve(string digit,int idx,string s){
        if(s.size()==digit.size()){
            ans.push_back(s);
        }
        for(char it:mp[digit[idx]]){
                solve(digit,idx+1,s+it);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return ans;
        solve(digits,0,"");
        return ans;
    }
};