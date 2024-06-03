# Project_podst
Temat: Aplikacja do zarządzania biblioteką

Opis projektu: Aplikacja będzie umożliwiała zarządzanie książkami w bibliotece. Użytkownik będzie mógł dodawać nowe książki, usuwać istniejące, wyszukiwać książki według różnych kryteriów (np. tytuł, autor, gatunek) oraz edytować informacje o książkach. Dodatkowo, będzie możliwość zarządzania wypożyczeniami, czyli rejestrowanie, przedłużanie i zwracanie wypożyczonych książek.

Opis hierarchii klas:

Klasa Book: Reprezentuje pojedynczą książkę. Zawiera pola takie jak tytuł, autor, gatunek, rok wydania, status wypożyczenia itp.
Klasa Library: Zarządza zbiorami książek. Zawiera metody do dodawania, usuwania, wyszukiwania i edycji książek. Wykorzystuje obiekty klasy Book.
Klasa User: Reprezentuje użytkownika biblioteki. Może wypożyczać książki.
Klasa Loan: Przechowuje informacje o wypożyczonych książkach, takie jak data wypożyczenia i termin zwrotu.
Enkapsulacja: Enkapsulacja będzie stosowana w klasach Book, Library i User, aby ukryć szczegóły implementacyjne i zapewnić bezpieczny dostęp do danych poprzez odpowiednie metody dostępowe.
Dziedziczenie: Dziedziczenie można zastosować, tworząc np. klasy pochodne od klasy Book dla konkretnych gatunków książek (np. FictionBook, NonFictionBook) lub klasy pochodne od klasy User dla różnych typów użytkowników (np. Student, Teacher).
Polimorfizm: Polimorfizm może być wykorzystany poprzez nadpisanie metod w klasach pochodnych, na przykład w klasie Loan dla różnych typów wypożyczeń.
Komunikacja z użytkownikiem: Interakcja z użytkownikiem może odbywać się poprzez konsolę sterowaną klawiszami. Użytkownik będzie mógł wybierać opcje z menu, wprowadzać dane i otrzymywać odpowiedzi od aplikacji.
