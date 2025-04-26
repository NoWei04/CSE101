#include "bfs.hpp"

int main(int argc, char* argv[]) {
	if (argc!= 3){
		return 1;
	} 

	graph g;
	g.loaddata("cleaned_movielist.txt");
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);
	std::string actor1, actor2;

	while (input >> actor1 >> actor2) {
		std::vector<std::string> path = g.findshortestpath(actor1,actor2);
		for (const auto &s : path) {
			output << s << " ";
		}
		output << "\n";
	}
	return 0;
}
