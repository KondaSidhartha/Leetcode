class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int points=0;
        int i=0;
        int j=tokens.size()-1;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                ans=max(ans,++points);
            }
            else if(points>0){
                power+=tokens[j];
                j--;
                points--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};