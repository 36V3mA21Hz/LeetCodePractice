class Solution {
public:
	struct brackets {
		int front;
		int back;
		int pr;
        stack<int> prStack;
		brackets() : front(0), back(0), pr(0) {}
	};
    bool isValid(string s) {
   		if (s.empty()) return true;
   		brackets curl, square, large;
   		int priority = 0;
   		for (char c : s) {
   			switch (c) {
   				case '(' :
   					priority++;
   					curl.front++;
                    curl.prStack.push(curl.pr);
   					curl.pr = priority;
   					break;
   				case '[' :
   					priority++;
   					square.front++;
                    square.prStack.push(square.pr);
   					square.pr = priority;
   					break;
   				case '{' :
   					priority++;
   					large.front++;
                    large.prStack.push(large.pr);
   					large.pr = priority;
   					break;
   				case ')' :
					curl.back++;
					if (curl.pr < square.pr || curl.pr < large.pr || curl.front < curl.back)
						return false;
					curl.front--;
					curl.back--;
					curl.pr = curl.prStack.top();
                    curl.prStack.pop();
                    priority--;
					break;
				case ']' :
					square.back++;
					if (square.pr < curl.pr || square.pr < large.pr || square.front < square.back)
						return false;
					square.front--;
					square.back--;
					square.pr = square.prStack.top();
                    square.prStack.pop();
                    priority--;
					break;
				case '}' :
					large.back++;
					if (large.pr < curl.pr || large.pr < square.pr || large.front < large.back)
						return false;
					large.front--;
					large.back--;
					large.pr = large.prStack.top();
                    large.prStack.pop();
                    priority--;
					break;
   			}
   		}
   		if (curl.front != curl.back || square.front != square.back || large.front != large.back)
   			return false;
   		return true;
    }
};
