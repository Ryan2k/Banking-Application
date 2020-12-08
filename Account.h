#pragma once
#include<iostream>
#include<vector>
#include "Transaction.h"
#include "Fund.h"
using namespace std;

class Account {
	private:
		string firstName;
		string lastName;
		int ID;

	public:
		vector<vector<Transaction> > transactions;
		vector<Fund> funds;
		Account(string first, string last, int id);
		Account();

		int getID();

		void deposit(int fundID, int transactionVal);

		void withdrawl(int fundID, int transactionVal);
		
		void Print();
};
