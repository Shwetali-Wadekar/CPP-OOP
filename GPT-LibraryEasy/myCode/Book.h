#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <Poco/JSON/Object.h>

class Book {
private:
    std::string id;
    std::string title;
    std::string author;
    bool isBorrowed = false;

public:
    Book(std::string id, std::string title, std::string author);
    std::string getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getIsBorrowed() const;
    void setBorrowed(bool borrowed);
    Poco::JSON::Object::Ptr toJson() const;
};

#endif /* BOOK_H_ */
