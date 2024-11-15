// MINI PROJECT 

// Name: R VINESH
// Class: SE2
// Roll Number: 05
// PRN Number: F23112005

// PROGRAM -

#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    char title[100];
    char author[100];
    int publicationYear;
    int shelfNumber;
    Node* next;
};

Node* head = nullptr;

void addBook() {
    Node* newBook = new Node();

    cout << "Enter book title: ";
    cin.ignore();
    cin.getline(newBook->title, 100);

    cout << "Enter book author: ";
    cin.getline(newBook->author, 100);

    cout << "Enter publication year: ";
    cin >> newBook->publicationYear;

    cout << "Enter shelf number: ";
    cin >> newBook->shelfNumber;

    newBook->next = nullptr;

    if (head == nullptr || head->shelfNumber >= newBook->shelfNumber) {
        newBook->next = head;
        head = newBook;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->shelfNumber < newBook->shelfNumber) {
            current = current->next;
        }
        newBook->next = current->next;
        current->next = newBook;
    }

    cout << "Book added successfully!";
}

void displayAllBooks() {
    if (head == nullptr) {
        cout << "No books in the library.";
    } else {
        Node* current = head;
        cout << "\nBooks in the library (sorted by shelf number):\n";
        while (current != nullptr) {
            cout << "Title: " << current->title << ", Author: " << current->author
                 << ", Year: " << current->publicationYear 
                 << ", Shelf Number: " << current->shelfNumber << endl;
            current = current->next;
        }
    }
}

void deleteBook() {
    if (head == nullptr) {
        cout << "No books in the library to delete.";
        return;
    }

    int shelfNumberToDelete;
    cout << "Enter the shelf number of the book to delete: ";
    cin >> shelfNumberToDelete;

    if (head->shelfNumber == shelfNumberToDelete) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Book deleted successfully!";
        return;
    }

    Node* current = head;

    while (current->next != nullptr && current->next->shelfNumber != shelfNumberToDelete) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Book deleted successfully!";
    } else {
        cout << "Book with shelf number " << shelfNumberToDelete << " not found.";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Basic Book Arranging System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Delete Book by Shelf Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayAllBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                
        }
    } while (choice != 4);

    return 0;
}



// OUTPUT -

// --- Basic Book Arranging System ---
// 1. Add Book
// 2. Display All Books
// 3. Delete Book by Shelf Number
// 4. Exit
// Enter your choice: 1
// Enter book title: The Great Gatsby
// Enter book author: F. Scott Fitzgerald
// Enter publication year: 1925
// Enter shelf number: 3
// Book added successfully!

// --- Basic Book Arranging System ---
// 1. Add Book
// 2. Display All Books
// 3. Delete Book by Shelf Number
// 4. Exit
// Enter your choice: 1
// Enter book title: To Kill a Mockingbird
// Enter book author: Harper Lee
// Enter publication year: 1960
// Enter shelf number: 1
// Book added successfully!

// --- Basic Book Arranging System ---
// 1. Add Book
// 2. Display All Books
// 3. Delete Book by Shelf Number
// 4. Exit
// Enter your choice: 1
// Enter book title: 1984
// Enter book author: George Orwell
// Enter publication year: 1949
// Enter shelf number: 2
// Book added successfully!

// --- Basic Book Arranging System ---