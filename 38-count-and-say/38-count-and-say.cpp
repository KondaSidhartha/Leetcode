class Solution {
public:
    string countAndSay(int n) {
        string s;
        string p="1";
        while(--n){
            int i=0;
            while(i<p.size()){
                char ch=p[i];
                int count=0;
                while(i<p.size() && p[i]==ch){
                    count++;
                    i++;
                }
                s+=(to_string(count))+ch; 
            }
            p=s;
            s="";
        }             
     return p;
}
};