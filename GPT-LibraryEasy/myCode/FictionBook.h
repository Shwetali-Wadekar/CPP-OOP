#ifndef FICTIONBOOK_H_
#define FICTIONBOOK_H_

#include "Book.h"

class FictionBook : public Book {
public:
    FictionBook(std::string id, std::string title, std::string author);
    Poco::JSON::Object& setGenre(Poco::JSON::Object& obj) const;
};

#endif /* FICTIONBOOK_H_ */
