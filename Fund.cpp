#pragma once
#include "Fund.h"

Fund::Fund(int a) {
	this->balance = a;
}

int Fund::getBalance() {
	return this->balance;
}

void Fund::setBalance(int x) {
	this->balance = x;
}

Fund Fund::operator+(const Fund& rhs) {
	Fund fund(0);
	fund.balance = this->balance += rhs.balance;
	return fund;
}

Fund& Fund::operator+=(const Fund& rhs) {
	this->balance += rhs.balance;
	return *this;
}