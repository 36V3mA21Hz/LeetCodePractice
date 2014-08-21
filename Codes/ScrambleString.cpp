class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty())
            return true;
        int n = s1.size();
        queue<pair<int, int> > q;
        vector<string> scrambleStr;
        q.push({ 0, n - 1 });
        string scrS = scramble(s1, 0, n - 1);
        if (scrS == s2)
            return true;
        scrambleStr.push_back(s1);
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            int nodeSize = scrambleStr.size();
            for (int i = 0; i < nodeSize; i++) {
                scrS = scramble(scrambleStr[i], t.first, t.second);
                if (scrS == s2)
                    return true;
                scrambleStr.push_back(scrS);
            }
            if (t.first < t.second) {
                int mid = (t.first + t.second) / 2;
                if ((t.first + t.second) % 2)
                    mid++;
                if (t.first < mid - 1)
                    q.push({ t.first, mid - 1 });
                if (mid < t.second)
                    q.push({ mid, t.second });
            }
        }
    }
    string scramble(string s, int i, int j) {
        int mid = (i + j) / 2;
        if ((i + j) % 2)
            mid++;
        string temp = s.substr(mid, j - mid + 1);
        temp.append(s, i, mid - i);
        string output = s.substr(0, i);
        output.append(temp);
        output.append(s, j + 1, s.size() - j - 1);
        return output;
    }
};