#include <iostream>
#include "calculate.h"
#include <iomanip>
#include <string>
using namespace std;


int main() 
{
  // this works with 3+ digit numbers like 100 or 1000 
  string expression;
  cout << "Write an expression to be evaluated." << endl;
  getline(cin,expression);
  cout << eval(expression);

  



return 0;
}











    