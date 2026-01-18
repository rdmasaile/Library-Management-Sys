#include "IssuedBook.h"
#include "Date.h"
#include <iostream>
#include "Book.h"
#include <ctime>
#include "HelperFunc.h"

using namespace std;

IssuedBook::IssuedBook(Book *b)
{
   book = b;
   ReturnDate = getCurrentDate() + 7;
}
IssuedBook::IssuedBook(Book *b, string date)
{

   book = b;
   ReturnDate = Date(date);
   //   ReturnDate.setDay(24);
}

// void IssuedBook::setDuration(int duration)
//{
//    if (duration > 7)
//    {
//       cout << "Duration should be less than or equal to 7!!!" << endl;
//       return;
//    }
//    Duration = duration;
// }

Book *IssuedBook::getBook()
{
   return book;
}
// string IssuedBook::getMemberId()
//{
//    return MemberId;
// }
// string IssuedBook::getIssuedBy()
//{
//    return IssuedBy;
// }

/*
Calculate amount owed based on days overdue
   5.0 per day
*/
double IssuedBook::getAmount()
{
   int days = getCurrentDate() - getReturnDate();
   if (days <= 0)
   {
      return 0;
   }

   return 5.0 * days;
}
// int IssuedBook::getDuration()
//{
//    return Duration;
// }
// Date IssuedBook::getIssuedDate()
//{
//    return IssuedDate;
// }
Date IssuedBook::getReturnDate()
{
   return ReturnDate;
}