#include "MembersList.h"
#include <list>
#include <vector>
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <exception>
#include "Member.h"
#include "HelperFunc.h"

using namespace std;

vector<Member> MembersList::getMembers(){
	return members;
}

void MembersList::addMember(Member member){
   members.push_back(member);
}

void MembersList::addMember(string record){
   this->addMember(Member(record));
}

void MembersList::displayMembers(){
	cout << endl;
   cout << left << setw(8) << "Id"
        << left << setw(30) << "Name"
        << left << setw(30) << "Address"
        << left << setw(6) << "Gender"
		  << endl;
	cout <<setfill('-')<< left<<setw(80)<<""<<endl;
   for (Member member : members)
   {
      cout <<setfill(' ')<< left << setw(8) << member.getId()
           <<setfill(' ')<< left << setw(30) << member.getFullName()
           <<setfill(' ')<< left << setw(30) << member.getAddress()
           <<setfill(' ')<< left << setw(6) << member.getGender()
			  << endl;
   }
}

Member* MembersList::getMemberById(string id){
   for(int i = 0; i < members.size();i++){
   	if(members[i].getId() == id){
   		return &members[i];
		}
	}
   return NULL;
}

void MembersList::removeMemberById(string id){
	for(int i=0;i<members.size();i++){
   	if(members[i].getId() == id){
   		members.erase(members.begin()+i);
   		cout<<"Done ..."<<endl;
   		return;
		}
	}
	cout<<"Member Not Found!!!"<<endl;
}
vector<Member> MembersList::getOwingMembers(){
	vector<Member> owingMembers;
	for(Member m : members){
		if(m.getAmountOwing() > 0)
			owingMembers.push_back(m);
//		for(IssuedBook ibook:m.getIssuedBooks()){
//			if(ibook.getAmount() > 0){
//				owingMembers.push_back(m);
//			}
//		}
	}
	return owingMembers;
}

void MembersList::displayOwingMembers(){
	vector<Member> owingMembers = getOwingMembers();
	
	if(owingMembers.empty()){
		cout<<endl<<"*******NO OWING MEMBERS********"<<endl;
		return;
	}

	sort(owingMembers.begin(),owingMembers.end(),[](Member m1,Member m2){return m1.getAmountOwing()>m2.getAmountOwing();});
	cout << endl;
	cout << left << setw(25) << "Book Title"
        << left << setw(15) << "Member ID"
        << left << setw(25) << "Member Name"
        << left << setw(15) << "Amount Owing(M)"
		  << endl;
	cout <<setfill('-')<< left<<setw(90)<<""<<endl;
	for(Member m:owingMembers){
		for(IssuedBook ibook : m.getIssuedBooks()){
			if(ibook.getAmount() == 0)
				continue;
			cout <<setfill(' ')<< left << setw(25) << ibook.getBook()->getTitle()
		        <<setfill(' ')<< left << setw(15) << m.getId()
		        <<setfill(' ')<< left << setw(25) << m.getFullName()
		        <<setfill(' ')<< left << setw(15) << ibook.getAmount()<<m.getAmountOwing()
				  << endl;
		}
	}
}

int MembersList::operator [](int index){
	return index;
}
