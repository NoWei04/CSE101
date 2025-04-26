#include <vector>
#include <stack>
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

bool isattacking(int col1, int row1, int col2, int row2);
bool isvalid(const std::vector<int>& solution, int n);
void solve(int n, const std::vector<int>& fixed_cols, const std::vector<int>& fixed_rows, std::ofstream& outfile);
