#include "CurrentAccount.h"
#include "Customer.h"
using namespace std;

CurrentAccount::CurrentAccount(Customer *customer) : Account(customer, Bank::Current){
}

Poco::JSON::Object& CurrentAccount::setAccountType(
        Poco::JSON::Object &obj) const {

    obj.set("accountType","Current");

    return obj;
}
