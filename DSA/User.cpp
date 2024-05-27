#include "User.h"
#include <iostream>
#include <algorithm>

User::User(std::string name) : name(name) {}

void User::borrowBook(Book& book) {
    if (!book.isBorrowed) {
        book.isBorrowed = true;
        borrowedBooks.push_back(&book);
        std::cout << "Book borrowed successfully!\n";
    } else {
        std::cout << "Book is already borrowed!\n";
    }
}

void User::returnBook(Book& book) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), &book);
    if (it != borrowedBooks.end()) {
        book.isBorrowed = false;
        borrowedBooks.erase(it);
        std::cout << "Book returned successfully!\n";
    } else {
        std::cout << "This book was not borrowed by the user!\n";
    }
}

void User::displayUserInfo() const {
    std::cout << "User: " << name << "\nBorrowed Books:\n";
    for (const auto& book : borrowedBooks) {
        book->displayBookInfo();
    }
}
