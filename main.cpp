#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definicja klasy Book
class Book {
private:
    string title;
    string author;
    string genre;
    int publication_year;
    bool is_borrowed;

public:
    /**
     * Konstruktor klasy Book.
     *
     * @param t Tytuł książki.
     * @param a Autor książki.
     * @param g Gatunek książki.
     * @param y Rok wydania książki.
     */
    Book(string t, string a, string g, int y) : title(t), author(a), genre(g), publication_year(y), is_borrowed(false) {}

    /**
     * Pobiera tytuł książki.
     *
     * @return Tytuł książki.
     */
    string getTitle() const { return title; }

    /**
     * Pobiera autora książki.
     *
     * @return Autor książki.
     */
    string getAuthor() const { return author; }

    /**
     * Pobiera gatunek książki.
     *
     * @return Gatunek książki.
     */
    string getGenre() const { return genre; }

    /**
     * Pobiera rok wydania książki.
     *
     * @return Rok wydania książki.
     */
    int getPublicationYear() const { return publication_year; }

    /**
     * Sprawdza, czy książka jest wypożyczona.
     *
     * @return True, jeśli książka jest wypożyczona, w przeciwnym razie False.
     */
    bool getIsBorrowed() const { return is_borrowed; }

    /**
     * Ustawia status wypożyczenia książki.
     *
     * @param borrowed True, jeśli książka jest wypożyczona, w przeciwnym razie False.
     */
    void setIsBorrowed(bool borrowed) { is_borrowed = borrowed; }

    /**
     * Wypożycza książkę.
     */
    void borrow() { is_borrowed = true; }

    /**
     * Zwraca książkę.
     */
    void returnBook() { is_borrowed = false; }
};

// Definicja klasy Library
class Library {
private:
    vector<Book> books;

public:
    /**
     * Dodaje książkę do biblioteki.
     *
     * @param book Książka do dodania.
     */
    void addBook(const Book& book) { books.push_back(book); }

    /**
     * Usuwa książkę z biblioteki.
     *
     * @param book Książka do usunięcia.
     */
    void removeBook(const Book& book) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == book.getTitle() && it->getAuthor() == book.getAuthor()) {
                books.erase(it);
                break;
            }
        }
    }

    /**
     * Wyszukuje książki według słowa kluczowego.
     *
     * @param keyword Słowo kluczowe do wyszukiwania.
     * @return Wektor książek spełniających kryteria wyszukiwania.
     */
    vector<Book> searchBooks(const string& keyword) {
        vector<Book> result;
        for (const auto& book : books) {
            if (book.getTitle().find(keyword) != string::npos || book.getAuthor().find(keyword) != string::npos || book.getGenre().find(keyword) != string::npos) {
                result.push_back(book);
            }
        }
        return result;
    }

    /**
     * Wyświetla wszystkie książki w bibliotece.
     */
    void displayBooks() const {
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Genre: " << book.getGenre() << ", Year: " << book.getPublicationYear();
            if (book.getIsBorrowed()) {
                cout << " [Borrowed]";
            }
            cout << endl;
        }
    }

    /**
     * Wypożycza książkę.
     *
     * @param title Tytuł książki do wypożyczenia.
     * @return True, jeśli książka została wypożyczona, w przeciwnym razie False.
     */
    bool borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title && !book.getIsBorrowed()) {
                book.borrow();
                return true;
            }
        }
        return false;
    }

    /**
     * Zwraca książkę.
     *
     * @param title Tytuł książki do zwrotu.
     * @return True, jeśli książka została zwrócona, w przeciwnym razie False.
     */
    bool returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title && book.getIsBorrowed()) {
                book.returnBook();
                return true;
            }
        }
        return false;
    }
};

// Definicja klasy User
class User {
private:
    string username;
    vector<Book> borrowed_books;

public:
    /**
     * Konstruktor klasy User.
     *
     * @param name Nazwa użytkownika.
     */
    User(string name) : username(name) {}

    /**
     * Wypożycza książkę.
     *
     * @param book Książka do wypożyczenia.
     */
    void borrowBook(Book& book) {
        book.borrow();
        borrowed_books.push_back(book);
    }

    /**
     * Zwraca książkę.
     *
     * @param book Książka do zwrotu.
     */
    void returnBook(Book& book) {
        book.returnBook();
        for (auto it = borrowed_books.begin(); it != borrowed_books.end(); ++it) {
            if (it->getTitle() == book.getTitle() && it->getAuthor() == book.getAuthor()) {
                borrowed_books.erase(it);
                break;
            }
        }
    }

    /**
     * Wyświetla wszystkie wypożyczone książki przez użytkownika.
     */
    void displayBorrowedBooks() const {
        for (const auto& book : borrowed_books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
        }
    }
};

/**
 * Funkcja wyświetlająca menu i obsługująca interakcję z użytkownikiem.
 *
 * @param library Obiekt klasy Library.
 */
void menu(Library& library) {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Dodaj książkę\n";
        cout << "2. Usuń książkę\n";
        cout << "3. Szukaj książki\n";
        cout << "4. Wyświetl wszystkie książki\n";
        cout << "5. Wypożycz książkę\n";
        cout << "6. Zwróć książkę\n";
        cout << "7. Wyjdź\n";
        cout << "Wybierz opcję: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author, genre;
                int year;
                cout << "Tytuł: ";
                cin.ignore();
                getline(cin, title);
                cout << "Autor: ";
                getline(cin, author);
                cout << "Gatunek: ";
                getline(cin, genre);
                cout << "Rok wydania: ";
                cin >> year;
                library.addBook(Book(title, author, genre, year));
                break;
            }
            case 2: {
                string title;
                cout << "Tytuł książki do usunięcia: ";
                cin.ignore();
                getline(cin, title);
                vector<Book> result = library.searchBooks(title);
                if (!result.empty()) {
                    library.removeBook(result[0]);
                    cout << "Książka została usunięta.\n";
                } else {
                    cout << "Książka nie znaleziona.\n";
                }
                break;
            }
            case 3: {
                string keyword;
                cout << "Słowo kluczowe: ";
                cin.ignore();
                getline(cin, keyword);
                vector<Book> result = library.searchBooks(keyword);
                for (const auto& book : result) {
                    cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Genre: " << book.getGenre() << ", Year: " << book.getPublicationYear();
                    if (book.getIsBorrowed()) {
                        cout << " [Borrowed]";
                    }
                    cout << endl;
                }
                break;
            }
            case 4:
                library.displayBooks();
                break;
            case 5: {
                string title;
                cout << "Tytuł książki do wypożyczenia: ";
                cin.ignore();
                getline(cin, title);
                if (library.borrowBook(title)) {
                    cout << "Książka została wypożyczona.\n";
                } else {
                    cout << "Książka jest już wypożyczona lub nie istnieje.\n";
                }
                break;
            }
            case 6: {
                string title;
                cout << "Tytuł książki do zwrotu: ";
                cin.ignore();
                getline(cin, title);
                if (library.returnBook(title)) {
                    cout << "Książka została zwrócona.\n";
                } else {
                    cout << "Książka nie była wypożyczona lub nie istnieje.\n";
                }
                break;
            }
            case 7:
                cout << "Wyjście.\n";
                break;
            default:
                cout << "Nieprawidłowa opcja. Spróbuj ponownie.\n";
        }
    } while (choice != 7);
}

/**
 * Funkcja główna programu.
 *
 * @return Kod wyjścia.
 */
int main() {
    Library library;
    menu(library);
    return 0;
}
