#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isBorrowed;

    Book(int id, std::string title, std::string author);
    void displayBookInfo() const;
};

#endif // BOOK_H
