#pragma once
#include<iostream>
#include "Account.h"
using namespace std;

//This class represents the binary search tree I am going to use to store all of the currently open accounts.
//These accounts will be ordered by value of account ID
class AccountDataBase {
	private:
		struct Node {
			Account *pACC;
			Node* left;
			Node* right;
		};
		Node* root;

	public:
		AccountDataBase();

		~AccountDataBase();

		//searches through binary tree and places account in correct place comparing account ID's with all smaller to the left and larget to the right.
		bool insert(Node*& parent, Account* val);
		bool insert(Account* val);
		int getAccountID(Account acc);
		//Seperated the return for account and if it exists because I need just a boolean for error checks within the creating of each
		//transaction in the driver class.
		bool doesAccountExist(const int accountIdentity) const;
		//this is the main retrieve function, first parameter is the ID of the account we are trying to retrieve
		//Second parameter holds pointer to found object, NULL if not found and returns false
		bool retrieve(const int& accountIdentity, Account*& acc)const;

		Account getAccount(const int& accountIdentity);

		//Checks to see if the tree is empty. If the root node is null that means there are no nodes at all meaning true should be returned
		bool isEmpty();

		//Displays contents of a tree to cout
		//Inorder traversal calling print on each account 
		//Done in order because it prints it by order of account ID from smallest to largest
		void Display() const;

		//Helper function for display to do the actual traversal
		void traversal(Node* node) const;

		//Empties the AccountDataBase tree esentially removing all active accounts
		void Empty();

		void emptyHelper(Node* node);

};
