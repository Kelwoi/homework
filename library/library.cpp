#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct Book {
    string author;
    string name;
    int year;
    bool available;

  
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Author: " << book.author << ", Name: " << book.name
            << ", Year: " << book.year << ", Available: " << (book.available ? "Yes" : "No");
        return os;
    }
};

class Library {
private:
    list<Book> lib;

public:

    void addBook(const Book& book) {
        lib.push_back(book);
    }


    void displayBooks() const {
        for (const auto& book : lib) {
            cout << book << endl;
        }
    }


    Book* findBook(const string& author, const string& name) {
        auto it = find_if(lib.begin(), lib.end(), [&author, &name](const Book& b) {
            return b.author == author && b.name == name;
            });
        return it != lib.end() ? &(*it) : nullptr;
    }


    void findBooksByAuthor(const string& author) const {
        for (const auto& book : lib) {
            if (book.author == author) {
                cout << book << endl;
            }
        }
    }


    bool issueBook(const string& author, const string& name) {
        Book* book = findBook(author, name);
        if (book && book->available) {
            book->available = false;
            return true;
        }
        return false;
    }


    bool returnBook(const string& author, const string& name) {
        Book* book = findBook(author, name);
        if (book && !book->available) {
            book->available = true;
            return true;
        }
        return false;
    }


    void sortBooks() {
        lib.sort([](const Book& a, const Book& b) {
            return a.author < b.author || (a.author == b.author && a.name < b.name);
            });
    }


    void removeBook(const string& author, const string& name, int year) {
        lib.remove_if([&author, &name, year](const Book& b) {
            return b.author == author && b.name == name && b.year == year;
            });
    }


    void removeBookByIndex(size_t index) {
        if (index >= lib.size()) return;
        auto it = lib.begin();
        advance(it, index);
        lib.erase(it);
    }


    void editBookByIndex(size_t index, const Book& updatedBook) {
        if (index >= lib.size()) return;
        auto it = lib.begin();
        advance(it, index);
        *it = updatedBook;
    }


    bool editBook(const string& author, const string& name, const Book& updatedBook) {
        Book* book = findBook(author, name);
        if (book) {
            *book = updatedBook;
            return true;
        }
        return false;
    }
};

int main() {
    Library library;


    library.addBook({ "Author A", "Book 1", 2000, true });
    library.addBook({ "Author B", "Book 2", 1999, true });
    library.addBook({ "Author A", "Book 3", 2010, true });


    cout << "All books in the library:" << endl;
    library.displayBooks();


    Book* foundBook = library.findBook("Author A", "Book 1");
    if (foundBook) {
        cout << "\nFound book: " << *foundBook << endl;
    }
    else {
        cout << "\nBook not found." << endl;
    }


    if (library.issueBook("Author A", "Book 1")) {
        cout << "\nBook issued successfully." << endl;
    }
    else {
        cout << "\nFailed to issue book." << endl;
    }


    if (library.returnBook("Author A", "Book 1")) {
        cout << "\nBook returned successfully." << endl;
    }
    else {
        cout << "\nFailed to return book." << endl;
    }


    library.sortBooks();
    cout << "\nsort:" << endl;
    library.displayBooks();


    library.removeBook("Author B", "Book 2", 1999);
    cout << "\nremove:" << endl;
    library.displayBooks();


    library.editBookByIndex(0, { "Author C", "Updated Book", 2022, true });
    cout << "\nedit by index:" << endl;
    library.displayBooks();


}
