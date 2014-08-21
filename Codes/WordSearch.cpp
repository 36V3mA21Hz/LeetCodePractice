class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (word == "")
			return true;
		bool q = false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (findLetters(board, word, 0, i, j)) 
					return true;
			}
		}
		return q;
	}
	bool findLetters(vector<vector<char> > &board, string word, int pos, int y, int x) {
		if (x < 0 || x >= board[0].size() || y < 0 || y >= board.size())
			return false;
		if (board[y][x] != word[pos] || board[y][x] == '#')
			return false;
		if (pos == word.size() - 1) 
			return true;
		char temp = board[y][x];
		board[y][x] = '#';
		bool q = false;
		if (findLetters(board, word, pos + 1, y + 1, x)) 
			q = true;
		else if (findLetters(board, word, pos + 1, y - 1, x))
			q = true;
		else if (findLetters(board, word, pos + 1, y, x + 1))
			q = true;
		else if (findLetters(board, word, pos + 1, y, x - 1))
			q = true;
		board[y][x] = temp;
		return q;
	}
};