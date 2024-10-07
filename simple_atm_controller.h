#ifndef SIMPLE_ATM_CONTROLLER_H
#define SIMPLE_ATM_CONTROLLER_H

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

// create struct classes for customer information by card number. pin, accounts
struct CustomerInfo 
{
    string pin;
    map<string, int> accounts; 
};

class Bank 
{
    unordered_map<int, CustomerInfo> cards_;

public:
    Bank(const unordered_map<int, CustomerInfo>& cards);

    bool validCard(int card_num) const;
    bool validPin(int card_num, const string& pin, CustomerInfo*& active_card) const;
};

class Controller 
{
    Bank* bank_;
    CustomerInfo* active_card_;

    int* account_balance_;
    int card_num_;

    string pin_;

    bool isCard_;
    bool is_pin_valid_;
    bool account_valid_;

public:
    Controller(Bank* bank);

    void insertCard(int card_num);
    void removeCard();
    void pin_number(const string& pin);
    void selectAccount(const string& account_name);
    int accountBalance() const;
    void withdraw(int amount, int& returned_amount);
    void deposit(int amount);
};

#endif 