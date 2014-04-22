class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty())
        	return 0;
        stack<int> temp;
        for (auto it = tokens.begin(); it != tokens.end(); it++) {
        	if (*it == "+") {
        		int x = temp.top();
        		temp.pop();
        		int y = temp.top();
        		temp.pop();
        		temp.push(y + x);
        	} else if (*it == "-") {
	    		int x = temp.top();
	    		temp.pop();
	    		int y = temp.top();
	    		temp.pop();
	    		temp.push(y - x);
	    	} else if (*it == "*") {
	    		int x = temp.top();
	    		temp.pop();
	    		int y = temp.top();
	    		temp.pop();
	    		temp.push(y * x);
	    	} else if (*it == "/") {
	    		int x = temp.top();
	    		temp.pop();
	    		int y = temp.top();
	    		temp.pop();
	    		temp.push(y / x);
	    	} else {
        		temp.push(stoi(*it, nullptr));
        	}
        }
        return temp.top();
    }
};
