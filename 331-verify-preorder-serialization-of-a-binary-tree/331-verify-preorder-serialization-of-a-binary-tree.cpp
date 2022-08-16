class Solution {
public:
    bool isValidSerialization(string p) {
        if(p.size()==0)return false;
        p+=',';
        int comma=1;
        for(int i=0;i<p.size();i++){
            if(p[i]==','){
                comma--;
                if(comma<0)return false;
                if(p[i-1]!='#')comma+=2;
            }
            else{
                continue;
            }
        }
        return comma==0;
        
        
    }
};