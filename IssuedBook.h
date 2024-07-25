#ifndef ISSUEDBOOK_H
#define ISSUEDBOOK_H
#include <iostream>
#include "Book.h"

using namespace std;

class IssuedBook
{
private:
   Book* book;
//   string IssuedBy;
//   double Amount;
   Date ReturnDate;

public:
   IssuedBook(Book*);
   IssuedBook(Book*,string);

//   void setDuration(int duration);

   Book* getBook();
//   string getIssuedBy();
   double getAmount();
//   int getDuration();
//   Date getIssuedDate();
   Date getReturnDate();
};

#endif