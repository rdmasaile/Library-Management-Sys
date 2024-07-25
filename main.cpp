#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <vector>
#include "MembersList.h"
#include "IssuedBook.h"
#include "BooksList.h"
#include "Member.h"
#include <ctime>
#include "Prompt.h"
#include "HelperFunc.h"


using namespace std;

void addMember();
void menu(int &);
void issueBook();
void loginPage(int&);
void loadData();
void saveData();
void memberMenu(int&);

class User{
private:
	string Id;
	string Username;
	string Password;
public:
	User(){

	};
	User(string id,string username,string password){
		Id = id;
		Username = username;
		Password = password;
	}
	User(string record){
		vector<string> *data = split(record,',');
		Id = data->at(0);
		Username = data->at(1);
		Password = data->at(2);
	}
	string getId(){
		return Id;
	}
	string getUsername(){
		return Username;
	}
	string getPassword(){
		return Password;
	}
};

static MembersList *members = new MembersList();

static BooksList *books = new BooksList();

//static User* authUser = new User();
//static Member* authMember;

int main()
{
   int option = 0;
   int type = 0;
   bool authenticated = false;

   loginPage(type);
   

   if(type == 1){
//		string username;
//		string password;
//
//		Prompt::input("Enter Username: ",username);
//		Prompt::input("Enter Password: ",password);
//
//		ifstream librariansFile("librarians.txt");
//
//		//Record in the Form: ID,Username,Password
//		if(librariansFile.is_open()){
//			string record;
//			while(getline(librariansFile,record)){
//				User user(record);
//				if(user.getUsername() == username && user.getPassword() == password){
//					authenticated = true;
//					authUser = &user;
//					break;
//				}
//			}
//			librariansFile.close();
//		}
//
//		if(!authenticated){
//			cout << endl <<"Invalid Username or Password!!!"<<endl;
//			return 0;
//		}

		loadData();

	   while (true)
	   {
	      menu(option);

	      if (option == 1){
	         string record;
	         Prompt::input("Enter all book details(ISBN,Title,Author,Category,Date of Publication,Edition) separated by Comma(,): ",record);

				try{
		         books->addBook(record);
		         cout<< "Successfully Added"<<endl;
		      }catch(exception &e){
					cout << "An Error occured. Check your input!!!"<<endl;
				}

	      }
	      else if (option == 2){
	      	books->displayBooks();
	      	string isbn;
	         Prompt::input("Enter the ISBN of the book to modify: ",isbn);
	         Book *book = books->getBookByISBN(isbn);
	         if (book == NULL){
					cout << "*******BOOK NOT FOUND*******"<<endl;
					continue;
				}

		 		string record;
	         Prompt::input("Enter all book details(ISBN,Title,Author,Category,Date of Publication,Edition) separated by Comma(,): ",record);

	         try{
		         *book = Book(record);
		         cout<< "Successfully Modified"<<endl;
		      }catch(exception &e){
					cout << "An Error occured. Check your input!!!"<<endl;
				}
	      }
	      else if (option == 3){
	      	books->displayBooks();
	      	string isbn;
	         Prompt::input("Enter the ISBN of the book to delete: ",isbn);
	      	books->deleteBookRecord(isbn);
	      }
	      else if (option == 4){
	      	string key;
	      	Prompt::input("Enter Search Value: ",key);
	      	BooksList* res = books->search(key);
	      	if(res != NULL){
					res->displayBooks();
					continue;
				}
	         cout<<endl<<"*******BOOK NOT FOUND!!!*******"<<endl;
	      }
	      else if (option == 5){
	      	books->displayBooks();
	         string isbn;
	         Prompt::input("Enter the ISBN of the book to issue: ",isbn);
				Book *book = books->getBookByISBN(isbn);
    			if(book == NULL){
					cout <<endl<< "*******BOOK NOT FOUND!!!*******"<<endl;
					continue;
				}
//				while(book == NULL){
//				   cout<<"Book Not Found!!!"<<endl;
//					Prompt::input("Enter the ISBN of the book to issue again: ",isbn);
//					book = books->getBookByISBN(isbn);
//				}
				members->displayMembers();
			   string memberId;
	         Prompt::input("Enter the Member ID to issue a book to: ",memberId);
	         Member* member = members->getMemberById(memberId);
//	         while(member == NULL){
//	         	cout << "Member not Found!!!"<<endl;
//	         	Prompt::input("Enter the Member ID to issue a book to again: ",memberId);
//	         	member = members->getMemberById(memberId);
//				}
				if(member == NULL){
					cout <<endl<< "*******MEMBER NOT FOUND!!!*******"<<endl;
					continue;
				}
//		 	   double amount;
//				int duration;
//				Prompt::input("Enter the amount: M",amount);
//				Prompt::input("Enter the Duration in days less than 7: ",duration);
				try{
					member->addIssuedBook(IssuedBook(book));
					cout<<endl<<"*******Successfully Issued!!*******"<<endl;
				}catch(char const* e){
					cout<<endl<<e<<endl;
				}
				
				
	      }
	      else if(option == 6){
				members->displayMembers();
	         string memberId;
	         Prompt::input("Enter the Member ID of the Member who returned a book to: ",memberId);
	         Member* member = members->getMemberById(memberId);
//	         while(member == NULL){
//	         	cout << "MEMBER NOT FOUND!!!"<<endl;
//	         	Prompt::input("Enter the Member ID of the Member who returned a book to again: ",memberId);
//	         	member = members->getMemberById(memberId);
//				}
				if(member == NULL){
					cout <<endl<< "*******MEMBER NOT FOUND!!!*******"<<endl;
					continue;
				}
		 	   member->removeIssuedBook();
			}
		   else if(option == 7){
		   	string record;
				Prompt::input("Enter All Member details(ID,Full Name,Address,Gender) separated by Comma(,): ",record);
				try{
			   	members->addMember(record);
					cout<<"Successfully Added."<<endl;
			   }catch(exception& e){
					cout <<endl <<"*******An Error occured. Check your input!!!*******"<<endl;
				}
			}
		   else if(option == 8){
		   	members->displayMembers();
		   	string memberId;
				Prompt::input("Enter Member ID to Modify: ",memberId);
				Member* member = members->getMemberById(memberId);

//	         while(member == NULL){
//	         	cout << "MEMBER NOT FOUND!!!"<<endl;
//	         	Prompt::input("Enter Member ID again: ",memberId);
//	         	member = members->getMemberById(memberId);
//				}
				if(member == NULL){
					cout <<endl<< "*******MEMBER NOT FOUND!!!*******"<<endl;
					continue;
				}
				string record;
		      Prompt::input("Enter all Member details(ID,Full Name,Address,Gender) separated by Comma(,): ",record);

				try{
			   	*member = Member(record);
					cout<<"Successfully Modified."<<endl;
			   }catch(exception& e){
					cout <<endl<< "*******An Error occured. Check your input!!!*******"<<endl;
				}
			}
			else if(option == 9){
				members->displayMembers();
				string memberId;
				Prompt::input("Enter Member ID to Modify: ",memberId);
				members->removeMemberById(memberId);
			}
			else if(option == 10){
				members->displayOwingMembers();
			}
	      else{
	         break;
	      }
		}

   }
	else if(type == 2){
		
		loadData();
		
//		string id;
//		string name;
//		
//		Prompt::input("Enter ID: ",id);
//		Prompt::input("Enter Member Name: ",name);
//
//		Member* m = members->getMemberById(id);
//		if(m == NULL || m->getFullName() != name){
//			cout << endl <<"Invalid Id or Name!!!"<<endl;
//			return 0;
//		}
//		
//		authMember = m;
		
   	while(true){

			memberMenu(option);
			if(option == 1){
				cout<<endl<<"1. Order ISBN"<<endl
					 <<"2. Order Book Title"<<endl
					 <<"3. Order Book Author"<<endl
					 <<"4. Order Book Category"<<endl;
				Prompt::input("\nPlease choose option to order books by: ",option);
				books->displayBooks(option);
			}
			else if(option == 2){
				string key;
	      	Prompt::input("\nEnter Search Value: ",key);
	      	BooksList* res = books->search(key);
	      	if(res != NULL){
					res->displayBooks();
					continue;
				}
	         cout<<endl<<"*******BOOK NOT FOUND!!!*******"<<endl;
			}
//			else if(option == 3){
//				authMember->displayIssuedBooks();				
//			}
			else{
				break;
			}
		}
	}else{

	}
	saveData();
   return 0;
}

void loadData(){

	//Record in the form: ID,Full Name,Address,Gender
	ifstream membersFile("members.txt");
	if(membersFile.is_open()){
		string record;
		while(getline(membersFile,record)){
			try{
				if(record.length() == 0)
					continue;
    			members->addMember(record);
			}catch(exception &e){
				cout<<endl<<"*******Error occured. Check the Member record.*******"<<endl;
				break;
			}
		}
		membersFile.close();
	}else{
		cout<<"Unable to open file: members.txt"<<endl;
	}
	
	//Record in the form: ISBN,Title,Author,Category,edition
	ifstream booksFile("books.txt");
	if(booksFile.is_open()){
		string record;
		while(getline(booksFile,record)){
			try{
				books->addBook(record);
			}catch(exception &e){
				cout<<endl<<"*******Error occured. Check the book record.*******"<<endl;
			}
		}
		booksFile.close();
	}else{
		cout<<endl<<"*******Unable to open file: books.txt*******"<<endl;
	}
	
	//Record in the form: ISBN,memberID,Return Date
	ifstream issuedBooksFile("issued_books.txt");
	if(issuedBooksFile.is_open()){
		string record;
		while(getline(issuedBooksFile,record)){
			vector<string> *data = split(record,',');
			
			Book *book = books->getBookByISBN(data->at(0));
			if(book == NULL){
				continue;
			}
			Member *member = members->getMemberById(data->at(1));
			if(member == NULL){
				continue;
			}
			
			member->addIssuedBook(IssuedBook(book,data->at(2)),"Load");
		}
		issuedBooksFile.close();
	}else{
		cout<<endl<<"Unable to open file: issued_books.txt"<<endl;
	}
}

void loginPage(int& type){
	cout<<endl;
	cout << setfill('_')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<right<<setw(50) <<"HA TSOLO LIBRARY MANAGEMENT SYSTEM"<<endl;
	cout << setfill('_')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<right<<setw(52) <<">>PLEASE CHOOSE ANY OPTION TO LOGIN<<"<<endl;
	cout << setfill('_')<<setw(70)<<""<<endl;
	cout << "1. Libraian"<<endl;
	cout << "2. Member"<<endl;
	cout << "3. Exit Application"<<endl;
	Prompt::input("Enter your choice(1-3): ",type);
}

void menu(int &option){
	cout<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<right<<setw(50) <<"HA TSOLO COMMUNITY CENTER LMS"<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<right<<setw(60) <<"WHERE QUALITY LIBRARY SERVICES CANNOT BE MATCHED"<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<right<<setw(59) <<"WELCOME TO HA TSOLO LIBRARY MANAGEMENT SYSTEM"<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<right<<setw(40) <<"Main Menu"<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
   cout<< setfill(' ')<< left << setw(40) <<"1. Add Book Record"
   	 << setfill(' ')<< left << setw(30) <<"7. Add a new Member" << endl
	    << setfill(' ')<< left << setw(40) <<"2. Modify Book Record"
	    << setfill(' ')<< left << setw(30) <<"8. Modify Member Record" << endl
	    << setfill(' ')<< left << setw(40) <<"3. Delete Book Record"
	    << setfill(' ')<< left << setw(30) <<"9. Delete Member Record" << endl
	    << setfill(' ')<< left << setw(40) <<"4. Search Book Record"
	    << setfill(' ')<< left << setw(30) <<"10. Display all owing Members" << endl
	    << setfill(' ')<< left << setw(30) <<"5. Issue Book" << endl
	    << setfill(' ')<< left << setw(30) <<"6. Return a Book"<<endl
	    << setfill(' ')<< right << setw(40) <<"11. Exit Application"<<endl
		 << endl;
	Prompt::input("Please Enter your choice (1-11): ",option);
}

void issueBook(){
   // co
}

void memberMenu(int& option){
	cout<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<setw(60) <<"********************Welcome Member********************"<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<setw(50) <<">>Please choose an option<<"<<endl;
	cout << setfill('-')<<setw(70)<<""<<endl;
	cout << setfill(' ')<<endl;
	cout << "1. View Book List"<<endl;
	cout << "2. Search for a Book"<<endl;
//	cout << "3. View Borrowed Books"<<endl;
	cout << "3. Exit Application"<<endl;
	Prompt::input("\nEnter your choice(1-3): ",option);

}

void addMember(){
   string id;
   string name;
   string address;
   string gender;

   Prompt::input("Enter Member ID: ",id);
   Prompt::input("Enter Member Name: ",name);
   Prompt::input("Enter Member Address: ",address);
   Prompt::input("Enter Member Gender: ",gender);

   members->addMember(Member(id, name, address, gender));
   cout <<endl<< "Done" << endl;
}

void saveData(){

	//Record in the form: ID,Name,Address,Gender
	ofstream membersFile("members.txt");
	if(membersFile.is_open()){
		for(Member member:members->getMembers()){
			membersFile << member.getId()<<","<<member.getFullName()<<","<<member.getAddress()<<","<<member.getGender()<<endl;
		}
		membersFile.close();
	}else{
		cout<<"Unable to open file: members.txt"<<endl;
	}

	//Record in the form: ISBN,Title,Author,Category,edition
	ofstream booksFile("books.txt");
	if(booksFile.is_open()){
		for(Book book:books->getBooks()){
			booksFile << book.getISBN()<<","<<book.getTitle()<<","<<book.getAuthor()<<","<<book.getCategory()<<","<<book.getDateOfPublication().toString()<<","<<book.getEdition()<<endl;
		}
		booksFile.close();
	}else{
		cout<<"Unable to open file: books.txt"<<endl;
	}

	//Record in the form: ISBN,memberID,Amount,issue_date,duration,issuedBy
	ofstream issuedBooksFile("issued_books.txt");
	if(issuedBooksFile.is_open()){
		for(Member member:members->getMembers()){
			for(IssuedBook ibook : member.getIssuedBooks()){
				issuedBooksFile << ibook.getBook()->getISBN()<<","<<member.getId()<<","<<ibook.getReturnDate().toString()<<endl;
			}
		}
		issuedBooksFile.close();

	}else{
		cout<<"Unable to open file: issued_books.txt"<<endl;
	}
}