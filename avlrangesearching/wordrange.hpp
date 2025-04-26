#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node {
	std::string key;
	int height;
	int subtree_size;
	Node* left;
	Node* right;

	Node(std::string k) : key(k), height(1), subtree_size(1), left(nullptr), right(nullptr) {}
};

class avl {
public:
	avl();
	~avl();
	void insert(const std::string& key);
	int rangequery(const std::string& low, const std::string& high);

private:
	Node* root;
	Node* insert(Node* node, const std::string& key);
	int getheight(Node* node);
	int getsubtreesize(Node* node);
	bool find(Node* node, const std::string& key);
	void updatenode(Node* node);
	Node* rotateright(Node* y);
	Node* rotateleft(Node* x);
	Node* balance(Node* node);
	int countlessthan(Node* node, const std::string& key);
	int countgreaterthan(Node* node, const std::string& key);
	Node* findlca(Node* node, const std::string& low, const std::string& high);
	void destroytree(Node* node);

};
