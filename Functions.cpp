#include "Functions.h"
#include <iostream>
using namespace std;

LibraryBook library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    int id;
    string title, author;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);

    library[bookCount++] = LibraryBook(id, title, author);
    cout << "Book added successfully!" << endl;
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << library[i].getBookID()
             << ", Title: " << library[i].getTitle()
             << ", Author: " << library[i].getAuthor()
             << ", Borrowed: " << (library[i].isBorrowed() ? "Yes" : "No") << endl;
    }
}

void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].getBookID() == id) {
            cout << "Found: " << library[i].getTitle() << " by " << library[i].getAuthor() << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void borrowBookMenu() {
    int id, days;
    string name;
    cout << "Enter Book ID to borrow: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Borrower Name: ";
    getline(cin, name);
    cout << "Enter Days Borrowed: ";
    cin >> days;

    for (int i = 0; i < bookCount; i++) {
        if (library[i].getBookID() == id) {
            library[i].borrowBook(name, days);
            return;
        }
    }
    cout << "Book not found." << endl;
}

void returnBookMenu() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].getBookID() == id) {
            library[i].returnBook();
            return;
        }
    }
    cout << "Book not found." << endl;
}

void displayOverdueBooks() {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isOverdue()) {
            cout << "Overdue: " << library[i].getTitle()
                 << " borrowed by " << library[i].getBorrowerName()
                 << " for " << library[i].getDaysBorrowed() << " days." << endl;
        }
    }
}

void calculateTotalFines() {
    int total = 0;
    for (int i = 0; i < bookCount; i++) {
        total += library[i].calculateFine();
    }
    cout << "Total fines: " << total << " RWF" << endl;
}
