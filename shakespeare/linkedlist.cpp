#include "linkedlist.hpp"

LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::add_node(string word){
	Node *current = head;
	Node *prev = nullptr; 

	while (current != nullptr) {
		if (current->word == word) {
			current->count++; 
			return; 
		}
		prev = current; 
		current = current->next;
	}

	Node* new_node = new Node; 
	new_node->word = word; 
	new_node->count = 1; 
	new_node->next = nullptr; 

	if (prev == nullptr) { 
		head = new_node;
	}
	else { 
		prev->next = new_node;
	}
}

bool LinkedList::compare(Node* word_1, Node* word_2) {
	if (word_1->count > word_2->count) { 
		return true;
	}
	else if (word_1->count == word_2->count) {
		return word_1->word < word_2->word;
	}
	else {
		return false;
	}
}

// Sorts the list by frequency/alphabetical order
void LinkedList::sort() {
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* temp = nullptr;
	
	while (head != nullptr) {
		Node* current = head; 
		head = head->next; 

		if (temp == nullptr || compare(current, temp)) {
			current->next = temp; 
			temp = current; 
		}
		else {
			Node* replace = temp;

			while (replace->next && compare(replace->next, current)) { 
				replace = replace->next; 
			}
			current->next = replace->next; 
			replace->next = current; 
		}
	}
	head = temp; 
}

// Retrieves the word based on the text file
string LinkedList::find_word(int frequency) {
	Node* current = head;

	for (int i = 0; i < frequency && current; i++) { 
		current = current->next; 
	}
	if (current != nullptr) {
		return current->word; 
	}
	else {
		return "-"; 
	}
}

// Deletes list to free memory
void LinkedList::delete_list(Node* head) {
	if (head == nullptr) { 
		return;
	}
	
	delete_list(head->next); 
	delete(head);
}
