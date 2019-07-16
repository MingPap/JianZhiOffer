

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> result;
		if (row == 0 || col == 0)
			return result;
		int left = 0, right = col - 1, up = 0, down = row - 1;
		while (left <= right&&up <= down)
		{
			for (int i = left; i <= right; ++i)
				result.push_back(matrix[up][i]);
			if (up<down)
				for (int i = up + 1; i <= down; ++i)
					result.push_back(matrix[i][right]);
			if (right>left&&up<down)
				for (int i = right - 1; i >= left; --i)
					result.push_back(matrix[down][i]);
			if (down>up + 1 && right>left)
				for (int i = down - 1; i >= up + 1; --i)
					result.push_back(matrix[i][left]);
			++left;
			--right;
			++up;
			--down;
		}
		return result;
	}
};