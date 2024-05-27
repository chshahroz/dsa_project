#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

class User {
public:
    std::string name;
    std::vector<Book*> borrowedBooks;

    User(std::string name);
    void borrowBook(Book& book);
    void returnBook(Book& book);
    void displayUserInfo() const;
};

#endif // USER_H
