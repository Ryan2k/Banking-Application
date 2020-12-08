#pragma once
#include "Account.h"

Account::Account(string first, string last, int id) {
	this->firstName = first;
	this->lastName = last;
	this->ID = id;
	this->transactions = {};
	for (int i = 0; i < 10; i++) {
		funds.push_back(0);
		vector<Transaction> newTransaction;
		transactions.push_back(newTransaction);
	}
}
Account::Account() {

}

int Account::getID() {
	return this->ID;
}

void Account::deposit(int fundID, int transactionVal) {
	this->funds[fundID] += transactionVal;
}

void Account::withdrawl(int fundID, int transactionVal) {
	if (fundID == 1 || fundID == 0) {
		if ((transactionVal * -1) < funds[fundID].getBalance()) {
			this->funds[fundID] += transactionVal;
		}
		else if ((transactionVal * -1) > (funds[0].getBalance() + funds[1].getBalance())) {
			cerr << "Not Enough Money in Balance to Withdrawl" << endl;
		}
		else if (fundID == 0) {
			funds[1] = funds[1] + (Fund(transactionVal) + funds[0]);
			funds[0] = 0;
		}
		else {
			funds[0] = funds[0] + (Fund(transactionVal) + funds[1]);
			funds[1] = 0;
		}
	}
	else if (fundID == 2 || fundID == 3) {
		if ((transactionVal * -1) < funds[fundID].getBalance()) {
			this->funds[fundID] += transactionVal;
		}
		else if ((transactionVal * -1) > (funds[2].getBalance() + funds[3].getBalance())) {
			cerr << "Not Enough Money in Balance to Withdrawl" << endl;
		}
		else if (fundID == 2) {
			funds[3] = funds[3] + (Fund(transactionVal) + funds[2]);
			funds[2] = 0;
		}
		else {
			funds[2] = funds[2] + (Fund(transactionVal) + funds[3]);
			funds[3] = 0;
		}
	}
	else if (transactionVal < (funds[fundID].getBalance() * -1)) {
		cerr << "Not Enough Money in Balance to Withdrawl" << endl;
	}
	else {
		this->funds[fundID] += transactionVal;
	}
}
//Prints out all information about the account in seperate lines.
void Account::Print() {
	cout << "Account Holder: " << this->firstName << " " << this->lastName << endl;
	cout << "Account Number: " << this->ID << endl;
	cout << "Money Market Holds: $" << this->funds[0].getBalance() << endl;
	cout << "Prime Money Market Holds: $" << this->funds[1].getBalance() << endl;
	cout << "Long-Term Bond Holds: $" << this->funds[2].getBalance() << endl;
	cout << "Short-Term Bonds HOlds: $" << this->funds[3].getBalance() << endl;
	cout << "500 Index Fund Holds: $" << this->funds[4].getBalance() << endl;
	cout << "Capital Value Fund Holds: $" << this->funds[5].getBalance() << endl;
	cout << "Growth Equity Fund Holds: $" << this->funds[6].getBalance() << endl;
	cout << "Growth Index Fund Holds: $" << this->funds[7].getBalance() << endl;
	cout << "Value Fund Holds: $" << this->funds[8].getBalance() << endl;
	cout << "Value Stock Index Holds: $" << this->funds[9].getBalance() << endl;
}
