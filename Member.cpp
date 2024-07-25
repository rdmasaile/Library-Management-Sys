#include "Member.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "IssuedBook.h"
#include "HelperFunc.h"

using namespace std;

Member::Member(){}

Member::Member(string ID, string fname, string addr, string g){
   id = ID;
   name = fname;
   address = addr;
   gender = g;
}

//Member::Member(string ID, string fname, string addr, string g, vector<IssuedBook> *issuedBooks)
//{
//   id = ID;
//   name = fname;
//   address = addr;
//   gender = g;
//   IssuedBooks = issuedBooks;
//}

Member::Member(string record){
	vector<string>* data = split(record,',');
	
	id = data->at(0);
	name = data->at(1);
	address = data->at(2);
	gender = data->at(3);
}

void Member::setId(string ID){
   id = ID;
}

string Member::getId(){
   return id;
}

void Member::setFullName(string fname){
   name = fname;
}

string Member::getFullName(){
   return name;
}

void Member::setAddress(string addr){
   address = addr;
}

string Member::getAddress(){
   return address;
}

void Member::setGender(string g){
   gender = g;
}

string Member::getGender(){
   return gender;
}

vector<IssuedBook> Member::getIssuedBooks(){
	return IssuedBooks;
}

double Member::getAmountOwing(){
	double totalAmount = 0;
	for(IssuedBook ibook: IssuedBooks){
		totalAmount += ibook.getAmount();
	}
	return totalAmount;
}

string Member::toString(){
   string message = id + "\t" + name + "\t" + address + "\t" + gender;
   return message;
}

void Member::addIssuedBook(IssuedBook issuedBook){
//	cout<<"Inside"<<endl;
   if (IssuedBooks.size() >= 3)
   {
      throw ("******Maximum number of borrowed books is reached!!!******");
   }

   for (auto itr = IssuedBooks.begin(); itr != IssuedBooks.end(); ++itr)
   {
      if (itr->getBook()->getISBN() == issuedBook.getBook()->getISBN())
      {
         throw ("******This book is already borrowed!!!******");
      }
      if(itr->getAmount() > 0){
      	throw ("******The member has an overdue!!!******");
		}
   }

   IssuedBooks.push_back(issuedBook);
}
void Member::addIssuedBook(IssuedBook issuedBook,string file){
	IssuedBooks.push_back(issuedBook);
}

void Member::removeIssuedBook(){
   displayIssuedBooks();
   if(IssuedBooks.size()==0){
   	return;
	}
   string isbn;
   cout << "Enter the ISBN of the book to Returned: ";
   cin>>isbn;
   for(int i=0;i<IssuedBooks.size();i++){
   	if(IssuedBooks[i].getBook()->getISBN() == isbn){
   		IssuedBooks.erase(IssuedBooks.begin()+i);
   		cout<<"Done ..."<<endl;			
   		return;			
		}
	}
   
   cout<<endl<<"*******Book Not Found!!!*******"<<endl;
}

void Member::displayIssuedBooks(){
   if (IssuedBooks.empty())
   {
      cout <<endl<< "*******NO ISSUED BOOKS*******" << endl;
      return;
   }

   cout<<endl
		<< left << setw(10) << "ISBN"
      << left << setw(25) << "Title"
      << left << setw(15) << "Amount(M)"
      << left << setw(15) << "Return Date" 
		<< endl;
	cout <<setfill('-')<< left<<setw(70)<<""<<endl;
	cout << setfill(' ')<<endl;
   for (IssuedBook issuedBook : IssuedBooks)
   {
      cout << left << setw(10) << issuedBook.getBook()->getISBN()
           << left << setw(25) << issuedBook.getBook()->getTitle()
           << left << setw(15) << issuedBook.getAmount()
           << left << setw(15) << issuedBook.getReturnDate().toString() << endl;
   }
}
