#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(int id, std::string title, std::string author);
    void addUser(std::string name);
    Book* searchBookById(int id);
    void displayAllBooks() const;
    void displayAllUsers() const;
};

#endif // LIBRARY_H
