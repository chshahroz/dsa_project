#include "Library.h"
#include <iostream>

void Library::addBook(int id, std::string title, std::string author) {
    books.emplace_back(id, title, author);
    std::cout << "Book added successfully!\n";
}

void Library::addUser(std::string name) {
    users.emplace_back(name);
    std::cout << "User added successfully!\n";
}

Book* Library::searchBookById(int id) {
    for (auto& book : books) {
        if (book.id == id) {
            return &book;
        }
    }
    return nullptr;
}

void Library::displayAllBooks() const {
    std::cout << "Library Books:\n";
    for (const auto& book : books) {
        book.displayBookInfo();
        std::cout << "\n";
    }
}

void Library::displayAllUsers() const {
    std::cout << "Library Users:\n";
    for (const auto& user : users) {
        user.displayUserInfo();
        std::cout << "\n";
    }
}
