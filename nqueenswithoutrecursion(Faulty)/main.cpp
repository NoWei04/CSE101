#include "nqueens.hpp"

int main (int argc, char* argv[]) {
	if (argc != 3) {
		return 1;
	}

	ifstream inputfile(argv[1]);
	ofstream outputfile(argv[2]);

	if (!inputfile.is_open() || !outputfile.is_open()) {
		return 1;
	}

	std::string line;
	while (std::getline(inputfile, line)) {
		std::istringstream iss(line);
		int n;
		iss >> n;
		
		std::vector<int> fixed_cols, fixed_rows;
		int col, row;
		while (iss >> col >> row) {
			fixed_cols.push_back(col);
			fixed_rows.push_back(row);
		}

		solve(n,fixed_cols,fixed_rows,outputfile);
	}
	inputfile.close();
	outputfile.close();
	return 0;
}
