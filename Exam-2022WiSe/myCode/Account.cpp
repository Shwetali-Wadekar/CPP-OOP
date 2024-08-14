#include "Account.h"
#include "Customer.h"

#include<set>
#include<iomanip>
#include<sstream>
using namespace std;
/**
 * Base class for all Accounts. Accounts have an id which is assigned
 * upon creation as follows:
 *
 *  * The first digit indicated the account type
 *    - 1: Current account
 *    - 2: Savings account
 *    - 3: Certificate of deposit account
 *
 *  * The second and third digit represent a counter (sequence number)
 *    for the number of accounts of a given type. Counting starts with 1.
 *
 *  * The remaining 7 digits are the same as the 7 rightmost digits
 *    of the customer id.
 */
Account::Account(Customer *customer, Bank::AccountType type) {
   // id="0";
    int Acctype=3;
    if(type==Bank::Current) {
        Acctype=1;
    }else if(type== Bank::Savings) {
        Acctype=2;

    }
    std::vector<Account*> allAcc=customer->allAccounts();
    std::set<int> seqs;

    for(auto i= allAcc.begin() ; i != allAcc.end() ; ++i) {
        if((**i).accountType((**i).getId())==type) {
        seqs.insert(std::stoi((**i).getId().substr(1,2)));}
    }

    int seqNumber=1;

    do{
        auto f=seqs.find(seqNumber);
        if(f != seqs.end()) {
            seqNumber++;
        }else {
            break;
        }
    }while(true);

    ostringstream oss;
    oss<<Acctype<<setw(2)<<setfill('0')<<seqNumber<<customer->getId().substr(3,7);
    id=oss.str();

}

std::string Account::getId() const {
    return id;
}

Bank::AccountType Account::accountType(std::string accountId) {

    if(accountId[0] == '1') {
        return Bank::Current;
    }else if(accountId[0] == '2') {
        return Bank::Savings;
    }else {//if(accountId[0] == '3') {
        return Bank::CD;
    }
}

float Account::getBalance() const {
    return balance;
}



void Account::transact(float amount) {
    balance=balance+amount;
}

Account::~Account() {
}
/**
 * Creates a JSON Object that represents the account data.
 * Fields are "accountType" and "balance", e.g.:
 * {"accountType":"Current","balance":100}
 */
Poco::JSON::Object::Ptr Account::toJson() const {
    Poco::JSON::Object::Ptr ptr1= new Poco::JSON::Object;
    //if(accountType(id)== Bank::CD) {
        setAccountType(*ptr1);
    //}
    //Poco::JSON::Object::Ptr ptr1;=new set
    //Poco::JSON::Object
       (*ptr1).set("balance",balance);

       return ptr1;
}
