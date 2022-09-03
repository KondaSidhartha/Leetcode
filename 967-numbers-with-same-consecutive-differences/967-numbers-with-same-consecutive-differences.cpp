class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        deque<int> q;
        q={1,2,3,4,5,6,7,8,9};
        while(--n){
            int len=q.size();
            for(int i=0;i<len;i++){
                int a=q.front();
                cout<<a<<" ";
                q.pop_front();
                for(int j=0;j<10;j++){
                    if(abs((a%10)-j)==k){
                        q.push_back(a*10+j);
                    }
                }
            }
        }
        return vector<int>(q.begin(),q.end());
    }
};