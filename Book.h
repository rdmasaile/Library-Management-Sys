#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "Date.h"

using namespace std;

class Book
{
private:
   string ISBN;
   string author;
   string title;
   string category;
   Date dateOfPublication;
   int edition;   
public:
   Book(string,string,string,string,string,int);
   Book(string);
   string getISBN();
   string getAuthor();
   string getTitle();
   string getCategory();
   Date getDateOfPublication();
   int getEdition();

};

#endif