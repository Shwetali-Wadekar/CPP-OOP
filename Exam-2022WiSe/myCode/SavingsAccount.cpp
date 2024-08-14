#include "SavingsAccount.h"
#include "Customer.h"
using namespace std;
SavingsAccount::SavingsAccount(Customer *customer) : Account(customer, Bank::Savings){
}
/**
 * Sets the accountType field of the object to "Savings".
 *
 * @param obj the object to modify
 * @return the object for method invocation chaining
 */
Poco::JSON::Object& SavingsAccount::setAccountType(
        Poco::JSON::Object &obj) const {

    obj.set("accountType","Savings");

    return obj;
}
