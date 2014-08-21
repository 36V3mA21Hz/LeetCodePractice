class Solution {
	enum Directions { north, south, east, west };
public:
	void solve(vector<vector<char>> &board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] == 'O') {
					isSur(board, i, j);
				}
			}
		}
	}
	bool isSur(vector<vector<char>> &board, int y, int x) {
		if (y >= board.size() || x >= board.size() || y < 0 || x < 0)
			return false;
		if (board[y][x] == 'X' || board[y][x] == 'v')
			return true;
		board[y][x] = 'v';
		bool goNorth = isSur(board, y+1, x);
		bool goSouth = isSur(board, y-1, x);
		bool goEast = isSur(board, y, x+1);
		bool goWest = isSur(board, y, x-1);
		bool q = goNorth & goSouth & goEast & goWest;
		if (q)
			board[y][x] = 'X';
		else
			board[y][x] = 'O';
		return q;
	}
};