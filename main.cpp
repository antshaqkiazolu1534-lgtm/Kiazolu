#include "Functions.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n--- Library Book Borrowing System ---\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book by ID\n";
        cout << "6. Display Overdue Books\n";
        cout << "7. Calculate Total Fines\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: borrowBookMenu(); break;
            case 4: returnBookMenu(); break;
            case 5: searchBook(); break;
            case 6: displayOverdueBooks(); break;
            case 7: calculateTotalFines(); break;
            case 8: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}
