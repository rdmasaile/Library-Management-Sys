#include "HelperFunc.h"
#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;

void split(string& str,char splitter,vector<string> *to){
	
	string value = string();
	bool foundS = false;
	for(int i = 0;i<str.length();i++){
		if(str[i] == splitter){
					 	
	      if (foundS){
	 			continue;
			}
			 	
			foundS = true;
			to->push_back(value);
			value = string();
			continue;
		}
	   foundS = false;
	   value += str[i];
	}
	to->push_back(value);
}

vector<string>* split(string& str,char splitter){
	
	vector<string> *to = new vector<string>();
	split(str,splitter,to);
	return to;
}

Date getCurrentDate(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	return Date(*ltm);
}
