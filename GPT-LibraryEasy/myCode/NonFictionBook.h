#ifndef NONFICTIONBOOK_H_
#define NONFICTIONBOOK_H_

#include "Book.h"

class NonFictionBook : public Book {
public:
    NonFictionBook(std::string id, std::string title, std::string author);
    Poco::JSON::Object& setGenre(Poco::JSON::Object& obj) const;
};

#endif /* NONFICTIONBOOK_H_ */
