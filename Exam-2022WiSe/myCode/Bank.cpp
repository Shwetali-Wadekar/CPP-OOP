#include "Bank.h"
#include "Customer.h"
#include "Account.h"
//#include "CurrentAccount.h"
//#include "CDAccount.h"
//#include "SavingsAccount.h"
using namespace std;

Customer* Bank::createCustomer() {
    Customer* customer=new Customer(nextCustomerNumber);
    //Customer customer(nextCustomerNumber);
    std::unique_ptr<Customer> customerPtr(customer);

    std::string id=customerPtr->getId();
   // Customer* cus= customerPtr.get();
    customers.insert(make_pair(id,move(customerPtr)));

    nextCustomerNumber++;
    return customer;

}

Customer* Bank::lookupCustomer(std::string id) const {
    auto findCus= customers.find(id);
    if( findCus != customers.end()) {
        return findCus->second.get();
    }else {
        return nullptr;
    }
}

std::vector<Customer*> Bank::allCustomers() const {
    vector<Customer*> allCustomers;
    for(auto iter=customers.begin() ;  iter != customers.end() ; ++iter) {

        allCustomers.push_back(iter->second.get());

    }
    return allCustomers;
}
  //  std::map<std::string, std::unique_ptr<Customer>> customers;
