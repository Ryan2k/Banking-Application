#include "AccountDataBase.h"

AccountDataBase::AccountDataBase() {
	this->root = NULL;
}

AccountDataBase::~AccountDataBase() {
	Empty();
}

//searches through binary tree and places account in correct place comparing account ID's with all smaller to the left and larget to the right.
bool AccountDataBase::insert(Node*& parent, Account* val) {
	if (parent == NULL) {
		parent = new Node();
		parent->pACC = val;
		return true;
	}
	else if (val->getID() == parent->pACC->getID()) {
		return false;
	}
	else if (val->getID() > parent->pACC->getID()) {
		return insert(parent->right, val);
	}
	else {
		return insert(parent->left, val);
	}
}
bool AccountDataBase::insert(Account* val) {
	return insert(root, val);
}
int AccountDataBase::getAccountID(Account acc) {
	//placeholder is 0, i want to return the id after searching the tree to see if it exists.
	return 0;
}
//Seperated the return for account and if it exists because I need just a boolean for error checks within the creating of each
//transaction in the driver class.
bool AccountDataBase::doesAccountExist(const int accountIdentity) const {
	Node* node = root;
	if (node == NULL) {
		return false;
	}

	while (node != NULL) {
		if (accountIdentity < node->pACC->getID()) {
			node = node->left;
		}
		else if (accountIdentity > node->pACC->getID()) {
			node = node->right;
		}
		else {	//if account identity matches the identity of the account at the node the account exists
			return true;
		}
	}
	return false;
}

//this is the main retrieve function, first parameter is the ID of the account we are trying to retrieve
//Second parameter holds pointer to found object, NULL if not found and returns false
bool AccountDataBase::retrieve(const int& accountIdentity, Account*& acc) const {
	Node* node = root;
	if (node == NULL) {
		return false;
	}

	while (node != NULL) {
		if (accountIdentity < node->pACC->getID()) {
			node = node->left;
		}
		else if (accountIdentity > node->pACC->getID()) {
			node = node->right;
		}
		else {	//if account identity matches the identity of the account at the node the account exists
			acc = node->pACC;
			return true;
		}
	}
	return false;

}

Account AccountDataBase::getAccount(const int& accountIdentity) {
	Node* node = root;
	while (node != NULL) {
		if (accountIdentity < node->pACC->getID()) {
			node = node->left;
		}
		else if (accountIdentity > node->pACC->getID()) {
			node = node->right;
		}
		else {	//if account identity matches the identity of the account at the node the account exists
			return *node->pACC;
		}
	}
}

//Checks to see if the tree is empty. If the root node is null that means there are no nodes at all meaning true should be returned
bool AccountDataBase::isEmpty() {
	if (root == NULL) {
		return true;
	}
	return false;
}

//Displays contents of a tree to cout
//Inorder traversal calling print on each account 
//Done in order because it prints it by order of account ID from smallest to largest
void AccountDataBase::Display() const {
	Node* node = new Node;
	node = root;
	traversal(node);
}

//Helper function for display to do the actual traversal
void AccountDataBase::traversal(Node* node) const {
	if (node == NULL) {
		return;
	}

	traversal(node->left);

	Account acc = *node->pACC;
	acc.Print();
	cout << " " << endl;

	traversal(node->right);
}

//Empties the AccountDataBase tree esentially removing all active accounts
void AccountDataBase::Empty() {
	if (root == NULL) {
		return;
	}
	Node* node = root;
	emptyHelper(node);
}

void AccountDataBase::emptyHelper(Node* node) {
	if (node->left != NULL) {
		emptyHelper(node->left);
	}
	if (node->right != NULL) {
		emptyHelper(node->right);
	}
	delete node->pACC;
	delete node;
	node = NULL;
}