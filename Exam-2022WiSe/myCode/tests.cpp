
    #include <iostream>
    #include <sstream>
    #include <set>
    #include <Poco/JSON/Stringifier.h>

    using namespace std;

    #include "Bank.h"
    #include "Customer.h"
    #include "Account.h"
    #include "CurrentAccount.h"
    #include "SavingsAccount.h"
    #include "CDAccount.h"

    /**
     * Outputs the failedMessage on the console if condition is false.
     *
     * @param condition the condition
     * @param failedMessage the message
     */
    void assertTrue(bool condition, string failedMessage) {
        if (!condition) {
            cout << failedMessage << endl;
        }
    }

    /**
     * Initializes a bank with customers with different account
     * types. Can be used as data for various tests.
     */
    void setupBank(Bank& bank) {
        // The following code has been commented out to keep
        // the start project buildable. Remove the comments
        // when you have implemented the required methods.

        /********* reactivate later *********
        Customer* c = bank.createCustomer()->setPersonalData
                ("Angel", "Alice", Poco::Data::Date(1991, 1, 1));
        c->createAccount(Bank::AccountType::Current)->transact(100);
        c->createAccount(Bank::AccountType::Savings)->transact(500);
        c->createAccount(Bank::AccountType::CD)->transact(1000);
        c->createAccount(Bank::AccountType::CD)->transact(2000);
        c->createAccount(Bank::AccountType::CD)->transact(3000);
        bank.createCustomer()->setPersonalData
                ("Billings", "Bob", Poco::Data::Date(1992, 2, 2));
        bank.createCustomer()->setPersonalData
                ("Chase", "Caesar", Poco::Data::Date(1993, 3, 3));
        ************************************/
        Customer* c = bank.createCustomer()->setPersonalData
                    ("Angel", "Alice", Poco::Data::Date(1991, 1, 1));
            c->createAccount(Bank::AccountType::Current)->transact(100);
            c->createAccount(Bank::AccountType::Savings)->transact(500);
            c->createAccount(Bank::AccountType::CD)->transact(1000);
            c->createAccount(Bank::AccountType::CD)->transact(2000);
            c->createAccount(Bank::AccountType::CD)->transact(3000);
            bank.createCustomer()->setPersonalData
                    ("Billings", "Bob", Poco::Data::Date(1992, 2, 2));
            bank.createCustomer()->setPersonalData
                    ("Chase", "Caesar", Poco::Data::Date(1993, 3, 3));
    }

    void bankTests () {
        /**
         * Create a bank and initialize it with setupBank.
         */
        // Add your code here:
        Bank sbi;
        setupBank(sbi);
        /*
         * (1) Assert that the bank has three customers.
         */
        // Add your code here:
        assertTrue(sbi.allCustomers().size()==3,"bank not having 3 customers");

       /*
        * (2) Assert that the customer with id 0000000002 can be looked up.
        */
        // Add your code here:
        assertTrue(sbi.lookupCustomer("0000000002") != nullptr,"custer id 0000000002 can not accessed");


       /*
        * (3) Assert that there is no customer with id 0000000042.
        */
        // Add your code here:
       assertTrue( sbi.lookupCustomer("0000000042")==nullptr,"there is no customer with id 0000000042");



    }

    void customerTests () {
        /*
         * (1) Create a Customer with sample data. Assert that
         * invoking the overloaded left shift operator produces the
         * expected result. (Hint: use a stringstream.)
         */
        // Add your code here:
        Customer bhavin(1);
        bhavin.setPersonalData("prajapati","Bhavinkumar",Poco::Data::Date(1997,12,1));
        //cout<<bhavin;
        string expected="0000000001: prajapati, Bhavinkumar (1.12.1997)";
        ostringstream oss;
        oss<<bhavin;
        assertTrue(oss.str()==expected,"operator overloading not working");
    }

    void accountTests () {
        /**
         * Create a bank and initialize it with setupBank.
         */
        // Add your code here:

        Bank bob;
        setupBank(bob);


        /*
         * (1) Lookup Customer 0000000001 (Alice), assert that she is found.
         */
        // Add your code here:
        assertTrue(bob.lookupCustomer("0000000001")!=nullptr,"alice should be in the bank");

        /*
         * (2) Assert that Alice has 5 accounts.
         */
        // Add your code here:

        assertTrue(bob.lookupCustomer("0000000001")->allAccounts().size()==5,"alice should have 5 accounts");
        /**
         * (3) Assert that the C++-types of Alice's accounts and the
         * types derived from the account id (see Account::accountType)
         * match.
         */
        // Add your code here:

        /**
         * (4) Assert that Alice has 3 accounts of type CD
         * and that these accounts have the ids "3010000001",
         * "3020000001" and "3030000001". The check must not
         * rely on accounts being returned in a specific sequence.
         *
         * In order to check this, proceed as follows:
         *  * Obtain the ids
         *  * Filter out the CD accounts and count them
         *  * Out the ids in a set and assert that the set contains
         *    the expected ids.
         */
        // Add your code here:
        std::vector<Account*> aliceaccounts=bob.lookupCustomer("0000000001")->allAccounts();
        set<string> exptected {"3030000001","3020000001","3010000001"};
        set<string> actual;

        for( auto i = aliceaccounts.begin() ; i != aliceaccounts.end() ; ++i) {
            if((**i).accountType((**i).getId())==Bank::CD) {
                actual.insert((**i).getId());
            }

        }
        assertTrue(actual==exptected,"set not macthed");


        /**
         * (5) Assert that an attempt to delete account 3040000001
         * throws an invalid_argument exception.
         */
        // Add your code here:
        string expected_str="account does not exists";
        string actual_str;
        try{
        bob.lookupCustomer("0000000001")->deleteAccount("3040000001");
        }catch ( invalid_argument& e) {
            actual_str=e.what();
        }
        assertTrue(expected_str==actual_str,"not throwing  an invalid_argument exception");


         /**
          * (6) Assert that an attempt to delete account 3020000001
          * throws a logic_error exception.
          */
        // Add your code here:

        string expected_str2="balance is not zero!";
         string actual_str2;
         try{
         bob.lookupCustomer("0000000001")->deleteAccount("3020000001");
         }catch ( logic_error& e) {
             actual_str2=e.what();
         }
         assertTrue(expected_str2==actual_str2,"not throwing  an invalid_argument exception");

          /**
           * (7) Withdraw the deposit from account 3010000001,
           * delete the account and assert that Alice has only
           * 4 accounts left
           */
        // Add your code here:

         float deposite = bob.lookupCustomer("0000000001")->lookupAccount("3010000001")->getBalance();
         bob.lookupCustomer("0000000001")->lookupAccount("3010000001")->transact(-deposite);
         bob.lookupCustomer("0000000001")->deleteAccount("3010000001");

         assertTrue(bob.lookupCustomer("0000000001")->allAccounts().size()==4,"Alice does not have 4 account");

          /**
           * (8) Lookup Alice's account 1010000001, create
           * the JSON object representing its data and assert
           * that the account type is "Current" and the balance
           * is 100.
           */
        // Add your code here:
         Poco::JSON::Object::Ptr p1=bob.lookupCustomer("0000000001")->lookupAccount("1010000001")->toJson();
         assertTrue(p1.get()->getValue<string>("accountType")=="Current" && p1.get()->getValue<float>("balance")==100,
                 "Json not working");
       //  cout<<p1.get()->getValue<float>("balance");


    }

    void allTests() {
        bankTests();
        customerTests();
        accountTests();
    }
