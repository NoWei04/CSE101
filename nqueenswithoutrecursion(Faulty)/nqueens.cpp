#include "nqueens.hpp"

bool isattacking(int col1, int row1, int col2, int row2) {
	return (row1 == row2) || (abs(col1-col2) == abs(row1 - row2));
}

bool isvalid(const std::vector<int>& solution, int n) {
	for (int col1 = 1; col1 <= n; col1++) {
		if (solution[col1] == 0) continue;
		for (int col2 = col1 + 1; col2 <= n; col2++) {
			if (solution[col2] == 0) continue;
			if (isattacking(col1, solution[col1], col2, solution[col2])) {
				return false;
			}
		}
	}
	return true;
}

void solve(int n, const std::vector<int>& fixed_cols, const std::vector<int>& fixed_rows, std::ofstream& outfile) {
	std::vector<int> solution(n+1,0);

	for (size_t i = 0; i < fixed_cols.size(); i++) {
		int col = fixed_cols[i];
		int row = fixed_rows[i];
		if (col < 1 || col > n || row < 1 || row > n) {
			outfile << "No solution\n";
			return;
		}
		solution[col] = row;
	}

	if (!isvalid(solution,n)) {
		outfile << "No solution\n";
		return;
	}

	int preplacedcount = 0;
	for (int col = 1; col <= n; col++) {
		if (solution[col] != 0) preplacedcount++;
	}
	if (preplacedcount == n) {
		if (isvalid(solution,n)) {
			for (int col = 1; col <= n; col++) {
				outfile << col << " " << solution[col] << " ";
			}
			outfile << "\n";
		}
		else {
			outfile << "No solution\n";
		}
		return;
	}
	if (n <= 3) {
		outfile << "No solution\n";
		return;
	}

	std::vector<int> nextrow(n+1,1);
	std::stack<int> col_stk;
	int col = 1;

	while (col <= n) {
		if (solution[col] != 0) {
			col++;
			continue;
		}

		bool found = false;
		for (int row = nextrow[col]; row <= n; row++) {
			bool safe = true;
			for (int prev = 1; prev <= n; prev++) {
				if (prev == col || solution[prev] == 0) continue;
				if (isattacking(prev, solution[prev], col,row)) {
					safe = false;
					break;
				}
			}
			
			if (safe) {
				solution[col] = row;
				nextrow[col] = row + 1;
				col_stk.push(col);
				found = true;
				break;
			}
		}

		if (found) {
			col++;
		}
		else {
			nextrow[col] = 1;
			solution[col] = 0;
			if (col_stk.empty()) {
				outfile << "No solution\n";
				return;
			}
			col = col_stk.top();
			col_stk.pop();
			solution[col] = 0;
		}
	}
	for (int c = 1; c <= n; c++) {
		outfile << c << " " << solution[c] << " ";
	}
	outfile << "\n";
}
