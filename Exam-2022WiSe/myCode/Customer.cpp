#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "CDAccount.h"
#include "SavingsAccount.h"
#include<memory>
#include<iomanip>
#include<sstream>

using namespace std;

Customer::Customer(unsigned int number) : number(number){
}

unsigned int Customer::getNumber() const {
    return number;
}

std::string Customer::getId() const {
    ostringstream oss;
    oss<<setw(10)<<setfill('0')<<to_string(number);
    return oss.str();
}

Customer* Customer::setPersonalData(std::string lastName, std::string firstName,
        Poco::Data::Date dateOfBirth) {
    this->firstName=firstName;
    this->lastName= lastName;
    this->dateOfBirth=dateOfBirth;
    return this;

}

const Poco::Data::Date& Customer::getDateOfBirth() const {
    return dateOfBirth;
}

const std::string& Customer::getFirstName() const {
    return firstName;
}

const std::string& Customer::getLastName() const {
    return lastName;
}

std::vector<Account*> Customer::allAccounts() const {
    std::vector<Account*> allAccounts;
    for(auto iter=accounts.begin(); iter != accounts.end() ; ++iter){
        allAccounts.push_back((*iter).second.get());
    }
    return allAccounts;

}

Account* Customer::lookupAccount(std::string id) const {

    auto findAccount=accounts.find(id);

    if( findAccount != accounts.end()) {
        return findAccount->second.get();
    }else {
        throw invalid_argument ("account does not exists");
    }
}


void Customer::deleteAccount(std::string id) {
    auto findAccount=accounts.find(id);

    if( findAccount != accounts.end()) {
        if(findAccount->second->getBalance()==0) {
            accounts.erase(id);
        }else {
            throw logic_error ("balance is not zero!");
        }
    }else {
        throw invalid_argument ("account does not exists");
    }
}

//std::ostream& operator <<(std::ostream &out, const Customer &customer) {
//    string dob=to_string(customer.getDateOfBirth().day())+"."+to_string(customer.getDateOfBirth().month())+
//            "."+to_string(customer.getDateOfBirth().year());
//
//    out<<customer.getId()<<": "<<customer.getLastName()<<", "<<customer.getFirstName()<<" ("<<dob+")";
//    return out;
//
//}

Account* Customer::createAccount(Bank::AccountType type) {


    std::unique_ptr<Account> accountPtr;

    if( type == Bank::CD) {
        accountPtr=std::unique_ptr<CDAccount> (new CDAccount(this));
    }else if( type == Bank::Current) {
        accountPtr=std::unique_ptr<CurrentAccount> (new CurrentAccount(this));

    }else if( type == Bank::Savings) {
        accountPtr=std::unique_ptr<SavingsAccount> (new SavingsAccount(this));
    }

    Account* accountRawPtr = accountPtr.get();
    accounts.insert(make_pair(accountPtr->getId(), move(accountPtr)));
    return accountRawPtr;

    //return accountRawPtr;
}

std::ostream& operator <<(std::ostream &out, const Customer &customer) {

    out<<customer.getId()+": "+customer.getLastName()+", "+customer.getFirstName()+" ("+
            std::to_string(customer.getDateOfBirth().day())+"."+std::to_string(customer.getDateOfBirth().month())+"."+
            std::to_string(customer.getDateOfBirth().year())+")";

    return out;

}



