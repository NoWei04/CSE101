#include "wordrange.hpp"

int main (int argc, char* argv[]) {
	if (argc != 3) {
		return 0;
	}

	std::ifstream inputfile(argv[1]);
	std::ofstream outputfile(argv[2]);

	if (!inputfile || !outputfile) {
		return 0;
	}

	avl tree;
	std::string command, word1, word2;

	while (inputfile >> command) {
		if (command == "i") {
			inputfile >> word1;
			tree.insert(word1);
		}
		else if (command == "r") {
			inputfile >> word1 >> word2;
			outputfile << tree.rangequery(word1,word2) << endl;
		}
	}

	inputfile.close();
	outputfile.close();
	return 0;
}
