#include "Driver.h"
using namespace std;

int main(int argc, char* argv[]) {
	Driver driver;
	queue<Transaction> que = driver.BuildTransactions(argv[1]);
	driver.runTransactions(que);
	return 0;
}

/*Takes in a file name as a string and builds a que of transactions. Each line read in from file is a seperate transaction and the first character in each line
* Will represent the type of transaction that is going to be built. There are constructors for each of the 5 transaction types in the transaction class.*/
queue<Transaction> Driver::BuildTransactions(string fileName) {
	queue<Transaction> Que;
	ifstream inFile;
	inFile.open(fileName);

	if (inFile.is_open()) {
		while (!inFile.eof()) {
			char itemType;
			inFile >> itemType;
			if (itemType == 'O') {
				string digits;
				string first;
				string last;

				inFile >> last;
				inFile >> first;
				inFile >> digits;
				int accountID = atoi(digits.c_str());
				Transaction openAcc(first, last, accountID);
				Que.push(openAcc);
			}
			else if (itemType == 'D') {
				string accID;
				string fundID;
				string depositVal;

				inFile >> accID;
				inFile >> depositVal;

				fundID = accID.substr(4);
				accID = accID.substr(0, 4);

				int numACCID = atoi(accID.c_str());
				int numFundID = atoi(fundID.c_str());
				int numDepositVal = atoi(depositVal.c_str());
				Transaction depo(numACCID, numFundID, numDepositVal);
				Que.push(depo);
			}
			else if (itemType == 'W') {
				string accID;
				string fundID;
				string depositVal;

				inFile >> accID;
				inFile >> depositVal;

				fundID = accID.substr(4);
				accID = accID.substr(0, 4);

				int numACCID = atoi(accID.c_str());
				int numFundID = atoi(fundID.c_str());
				int numDepositVal = atoi(depositVal.c_str());
				numDepositVal *= -1;
				Transaction depo(numACCID, numFundID, numDepositVal);
				Que.push(depo);
			}
			else if (itemType == 'T') {
				string accID1;
				string fundID1;
				string depositVal;
				string accID2;
				string fundID2;

				inFile >> accID1;
				inFile >> depositVal;
				inFile >> accID2;

				fundID1 = accID1.substr(4);
				accID1 = accID1.substr(0, 4);
				fundID2 = accID2.substr(4);
				accID2 = accID2.substr(0, 4);

				int numACCID = atoi(accID1.c_str());
				int numFundID = atoi(fundID1.c_str());
				int numACCID2 = atoi(accID2.c_str());
				int numFundID2 = atoi(fundID2.c_str());
				int numDepositVal = atoi(depositVal.c_str());
				Transaction transfer(numACCID, numFundID, numDepositVal, numACCID2, numFundID2);
				Que.push(transfer);
			}
			else if (itemType == 'H') {
				string accID;
				string fundID;
				int numFundID;
				int numACCID;
				inFile >> accID;
				if (accID.size() == 4) {
					numFundID = -1;
					numACCID = atoi(accID.c_str());
				}
				else {
					fundID = accID.substr(4);
					accID = accID.substr(0, 4);
					numACCID = atoi(accID.c_str());
					numFundID = atoi(fundID.c_str());
				}
				Transaction history(numACCID, numFundID);
				Que.push(history);
			}
		}
	}
	return Que;
}

/*This function creates all of the transactions and stores them in the AccountDataBase. It takes in the queue generated in BuildTransactions
* It then creates the transactions in order of FIFO.
*/
void Driver::runTransactions(queue<Transaction> que) {
	while (!que.empty()) {
		Transaction t = que.front();
		que.pop();
		Account* acc;
		Account* acc2;
		if (t.getTransactionType() == 'D' || t.getTransactionType() == 'W') {
			if (myAccounts.retrieve(t.getAccountID(), acc)) {
				if (t.getTransactionType() == 'D') {
					acc->deposit(t.getFundID(), t.getTransactionAmount());
				}
				else {
					acc->withdrawl(t.getFundID(), t.getTransactionAmount());
				}
				acc->transactions[t.getFundID()].push_back(t);//stores in vector of transactions at fundID indice
			}
			else {
				cerr << "Given Account Does Not Exist" << endl;
			}
		}
		else if (t.getTransactionType() == 'O') {
			Account* newAccount = new Account(t.getFirst(), t.getLast(), t.getAccountID());
			if (!myAccounts.insert(newAccount)) {
				cerr << "This account is already open!" << endl;
			}
		}
		else if (t.getTransactionType() == 'T') {
			if (myAccounts.retrieve(t.getAccountID(), acc) && myAccounts.retrieve(t.getAccountID2(), acc2) && t.getFundID() >= 0 && t.getFundID() <= 9 && t.getFundID2() >= 0 && t.getFundID2() <= 9) {
				if (myAccounts.getAccount(t.getAccountID()).funds[t.getFundID()].getBalance() < t.getTransactionAmount()) {
					if (t.getFundID() == 0 || t.getFundID() == 1 && myAccounts.getAccount(t.getAccountID()).funds[0].getBalance() + myAccounts.getAccount(t.getAccountID()).funds[1].getBalance()
						>= t.getTransactionAmount()) {
						myAccounts.getAccount(t.getAccountID2()).funds[t.getFundID2()] += t.getTransactionAmount();
						if (t.getFundID() == 0) {
							myAccounts.getAccount(t.getAccountID()).funds[1].setBalance( 
								myAccounts.getAccount(t.getAccountID()).funds[1].getBalance() - (t.getTransactionAmount() - myAccounts.getAccount(t.getAccountID()).funds[0].getBalance()));
							myAccounts.getAccount(t.getAccountID()).funds[0] = 0;
							acc->transactions[0].push_back(t);
							acc->transactions[t.getFundID2()].push_back(t);
						}
						else {
							myAccounts.getAccount(t.getAccountID()).funds[0].setBalance(
								myAccounts.getAccount(t.getAccountID()).funds[0].getBalance()  - (t.getTransactionAmount() - myAccounts.getAccount(t.getAccountID()).funds[1].getBalance()));
							myAccounts.getAccount(t.getAccountID()).funds[1] = 0;
							acc->transactions[1].push_back(t);
							acc->transactions[t.getFundID2()].push_back(t);
						}
					}
					else if (t.getFundID() == 2 || t.getFundID() == 3 && myAccounts.getAccount(t.getAccountID()).funds[2].getBalance() + myAccounts.getAccount(t.getAccountID()).funds[3].getBalance()
						>= t.getTransactionAmount()) {
						myAccounts.getAccount(t.getAccountID2()).funds[t.getFundID2()] += t.getTransactionAmount();
						if (t.getFundID() == 2) {
							myAccounts.getAccount(t.getAccountID()).funds[3].setBalance(
								myAccounts.getAccount(t.getAccountID()).funds[3].getBalance() - (t.getTransactionAmount() - myAccounts.getAccount(t.getAccountID()).funds[2].getBalance()));
							myAccounts.getAccount(t.getAccountID()).funds[2] = 0;
							acc->transactions[2].push_back(t);
							acc->transactions[t.getFundID2()].push_back(t);
						}
						else {
							myAccounts.getAccount(t.getAccountID()).funds[2].setBalance(
								myAccounts.getAccount(t.getAccountID()).funds[2].getBalance() - (t.getTransactionAmount() - myAccounts.getAccount(t.getAccountID()).funds[3].getBalance()));
							myAccounts.getAccount(t.getAccountID()).funds[3] = 0;
							acc->transactions[3].push_back(t);
							acc->transactions[t.getFundID2()].push_back(t);
						}
					}
					else {
						cerr << "Not Enough Funds to Transfer!" << endl;
						t.setFailure("Not Enough funds to Transfer ");
					}
				}
				else {
					acc2->funds[t.getFundID2()] += t.getTransactionAmount();
					acc->funds[t.getFundID()].setBalance(
						acc->funds[t.getFundID()].getBalance() - t.getTransactionAmount());
					acc->transactions[t.getFundID()].push_back(t);
					acc2->transactions[t.getFundID2()].push_back(t);
				}
			}
			else {
				cerr << "One of the Given Accounts or Funds Associated with the Account Does Not Exist!" << endl;
				t.setFailure("One of the Given Accounts or Funds Associated with the Account Does Not Exist!");
			}
		}
		else if (t.getTransactionType() == 'H') {
			myAccounts.retrieve(t.getAccountID(), acc);
			if (t.getFundID() == -1) {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < acc->transactions[i].size(); j++) {
						acc->transactions[i][j].Print();
					}
				}
			}
			else {
				for (int i = 0; i < acc->transactions[t.getFundID()].size(); i++) {
					acc->transactions[t.getFundID()][i].Print();
				}
			}
		}
	}
	myAccounts.Display();
}
