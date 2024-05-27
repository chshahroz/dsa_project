#include "Book.h"
#include <iostream>

Book::Book(int id, std::string title, std::string author) 
    : id(id), title(title), author(author), isBorrowed(false) {}

void Book::displayBookInfo() const {
    std::cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\n";
    if (isBorrowed) {
        std::cout << "Status: Borrowed\n";
    } else {
        std::cout << "Status: Available\n";
    }
}
