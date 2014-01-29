#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
   		if (matrix.empty()) return;
        
   		int m = (int)matrix.size();
   		int n = (int)matrix[0].size();
   		int iStore, jStore, addStore;
        int reRow = 0, reColumn = 0;
   		bool replacement = false;
   		bool storeLineColumn = true;
   		for (int i = 0; i < m; i++) {
   			for (int j = 0; j < n; j++) {
   				if (matrix[i][j] == 0 && storeLineColumn) {
   					iStore = i;
   					jStore = j;
                    matrix[iStore][reColumn++] = j;
                    matrix[reRow++][jStore] = i;
   					replacement = true;
   					storeLineColumn = false;
   				} else if (matrix[i][j] == 0) {
                    if (reRow != reColumn) {
                        matrix[iStore][reColumn++] = j != matrix[iStore][reColumn] ? : j;
                        matrix[reRow++][jStore] = i != matrix[reRow++][jStore] ? : i;
                    } else {
                        matrix[iStore][reColumn++] = j != matrix[iStore][reColumn] ? : j;
                        addStore = i;
                        reRow++;
                    }
   				}
   			}
   		}
        int reM = reRow, reN = reColumn;
   		if (replacement) {
   			int iRepl, jRepl, reRow = 0, reColumn = 0;
   			while (reRow < reM && reColumn < reN) {
                if (reColumn != reRow) {
                    iRepl = matrix[reRow++][jStore];
                    jRepl = matrix[iStore][reColumn++];
                } else {
                    jRepl = matrix[iStore][reColumn++];
                    iRepl = addStore;
                    reRow++;
                }
   				if (iRepl != iStore && jRepl != jStore) {
	   				for (int i = 0; i < m; i++) {
                        if (i == iStore) continue;
	   					matrix[i][jRepl] = 0;
                    }
	   				for (int j = 0; j < n; j++) {
                        if (j == jStore) continue;
	   					matrix[iRepl][j] = 0;
                    }
	   			}
   			}
   			for (int i = 0; i < m; i++)
				matrix[i][jStore] = 0;
			for (int j = 0; j < n; j++)
				matrix[iStore][j] = 0;
	   	}
    }
};

int main() {
    vector<vector<int>> matrix = {{0,0,5,8,3,8},{9,4,1,9,9,5},{0,4,3,0,2,7},{1,6,0,0,3,0},{4,4,0,3,3,7},{0,3,7,5,1,0}};

    Solution s;
    s.setZeroes(matrix);
	return 0;
}