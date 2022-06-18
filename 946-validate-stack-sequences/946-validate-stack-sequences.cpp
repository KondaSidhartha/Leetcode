class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        stack<int> st;
        while(i>=j && i< pushed.size()){
            st.push(pushed[i]);
            i++;
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};