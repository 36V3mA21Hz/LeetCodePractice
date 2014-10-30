class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    	queue<string> q;
    	vector<vector<string> > output;
        int length = 1;
        q.push(start);
        q.push("0");
        while(!q.empty()) {
             string temp = q.front();
             q.pop();
             if (temp == "0") {
                  length++;
                  if (!q.empty()) {
                       q.push("0");
                       continue;
                  }
                  else break;
             }
             int diffNow = diffWords(temp, end);
             if (diffNow == 0) return length;
             if (diffNow == 1) return length + 1;
             for (int j = 0; j < start.size(); j++) {
                  char restore = temp[j];
                  for (int i = 0; i < 26; i++) {
                       temp[j] = 'a' + i;
                       auto got = dict.find(temp);
                       if (got != dict.end()) {
                            if ('a' + i != restore) q.push(*got);
                            dict.erase(got);
                       }
                  }
                  temp[j] = restore;
             }
        }
        return 0;
    }
    int diffWords(string s1, string s2) {
         int diff = 0;
         for (int i = 0; i < s1.size(); i++) {
              if (s1[i] != s2[i]) diff++;
         }
         return diff;
    }
};