#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Book class definition
class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isBorrowed;

    Book(int id, std::string title, std::string author)
        : id(id), title(title), author(author), isBorrowed(false) {}

    void displayBookInfo() const {
        std::cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\n";
        if (isBorrowed) {
            std::cout << "Status: Borrowed\n";
        } else {
            std::cout << "Status: Available\n";
        }
    }
};

// User class definition
class User {
public:
    std::string name;
    std::vector<Book*> borrowedBooks;

    User(std::string name) : name(name) {}

    void borrowBook(Book& book) {
        if (!book.isBorrowed) {
            book.isBorrowed = true;
            borrowedBooks.push_back(&book);
            std::cout << "Book borrowed successfully!\n";
        } else {
            std::cout << "Book is already borrowed!\n";
        }
    }

    void returnBook(Book& book) {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), &book);
        if (it != borrowedBooks.end()) {
            book.isBorrowed = false;
            borrowedBooks.erase(it);
            std::cout << "Book returned successfully!\n";
        } else {
            std::cout << "This book was not borrowed by the user!\n";
        }
    }

    void displayUserInfo() const {
        std::cout << "User: " << name << "\nBorrowed Books:\n";
        for (const auto& book : borrowedBooks) {
            book->displayBookInfo();
        }
    }
};

// Library class definition
class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(int id, std::string title, std::string author) {
        books.emplace_back(id, title, author);
        std::cout << "Book added successfully!\n";
    }

    void addUser(std::string name) {
        users.emplace_back(name);
        std::cout << "User added successfully!\n";
    }

    Book* searchBookById(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                return &book;
            }
        }
        return nullptr;
    }

    void displayAllBooks() const {
        std::cout << "Library Books:\n";
        for (const auto& book : books) {
            book.displayBookInfo();
            std::cout << "\n";
        }
    }

    void displayAllUsers() const {
        std::cout << "Library Users:\n";
        for (const auto& user : users) {
            user.displayUserInfo();
            std::cout << "\n";
        }
    }

    User* getUserByIndex(int index) {
        if (index >= 0 && index < users.size()) {
            return &users[index];
        }
        return nullptr;
    }
};

// Function to display the menu
void menu() {
    std::cout << "Library System Menu:\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Add User\n";
    std::cout << "3. Borrow Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. Search Book\n";
    std::cout << "6. Display All Books\n";
    std::cout << "7. Display All Users\n";
    std::cout << "8. Exit\n";
}

int main() {
    Library library;
    int choice;

    while (true) {
        menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 8) {
            break;
        }

        switch (choice) {
        case 1: {
            int id;
            std::string title, author;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter Book Title: ";
            std::getline(std::cin, title);
            std::cout << "Enter Book Author: ";
            std::getline(std::cin, author);
            library.addBook(id, title, author);
            break;
        }
        case 2: {
            std::string name;
            std::cin.ignore();
            std::cout << "Enter User Name: ";
            std::getline(std::cin, name);
            library.addUser(name);
            break;
        }
        case 3: {
            int userId, bookId;
            std::cout << "Enter User ID (index): ";
            std::cin >> userId;
            std::cout << "Enter Book ID: ";
            std::cin >> bookId;
            User* user = library.getUserByIndex(userId);
            Book* book = library.searchBookById(bookId);
            if (user && book) {
                user->borrowBook(*book);
            } else {
                if (!user) std::cout << "User not found!\n";
                if (!book) std::cout << "Book not found!\n";
            }
            break;
        }
        case 4: {
            int userId, bookId;
            std::cout << "Enter User ID (index): ";
            std::cin >> userId;
            std::cout << "Enter Book ID: ";
            std::cin >> bookId;
            User* user = library.getUserByIndex(userId);
            Book* book = library.searchBookById(bookId);
            if (user && book) {
                user->returnBook(*book);
            } else {
                if (!user) std::cout << "User not found!\n";
                if (!book) std::cout << "Book not found!\n";
            }
            break;
        }
        case 5: {
            int bookId;
            std::cout << "Enter Book ID: ";
            std::cin >> bookId;
            Book* book = library.searchBookById(bookId);
            if (book) {
                book->displayBookInfo();
            } else {
                std::cout << "Book not found!\n";
            }
            break;
        }
        case 6:
            library.displayAllBooks();
            break;
        case 7:
            library.displayAllUsers();
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
