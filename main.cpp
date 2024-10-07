/* 
   author: Won Ko
   Description: This is a simple ATM controller
   Editor(s) used: Sublime Text
   Compiler(s) used: GNC compiler (g++ 14.2.0 ver)
*/

#include "simple_atm_controller.h"

int main() 
{
    // Create the customer information by pin number, account type, account balance for testing
    CustomerInfo c1 = {"1669", {{"checking", 20000}, {"saving", 15000}}};
    CustomerInfo c2 = {"5084", {{"checking", 15000}}};
    CustomerInfo c3 = {"1215", {{"saving", 15000}}};

    // Create the customer account number for testing
    unordered_map<int, CustomerInfo> customers{{52432312, c1}, {50432312, c2}, {51432812, c3}};
    Bank* bank = new Bank(customers);
    // Create simple atm controller object
    Controller controller_test(bank);

    // Test case 1 for customer 1
    int cardNum1 = 52432312;

    cout << "Testing for the simple atm controller:" << endl;
    controller_test.insertCard(cardNum1); // insert card
    controller_test.pin_number("1669"); 
    controller_test.selectAccount("saving"); // select the account type is checking or saving

    cout << "Current account balance: " << controller_test.accountBalance() << "\n";

    int amount_deposite = 5000;
    controller_test.deposit(amount_deposite); // deposit to account
    cout << "Deposited " << amount_deposite << " dollars\n";
    cout << "New account balance: " << controller_test.accountBalance() << "\n";

    int returned_amount = 0;
    controller_test.withdraw(1000, returned_amount); // withdraw to the another account.
    cout << "Withdrew " << 1000 << " dollars\n";
    cout << "New account balance: " << controller_test.accountBalance() << "\n";
    
    controller_test.removeCard(); // remove the card.
    cout << endl;

    // Test case 2 for customer 2
    int cardNum2 = 50432312;
    controller_test.insertCard(cardNum2); // insert card

    controller_test.pin_number("5085"); // checking the invalid pin.
    controller_test.pin_number("5084"); 

    controller_test.selectAccount("checking"); // select the account type is checking or saving

    cout << "Current account balance: " << controller_test.accountBalance() << "\n";

    int amount_deposite2 = 3000;
    controller_test.deposit(amount_deposite2); // deposit to account
    cout << "Deposited " << amount_deposite2 << " dollars\n";
    cout << "New account balance: " << controller_test.accountBalance() << "\n";

    int returned_amount2 = 0;
    cout << "Withdrew " << 20000 << " dollars\n";
    controller_test.withdraw(20000, returned_amount2); // withdraw to more money than account 
  
    controller_test.withdraw(15000, returned_amount2); 
    cout << "Withdrew " << 15000 << " dollars\n";
    cout << "New account balance: " << controller_test.accountBalance() << "\n";

    controller_test.removeCard(); // remove the card.
    cout << endl;
    
    // Test case 3 for customer 3
    int cardNum3 = 51432812;
    controller_test.insertCard(cardNum3); // insert card

    controller_test.pin_number("1215"); 

    controller_test.selectAccount("saving"); // select the account type is checking or saving

    cout << "Current account balance: " << controller_test.accountBalance() << "\n";
 
    int amount_deposite3 = 15000;
    controller_test.deposit(amount_deposite3); // deposit to account
    cout << "Deposited " << amount_deposite3 << " dollars\n"; 
    cout << "New account balance: " << controller_test.accountBalance() << "\n";

    int returned_amount3 = 0;
    controller_test.withdraw(10000, returned_amount3); 
    cout << "Withdrew " << 10000 << " dollars\n";
    cout << "New account balance: " << controller_test.accountBalance() << "\n";

    controller_test.removeCard(); // remove the card.

    return 0;
}
