#ifndef PROMPT_H
#define PROMPT_H
#include <iostream>

using namespace std;

class Prompt
{
private:
	static void printMsg(string);
public:   
   static void input(string , int &);
   static void input(string , double &);
   static void input(string , string &);
};

#endif