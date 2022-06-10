class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for (char c : s) {
		if (c == '(')
			a.push(')');
		else if (c == '{')
			a.push('}');
		else if (c == '[')
			a.push(']');
		else if (a.empty() || a.top() != c)
			return false;
        else{
            a.pop();
        }    
	}
	return a.empty();
    }
};