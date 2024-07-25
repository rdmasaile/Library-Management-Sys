#ifndef HELPERFUNC_H
#define HELPERFUNC_H
#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;

void split(string& str,char splitter,vector<string> *to);

vector<string>* split(string& str,char splitter);

Date getCurrentDate();

#endif