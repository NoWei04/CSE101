#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

class graph{
public:
	void loaddata(const std::string& filename);
	std::vector<std::string> findshortestpath(const std::string &actor1, const std::string &actor2);

private:
	std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> adjlist;
};
