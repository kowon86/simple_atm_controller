# Implemet a simple ATM controller.

This project aims to implement a simple ATM controller.

# Requirements

At least the following flow should be implemented:
1. Insert Card -> 2. PIN number -> 3. Select Account (Checking or Saving) -> 4. See Balance / Deposit / Withdraw

There are no cents only 1 dollar bills in this system.

Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code. Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing the controller part (not including bank system, cash bin etc) is within the scope.

A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.

Based on your work, another engineer should be able to implement the user interface. You don't need to implement any REST API, RPC, network communication etc, but just functions/classes/methods, etc.

You can simplify some complex real world problems if you think it's not worth illustrating in the project.

# Running the test case.
you have to clone the git or download the files:
```
git clone https://github.com/kowon86/simple_atm_controller.git
```
then makefile to run the simple test case:
```
make
./output
```

# Test case output
```
Testing for the simple atm controller:
Selected saving account and available account balance 15000
Current account balance: 15000
Deposited 5000 dollars
New account balance: 20000
Withdrew 1000 dollars
New account balance: 19000
Removing the card successful, don't forget to take it

The PIN number is invalid
Selected checking account and available account balance 15000
Current account balance: 15000
Deposited 3000 dollars
New account balance: 18000
Withdrew 20000 dollars
Not enough funds to transfer, enter amount smaller than current balance
Withdrew 15000 dollars
New account balance: 3000
Removing the card successful, don't forget to take it

Selected saving account and available account balance 15000
Current account balance: 15000
Deposited 15000 dollars
New account balance: 30000
Withdrew 10000 dollars
New account balance: 20000
Removing the card successful, don't forget to take it
```

