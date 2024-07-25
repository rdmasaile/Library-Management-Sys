#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include "IssuedBook.h"
#include <vector>

using namespace std;

class Member
{
private:
   string id;
   string name;
   string address;
   string gender;
   vector<IssuedBook> IssuedBooks;
	
public:
	Member();
   Member(string, string, string, string);
//   Member(string, string, string, string, vector<IssuedBook>);
	Member(string);
   void setId(string);
   string getId();
   void setFullName(string);
   string getFullName();
   void setAddress(string);
   string getAddress();
   void setGender(string);
   string getGender();
   vector<IssuedBook> getIssuedBooks();
   double getAmountOwing();
   string toString();
   void addIssuedBook(IssuedBook);
   void addIssuedBook(IssuedBook,string);
   void removeIssuedBook();
   void displayIssuedBooks();
};

#endif