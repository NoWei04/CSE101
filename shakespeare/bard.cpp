#include "linkedlist.hpp"

int main(int argc, char* argv[]) {
	string input = argv[1]; 
	string output = argv[2];

	int len;
	int rank;
	string word; 
	ifstream shakespeare("shakespeare-cleaned5.txt"); 
	LinkedList list[50]; // Allocates memory for a word (max word length is 50)

	while (shakespeare >> word) {
		int len = word.length(); 
		list[len].add_node(word);
	}

	shakespeare.close();

	for (int i = 0; i < 50; i++) { 
		list[i].sort(); 
	}

	ifstream inputFileStream(input); 
	ofstream outputFileStream(output);

	while (inputFileStream >> len >> rank) {
		if (len < 50) { // Checks if the word is len 50 or less
			outputFileStream << list[len].find_word(rank) << endl; // Outputs the word of kth frequency
		}
		else {
			outputFileStream << "-" << endl; // Handles edgecase of nonexistant word
		}
	}

	inputFileStream.close();
	outputFileStream.close();
	return 0;
}
