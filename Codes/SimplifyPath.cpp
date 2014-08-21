class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
        	return "";
        stack<string> directories;
        string temp;
        for (int i = 0; i < path.size(); i++) {
        	if (path[i] == '/' && temp.empty()) {
        		temp.push_back('/');
        	}
        	else if (path[i] == '.' && i+1 < path.size() && path[i+1] == '.') {
        		int j = i + 2;
        		while (j < path.size() && path[j] == '.') {
        			j++;
        		}
        		i = j - 1;
        		if (j < path.size() && path[j] == '/') {
        			if (!directories.empty()) 
        				directories.pop();	
        			temp.clear();
        		}         		
        	} else if (path[i] == '.' && !(i+1 < path.size() && path[i+1] == '.')) {
        		if (!directories.empty())
        			temp.clear(); 
        	} else if (path[i] != '/' && path[i] != '.') {
        		temp.push_back(path[i]);
        		directories.push(temp);
        		temp.clear();
        	}
        }
        if (directories.empty() && !temp.empty())
        	directories.push(temp);
        temp.clear();
        while (!directories.empty()) {
        	temp.append(directories.top());
        	directories.pop();
        }
        return temp;
    }
};