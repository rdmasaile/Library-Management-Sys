#include "BooksList.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>
#include <exception>

using namespace std;

vector<Book> BooksList::getBooks(){
	return books;
}

void BooksList::addBook(Book book){
   books.push_back(book);
}

void BooksList::addBook(string record){
	this->addBook(Book(record));
}


void BooksList::displayBooks(){
	if(books.empty()){
		cout<<endl<<"******NO BOOK RECORDS******"<<endl;
		return;
	}
	cout << endl;
	cout << left << setw(8) << "ISBN"
        << left << setw(25) << "Title"
        << left << setw(20) << "Author"
        << left << setw(20) << "Category"
        << left << setw(15) << "Edition"
		  << endl;
	cout <<setfill('-')<< left<<setw(90)<<""<<endl;

   for (Book book : books)
   {
      cout <<setfill(' ')<< left << setw(8) << book.getISBN()
           <<setfill(' ')<< left << setw(25) << book.getTitle()
           <<setfill(' ')<< left << setw(20) << book.getAuthor()
           <<setfill(' ')<< left << setw(20) << book.getCategory()
           <<setfill(' ')<< left << setw(15) << to_string(book.getEdition())+"th Edition"
			  << endl;
   }
}
void BooksList::displayBooks(int &val){
	orderBy(val);
	displayBooks();
}
Book *BooksList::getBookByISBN(string isbn){
   for (int i = 0; i < books.size(); i++)
   {
      if (books[i].getISBN() == isbn)
      {
         return &books[i];
      }
   }
   return NULL;
}

void BooksList::deleteBookRecord(string isbn){
	
	for(int i=0;i<books.size();i++){
   	if(books[i].getISBN() == isbn){
   		books.erase(books.begin()+i);
   		cout<<endl<<"******Successfully deleted******"<<endl;			
   		return;			
		}
	}
	cout<<endl<< "*******BOOK NOT FOUND!!!********"<<endl;
}

BooksList* BooksList::search(string key){
	BooksList* searchList = new BooksList();
	
	Book* book1 = getBookByISBN(key);
	
	if(book1 != NULL){
		searchList->addBook(*book1);
		return searchList;
	}
	
	bool found = false;
	
	//Search by Title
	for(Book book:books){
		if(book.getTitle() == key){
			found = true;
			searchList->addBook(book);
		}
	}
	if(found){
		return searchList;
	}
	
	//Search by Author
	for(Book book:books){
		if(book.getAuthor() == key){
			found = true;
			searchList->addBook(book);
		}
	}
	if(found){
		return searchList;
	}
	
	//Search by Category
	for(Book book:books){		
		if(book.getCategory() == key){
			found = true;
			searchList->addBook(book);
		}
	}
	if(found){
		return searchList;
	}
	
	return NULL;
}

void BooksList::orderBy(int val){
	if(val == 1){
		sort(books.begin(),books.end(),[](Book b1,Book b2){
			return b1.getISBN() < b2.getISBN();
		});
	}
	else if(val == 2){
		sort(books.begin(),books.end(),[](Book b1,Book b2){	
		 	return b1.getTitle() < b2.getTitle();
		});
	}
	else if(val == 3){
		sort(books.begin(),books.end(),[](Book b1,Book b2){
			return b1.getAuthor() < b2.getAuthor();
		});
	}
	else if(val == 4){
		sort(books.begin(),books.end(),[](Book b1,Book b2){
			return b1.getCategory() < b2.getCategory();
		});
	}
} 
