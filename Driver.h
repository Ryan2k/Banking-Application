#pragma once
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include "Transaction.h"
#include "Account.h"
#include "AccountDataBase.h"

using namespace std;

class Driver {
	private:
		AccountDataBase myAccounts;
	public:
		queue<Transaction> BuildTransactions(string fileName);
		
		void runTransactions(queue<Transaction> que);
};
