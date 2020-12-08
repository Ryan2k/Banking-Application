#pragma once
using namespace std;

class Fund {
	private:
		int balance;

	public:
		Fund(int a);
		int getBalance();
		void setBalance(int x);
		Fund operator+(const Fund& rhs);
		Fund& operator+=(const Fund& rhs);
};
