#include <iostream>
#include <string>
#include "algorithm"
using namespace std;

struct Book{
    string title;
    string author;
    int year;
    int copies;
};

bool comparison(const Book& book1, const Book& book2){
    return book1.title < book2.title;
};

int main(){
    cout << "Введите количество книг в библиотеке: ";
    int numBooks;
    cin >> numBooks;

    // Выделяем память для хранения информации о книгах
    Book* books = new Book[numBooks];

    for (int i = 0; i < numBooks; i++) {
        cout << "Введите название книги " << i + 1 << ": ";
        cin.ignore();
        getline(cin, books[i].title);

        cout << "Введите автора книги " << i + 1 << ": ";
        getline(cin, books[i].author);

        cout << "Введите год издания книги " << i + 1 << ": ";
        cin >> books[i].year;

        cout << "Введите количесво копий " << i + 1 << ": ";
        cin >> books[i].copies;
    }

    // Сортируем книги по названию (алфавитный порядок)
    sort(books, books + numBooks, comparison);

    // Выводим список отсортированных книг
    cout << "Список книг в алфавитном порядке:\n";
    for (int i = 0; i < numBooks; i++) {
        cout << i + 1 << ". " << books[i].title
        << " - Автор: " << books[i].author
        << ", Год издания: " << books[i].year
        << ", Количество копий: " << books[i].copies
        << endl;
    }

    // Освобождаем память, выделенную для массива книг
    delete[] books;

    return 0;
}