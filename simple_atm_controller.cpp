#include "simple_atm_controller.h"

// Bank class implementation
Bank::Bank(const unordered_map<int, CustomerInfo>& cards) : cards_(cards) {}

bool Bank::validCard(int card_num) const 
{
    return cards_.count(card_num);
}

bool Bank::validPin(int card_num, const string& pin, CustomerInfo*& active_card) const 
{
    if (validCard(card_num)) 
    {
        active_card = const_cast<CustomerInfo*>(&cards_.at(card_num));
        return active_card->pin == pin;
    }
    return false;
}

// Controller class implementation
Controller::Controller(Bank* bank) : bank_(bank), active_card_(nullptr), account_balance_(nullptr), card_num_(-1), isCard_(false), is_pin_valid_(false), account_valid_(false) {}

void Controller::insertCard(int card_num) 
{
    if (bank_->validCard(card_num)) 
    {
        card_num_ = card_num;
        isCard_ = true;
    } 
    else 
    {
       cout << "Invalid card: it doesn't exist in the bank database system.\n";
    }
}

void Controller::removeCard() 
{
    if (isCard_) 
    {
        isCard_ = false;
        is_pin_valid_ = false;
        account_valid_ = false;
        account_balance_ = nullptr;
        active_card_ = nullptr;
        card_num_ = -1;
        cout << "Removing the card successful, don't forget to take it\n";
    }
}

void Controller::pin_number(const string& pin) 
{
    if (isCard_) 
    {
        if (bank_->validPin(card_num_, pin, active_card_)) 
        {
            pin_ = pin;
            is_pin_valid_ = true;
        } 
        else 
        {
             cout << "The PIN number is invalid\n";
        }
    }
}

void Controller::selectAccount(const string& account_name) 
{
    if (is_pin_valid_) 
    {
        auto it = active_card_->accounts.find(account_name);
        if (it != active_card_->accounts.end()) 
        {
            account_valid_ = true;
            account_balance_ = &(it->second);
            cout << "Selected " << it->first << " account and available account balance " << *account_balance_ << "\n";
        } 
        else 
        {
           cout << "Account does not exist.\n";
        }
    } 
    else 
    {
         cout << "Enter the PIN number before accessing the accounts\n";
    }
}

int Controller::accountBalance() const 
{
    if (account_valid_) 
    {
        return *account_balance_;
    }
    cout << "Account has not been selected\n";
    return -1;
}

void Controller::withdraw(int amount, int& returned_amount) 
{
    if (account_valid_) 
    {
        if (*account_balance_ < amount) 
        {
            cout << "Not enough funds to transfer, enter amount smaller than current balance\n";
            return;
        }
        *account_balance_ -= amount;
        returned_amount = amount;
    } 
    else 
    {
        cout << "Account has not been selected\n";
    }
}

void Controller::deposit(int amount) 
{
    if (account_valid_) 
    {
        *account_balance_ += amount;
    } 
    else 
    {
        cout << "Account has not been selected\n";
    }
}
