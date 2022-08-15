class Solution {
public:
    int romanToInt(string s) {
        if(s.empty())return 0;
        unordered_map<char, int> mp = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int sum=mp[s[s.size()-1]];
        for(int i=s.size()-2;i>=0;i--){
            if(mp[s[i]]<mp[s[i+1]])sum-=mp[s[i]];
            else sum+=mp[s[i]];
        }
        
        return sum;
        
    }
};