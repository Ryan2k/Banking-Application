# Banking-Application
C++ Application to create a Banking System
Reads in lines with 5 different Transactions: Open an account, Make a deposit, Make a withdrawl, Make a Transfer, Show account history
Takes in a list of transactions and creates them via durable queue
After all transactions are processed in queue, executes transactions
Each account has 10 different funds from money market to short term bond to long term bond ect.
Accounts are stored in a binary search tree.
Lines are read in as follows: Letter to show transaction type, 4 digit account id followed by one digit fund id (0 to 9) then transaction amount
Unless it is O, that means open a new account.
Transfer can be between accounts and funds of different people.
Handles errors for not enough funds to withdrawl.
Funds 0 and 1 are linked as well as 2 and 3

Sample Input:
O Cash Johnny 1001
D 10010 542
D 10011 1542
D 10012 5442
D 10013 7540
D 10017 5442
D 10016 7542
D 10011 1500
D 10012 5000
D 10013 7000
D 10017 6543
D 10016 7576
W 10017 1000
W 10016 65
W 10010 72
T 10017 54 10015
W 10017 20000
H 1001
O Williams Hank 1253
D 12530 10000
D 12531 10000
D 12532 10000
D 12533 10000
D 12534 10000
D 12535 10000
D 12536 10000
D 12537 10000
D 12538 10000
D 12539 10000
H 12534
W 12532 15000
H 1253
T 12539 765 43567
O Nelson Willie 9876
O Willis Bob 9876

Sample Output:
Not Enough Money in Balance to Withdrawl
Deposit $542 to account 1001 fund 0
Withdrew $72 from account 1001 fund 0
Deposit $1542 to account 1001 fund 1
Deposit $1500 to account 1001 fund 1
Deposit $5442 to account 1001 fund 2
Deposit $5000 to account 1001 fund 2
Deposit $7540 to account 1001 fund 3
Deposit $7000 to account 1001 fund 3
Transfered $54 from account 1001 fund 7 to 1001 fund 5
Deposit $7542 to account 1001 fund 6
Deposit $7576 to account 1001 fund 6
Withdrew $65 from account 1001 fund 6
Deposit $5442 to account 1001 fund 7
Deposit $6543 to account 1001 fund 7
Withdrew $1000 from account 1001 fund 7
Transfered $54 from account 1001 fund 7 to 1001 fund 5
Withdrew $20000 from account 1001 fund 7
Deposit $10000 to account 1253 fund 4
Deposit $10000 to account 1253 fund 0
Deposit $10000 to account 1253 fund 1
Deposit $10000 to account 1253 fund 2
Withdrew $15000 from account 1253 fund 2
Deposit $10000 to account 1253 fund 3
Deposit $10000 to account 1253 fund 4
Deposit $10000 to account 1253 fund 5
Deposit $10000 to account 1253 fund 6
Deposit $10000 to account 1253 fund 7
Deposit $10000 to account 1253 fund 8
Deposit $10000 to account 1253 fund 9
One of the Given Accounts or Funds Associated with the Account Does Not Exist!
This account is already open!
Account Holder: Johnny Cash
Account Number: 1001
Money Market Holds: $470
Prime Money Market Holds: $3042
Long-Term Bond Holds: $10442
Short-Term Bonds HOlds: $14540
500 Index Fund Holds: $0
Capital Value Fund Holds: $54
Growth Equity Fund Holds: $15053
Growth Index Fund Holds: $10931
Value Fund Holds: $0
Value Stock Index Holds: $0

Account Holder: Hank Williams
Account Number: 1253
Money Market Holds: $10000
Prime Money Market Holds: $10000
Long-Term Bond Holds: $0
Short-Term Bonds HOlds: $5000
500 Index Fund Holds: $10000
Capital Value Fund Holds: $10000
Growth Equity Fund Holds: $10000
Growth Index Fund Holds: $10000
Value Fund Holds: $10000
Value Stock Index Holds: $10000

Account Holder: Willie Nelson
Account Number: 9876
Money Market Holds: $0
Prime Money Market Holds: $0
Long-Term Bond Holds: $0
Short-Term Bonds HOlds: $0
500 Index Fund Holds: $0
Capital Value Fund Holds: $0
Growth Equity Fund Holds: $0
Growth Index Fund Holds: $0
Value Fund Holds: $0
Value Stock Index Holds: $0
