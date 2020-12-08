#include "Transaction.h"

//constructor for type "O" which means open an account
Transaction::Transaction(string first, string last, int id) {
	this->transactionType = 'O';
	this->firstName = first;
	this->lastName = last;
	this->accountID = id;
}

/*Constructor for withdrawl and deposit. In the driver it will take in the depositVal and set it to 
* negative if the type is W
*/
Transaction::Transaction(int acID, int fID, int depositVal) {
	this->accountID = acID;
	this->fundID = fID;
	this->transactionAmount = depositVal;
	if (depositVal >= 0) {
		this->transactionType = 'D';
	}
	else {
		this->transactionType = 'W';
	}
}

/*Constructor for transfer transaction
* This is the only case where acID2 and fID2 are initialized as there needs to be a fund for the money to transfer to
*/
Transaction::Transaction(int acID1, int fID1, int transferVal, int acID2, int fID2) {
	this->transactionType = 'T';
	this->accountID = acID1;
	this->fundID = fID1;
	this->accID2 = acID2;
	this->fundID2 = fID2;
	this->transactionAmount = transferVal;
}

/*Constructor for History transaction. Takes in account id as well as fund ID. If fund ID is -1, that means none was given and i it was places as -1 in the driver
		 This means that we should print out all transactions for all funds in the given account*/
Transaction::Transaction(int acID, int fID) {
	this->transactionType = 'H';
	this->accountID = acID;
	this->fundID = fID;
}

char Transaction::getTransactionType() {
	return this->transactionType;
}

int Transaction::getAccountID() {
	return this->accountID;
}

int Transaction::getFundID() {
	return this->fundID;
}

int Transaction::getTransactionAmount() {
	return this->transactionAmount;
}

int Transaction::getAccountID2() {
	return this->accID2;
}

int Transaction::getFundID2() {
	return this->fundID2;
}

string Transaction::getFirst() {
	return this->firstName;
}

string Transaction::getLast() {
	return this->lastName;
}

string Transaction::getFailure() {
	return this->failure;
}

void Transaction::setFailure(string s) {
	this->failure = s;
}

//Depending on the type of transaction prints out a line with all of the details to cout when called upon
void Transaction::Print() {
	if (this->transactionType == 'D') {
		cout << "Deposit $" << this->transactionAmount << " to account " << this->accountID << " fund " << this->fundID << endl;
	}
	if (this->transactionType == 'W') {
		cout << "Withdrew $" << this->transactionAmount * -1 << " from account " << this->accountID << " fund " << this->fundID << endl;
	}
	if (this->transactionType == 'O') {
		cout << "Opened account " << this->accountID << " for " << this->firstName << " " << this->lastName << endl;
	}
	if (this->transactionType == 'T') {
		cout << "Transfered $" << this->transactionAmount << " from account " << this->accountID << " fund " << this->fundID << " to " <<
			this->accID2 << " fund " << this->fundID2 << endl;
	}
	if (this->failure != "") {
		cout << this->failure << endl;
	}
}