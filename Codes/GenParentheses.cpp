class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	if (n == 0) return {};
    	vector<string> output;
    	string s;
    	stack<string> temp;
    	gpAux(n, 0, s, output, temp);
    	return output;
    }
	void gpAux(int openStock, int closeStock, string &s, vector<string> &buffer, stack<string> &temp) {
	    if (openStock == 0 && closeStock == 0) {
	        buffer.push_back(s);
	    }
	    if (openStock > 0) {
	        temp.push(s);
	        s.push_back('(');
	        gpAux(openStock - 1, closeStock + 1, s, buffer, temp);
	        s = temp.top();
	        temp.pop();
	    }
	    if (closeStock > 0) {
	        temp.push(s);
	        s.push_back(')');
	        gpAux(openStock, closeStock - 1, s, buffer,temp);
	        s = temp.top();
	        temp.pop();
	    }
	}
};