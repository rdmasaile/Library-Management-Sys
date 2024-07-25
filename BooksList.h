#ifndef BOOKSLIST_H
#define BOOKSLIST_H
#include <vector>
#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

class BooksList
{
private:
   vector<Book> books;
	
public:
	vector<Book> getBooks();
   void addBook(Book);
   void addBook(string);
   void displayBooks();
   void displayBooks(int &);
   Book* getBookByISBN(string ISBN);
   BooksList* search(string);
   void deleteBookRecord(string);
   void orderBy(int);
};

#endif