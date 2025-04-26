#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct Node {
	string word;
	int count;
	struct Node* next;
} Node;

class LinkedList {
	public:
		Node *head;
		LinkedList();
		void add_node(string word);
		void sort();
		string find_word(int frequency);
		void delete_list(Node* head);
	private:
		bool compare(Node* word_1, Node* word_2);
};
