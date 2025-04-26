#include "wordrange.hpp"

avl::avl(): root(nullptr) {}

avl::~avl() {
	destroytree(root);
}

void avl::destroytree(Node* node) {
	if (node) {
		destroytree(node->left);
		destroytree(node->right);
		delete node;
	}
}

int avl::getheight(Node* node) {
	return node ? node->height : 0;
}

int avl::getsubtreesize(Node* node) {
	return node ? node->subtree_size : 0;
}

bool avl::find(Node* node, const std::string& key) {
	if (!node) return false;
	if (node->key == key) return true;
	return key < node->key ? find(node->left, key) : find(node->right, key);
}

void avl::updatenode(Node* node) {
	if (node) {
		node->height = std::max(getheight(node->left), getheight(node->right)) + 1;
		node->subtree_size = getsubtreesize(node->left) + getsubtreesize(node->right) + 1;
	}
}

Node* avl::rotateright(Node* y) {
	Node* x = y->left;
	y->left = x->right;
	x->right = y;

	updatenode(y);
	updatenode(x);
	return x;
}

Node* avl::rotateleft(Node* x) {
	Node* y = x->right;
	x->right = y->left;
	y->left = x;

	updatenode(x);
	updatenode(y);
	return y;
}

Node* avl::balance(Node* node) {
	if (!node) return nullptr;

	updatenode(node);
	int balancefactor = getheight(node->left) - getheight(node->right);

	if (balancefactor > 1) {
		if (node->left && getheight(node->left->right) > getheight(node->left->left)) {
			node->left = rotateleft(node->left);
		}
		return rotateright(node);
	}

	if (balancefactor < -1) {
		if (node->right && getheight(node->right->left) > getheight(node->right->right)) {
			node->right = rotateright(node->right);
		}
		return rotateleft(node);
	}
	return node;
}

Node* avl::insert(Node* node, const std::string& key) {
	if (key.empty()) return node;

	if (!node) return new Node(key);

	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}
	else {
		return node;
	}

	updatenode(node);
	return balance(node);
}

void avl::insert(const std::string& key) {
	root = insert(root, key);
}

int avl::countlessthan(Node* node, const std::string& key) {
	if (!node) return 0;

	if (key < node->key) {
		return countlessthan(node->left, key);
	}
	return getsubtreesize(node->left) + countlessthan(node->right, key) + 1;
}

int avl::countgreaterthan(Node* node, const std::string& key) {
	if (!node) return 0;

	if (key > node->key) {
		return countgreaterthan(node->right, key);
	}
	return getsubtreesize(node->right) + countgreaterthan(node->left, key) + 1;
}

Node* avl::findlca(Node* node, const std::string& low, const std::string& high) {
	if (!node) return nullptr;

	if (node->key < low) {
		return findlca(node->right, low, high);
	}
	if (node->key > high) {
		return findlca(node->left, low, high);
	}
	return node;
}

int avl::rangequery(const std::string& low, const std::string& high) {
	if (!root || low > high) return 0;
	Node* lca = findlca(root, low, high);
	if (!lca) return 0;

	int countleft = (lca->left) ? countgreaterthan(lca->left, low) : 0;
	int countright = (lca->right) ? countlessthan(lca->right, high) : 0;

	return countleft + countright + 1;
}
