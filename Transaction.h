#pragma once
#include<iostream>
#include<vector>
#include <string>
using namespace std;

class Transaction {
	private:
		int transactionAmount;
		int accountID;
		int fundID;
		string firstName;
		string lastName;
		char transactionType;
		string failure;

		//These two only are set if there is a transfer between two accounts. 
		//The accID2 and fundID2 are the ID's of the account we are depositing money into
		int accID2;
		int fundID2;

	public:
		Transaction(string first, string last, int id);
		
		Transaction(int acID, int fID, int depositVal);
		
		Transaction(int acID1, int fID1, int transferVal, int acID2, int fID2);
		
		Transaction(int acID, int fID);

		char getTransactionType();

		int getAccountID();

		int getFundID();

		int getTransactionAmount();

		int getAccountID2();

		int getFundID2();

		string getFirst();

		string getLast();
		
		string getFailure();

		void setFailure(string s);

		void Print();
};
