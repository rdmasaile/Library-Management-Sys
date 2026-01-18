#include "Book.h"
#include <iostream>
#include <vector>
#include "HelperFunc.h"
#include <string>

using namespace std;

Book::Book(string isbn, string name, string writer, string cart,string date, int edi)
{
   ISBN = isbn;
   title = name;
   author = writer;
   category = cart;
   dateOfPublication = Date(date);
   edition = edi;
}

//Book::Book(int isbn){
//   ISBN = isbn;
//}
Book::Book(string record){
	vector<string> *data = split(record, ',');

   string *edi = data->data()+5;
   ISBN = data->at(0);
   title = data->at(1);
   author =  data->at(2);
   category = data->at(3);
   dateOfPublication = Date(data->at(4));
   edition = stoi(*edi);
}
string Book::getISBN()
{
   return ISBN;
}

string Book::getAuthor()
{
   return author;
}

string Book::getTitle()
{
   return title;
}

string Book::getCategory()
{
   return category;
}
Date Book::getDateOfPublication()
{
   return dateOfPublication;
}

int Book::getEdition()
{
   return edition;
}
