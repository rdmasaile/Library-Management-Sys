#ifndef MEMBERSLIST_H
#define MEMBERSLIST_H
#include <vector>
#include <iostream>
#include "Member.h"

using namespace std;

class MembersList
{
private:
   vector<Member> members;

public:
	vector<Member> getMembers();
   void addMember(Member);
   void addMember(string);
   void displayMembers();
   Member* getMemberById(string);
   void removeMemberById(string);
   void sortByMostOwing(vector<Member>*);
   vector<Member> getOwingMembers();
   void displayOwingMembers();
   int operator[](int);
};

#endif