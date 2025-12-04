#include <iostream>
#include <cassert>
using namespace std;
template <class T>
class BinarySearchTree {
	struct Node {
		T item;
		Node* right;
		Node* left;
	};
	Node* root;

public:

	BinarySearchTree() {
		root = NULL;
	}

	bool isEmpty() {
		return root == NULL;
	}

	void height() {
		cout << "Tree height = " << treeHeight(root) << endl;
	}

	void nodeCount() {
		cout << "Tree nodes = " << treeNodes(root) << endl;
	}

	void leavesCount() {
		cout << "Tree leaves = " << treeLeaves(root) << endl;
	}

	void pre_orderTraversal() {
		pre_order(root);
		cout << endl;
	}

	void in_orderTraversal() {
		in_order(root);
		cout << endl;
	}

	void post_orderTraversal() {
		post_order(root);
		cout << endl;
	}

	void clear() {
		clearTree(root);
	}

	~BinarySearchTree() {
		clearTree(root);
	}

	void insert(T item) {
		Node* curr=NULL;
		Node* trailCurr=NULL;
		Node* newNode= new Node;
		assert(newNode != NULL);
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		if (isEmpty())
			root = newNode;
		else {
			curr = root;
			while (curr != NULL) {
				trailCurr = curr;
				if (item > curr->item)
					curr = curr->right;
				else
					curr = curr->left;
			}
			if (item > trailCurr->item)
				trailCurr->right = newNode;
			else 
				trailCurr->left = newNode;
		}
	}

	void insertWithoutDuplicate(T item) {
		Node* curr=NULL;
		Node* trailCurr=NULL;
		Node* newNode = new Node;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		if (isEmpty())
			root = newNode;
		else {
			curr = root;
			while (curr != NULL) {
				trailCurr = curr;
				if (curr->item == item) {
					cout << "Element " << item << " is already in the tree\nduplicate not allowed\n";
					return;
				}
				else if (item > curr->item)
					curr = curr->right;
				else if (item <= curr->item)
					curr = curr->left;
			}
			if (trailCurr->item < item)
				trailCurr->right = newNode;
			else if (item <= trailCurr->item)
				trailCurr->left = newNode;
		}
	}
	
	void search(T item) {
		if (searchItem(item))
			cout << "Element " << item << " Found\n";
		else
			cout << "Element " << item << " NOT Found\n";
	}
	
	void deleteElement(T item) {
		if (isEmpty()) {
			cout << "Tree is already Empty!\n";
			return;
		}
		else if (root->item == item)
			deleteFromTree(root);
		else {
			Node* curr;
			Node* trailCurr=root;
			if (item > trailCurr->item)
				curr = root->right;
			else
				curr = root->left;
			while (curr != NULL) {
				if (curr->item == item)
					break;
				else if (item > curr->item) {
					trailCurr = curr;	
					curr = curr->right;
				}
				else {
					trailCurr = curr;
					curr = curr->left;
				}
			}
			if (curr == NULL)
				cout << "Element is Not Found in the tree\n";
			else if (item > trailCurr->item)
				deleteFromTree(trailCurr->right);
			else
				deleteFromTree(trailCurr->left);
		}
	}

private:

	void pre_order(Node* curr) {
		if (curr != NULL) {
			cout << curr->item << " ";
			pre_order(curr->left);
			pre_order(curr->right);
		}
	}

	void in_order(Node* curr) {
		if (curr != NULL) {
			in_order(curr->left);
			cout << curr->item << " ";
			in_order(curr->right);
		}
	}

	void post_order(Node* curr) {
		if (curr != NULL) {
			post_order(curr->left);
			post_order(curr->right);
			cout << curr->item << " ";
		}

	}

	void clearTree(Node* &curr) {
		if (curr != NULL) {
			clearTree(curr->left);
			clearTree(curr->right);
			delete curr;
			curr = NULL;
		}
	}

	int treeHeight(Node* curr) {
		if (curr == NULL)
			return 0;
		else
			return 1 + max(treeHeight(curr->left), treeHeight(curr->right));
	}

	int treeNodes(Node* curr) {
		if (curr == NULL)
			return 0;
		else
			return 1 + treeNodes(curr->left) + treeNodes(curr->right);
	}

	int treeLeaves(Node* curr) {
		if (curr == NULL)
			return 0;
		else if (curr->left == NULL && curr->right == NULL)
			return 1;
		else
			return treeLeaves(curr->left) + treeLeaves(curr->right);
	}

	bool searchItem(T item) {
		Node* curr = root;
		while (curr != NULL) {
			if (curr->item == item)
				return 1;
			else if (item > curr->item)
				curr = curr->right;
			else
				curr = curr->left;
		}
		return 0;
	}

	void deleteFromTree(Node* &ptr) {
		Node* curr;
		Node* trailCurr;
		Node* temp;
		if (ptr->left == NULL && ptr->right == NULL) {
			delete ptr;
			ptr = NULL;
		}
		else if (ptr->left == NULL) {
			temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
		else if (ptr->right ==  NULL) {
			temp = ptr;
			ptr = ptr->left;
			delete temp;
		}
		else {
			curr = ptr->left;
			trailCurr = NULL;
			while (curr->right != NULL) {
				trailCurr = curr;
				curr = curr->right;
			}
			ptr->item = curr->item;
			if (trailCurr == NULL)
				ptr->left = curr->left;
			else
				trailCurr->right = curr->left;
			delete curr;
		}
	}

};

int main()
{
	BinarySearchTree<int> bst;
	bst.insert(4);
	bst.insert(5);
	bst.insert(3);
	bst.insert(4);
	bst.insert(5);
	bst.insert(2);
	bst.insert(1);
	bst.insertWithoutDuplicate(4);
	bst.insertWithoutDuplicate(7);
	bst.insertWithoutDuplicate(3);
	bst.insertWithoutDuplicate(6);
	/*
							|4|
					|3|			  	  |5|
				|2|		|4|		|5|			|7|
			|1|							|6|
	*/
	//bst.clear();
	bst.pre_orderTraversal();
	bst.in_orderTraversal();
	bst.post_orderTraversal();
	bst.search(4);
	bst.search(9);
	bst.height();
	bst.nodeCount();
	bst.leavesCount();
	bst.deleteElement(4);
	bst.deleteElement(5);
	bst.deleteElement(4);
	bst.deleteElement(5);
	/*
						|3|			  	  
				|2|				|7|
			|1|				|6|
	*/
	cout << endl;
	bst.pre_orderTraversal();
	bst.in_orderTraversal();
	bst.post_orderTraversal();
	bst.search(4);
	bst.search(9);
	bst.height();
	bst.nodeCount();
	bst.leavesCount();
}