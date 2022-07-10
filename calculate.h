#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

// this outputs the number representaion of the char 
int num(char c)
{
int n=0;
if (c == '0')
n = 0;

if (c == '1')
n = 1;

if (c == '2')
n = 2;

if (c == '3')
n = 3;

if (c == '4')
n = 4;

if (c == '5')
n = 5;

if (c == '6')
n = 6;

if (c == '7')
n = 7;

if (c == '8')
n = 8;

if (c == '9')
n = 9;

return n;

}

bool isDigit(char chr)
{ 
  return (chr >= '0' && chr <= '9');
}
bool isOp(char c)
{
  return (c == '+' || c == '-' || c == '*' ||  c == '/' || c == '(' || c == ')');
}

// this will get the order in which to perform operations

int order(char c)
{
 switch(c) 
 {
   case '+':
   case '-': return 1;
   case '*':
   case '/':return 2;
   case '(':
   case ')':return 3;
   default: return -1;
 }


}

int operate(int a, int b, char op)
{
  if (op == '+') return a+b;
  if (op == '-') return a-b;
  if (op == '*') return a*b;
  return a/b;

}
int eval(string s)
 {



   Stack<int> value;
   Stack<char> operation;
   int number = 0;
   int position = 0;


   while(position < s.length())
   {
     char place = s[position];
     if (isDigit(place)) // in case the number is a double digit 
     {
       number = (number * 10) + num(place); // this multiplies by 10 then adds the integer value representation of the next char
     }
     else if (isOp(place)) // in case the char is '(' it waits to find the matching ')'
     {
      if(place == '(')
       {
         operation.push(place);
         number = 0;
       }
       else if (value.isEmpty())
       {
         value.push(number);
         operation.push(place);
         number = 0;
       }else if(place == ')') 
       {
         value.push(number); // when it finds the close ')' push the last number
         while(operation.showTop() != '(')
         {
           // these variables will store the pop values but the stack will not directly pop those values
           place = operation.pop();
           number = value.pop();
           int prev = value.pop();
           // now it operates and will store the value as the new number
           number = operate(prev, number, place);
           value.push(number);  
         }
         // I directly pop the stack
         operation.pop(); 
         value.pop();
       }
       else // then find the order of operation
       {  // store the previous operation which is at the top of the stack
          char prev = operation.showTop();
          // now evaluate the previous from the current
          // operation
          if (order(place) > order(prev))
          {
            value.push(number);
            operation.push(place);
            number = 0;
          }else // if the order is not greater then operate the values
          { 
            // the previous number is in the top of the stack
            int prevnum = value.pop();
            int prevop = operation.pop();
            prevnum = operate(prevnum, number, prevop);
            value.push(prevnum);
            operation.push(place);
            number = 0;
          }
       }
     
     }
     position++;
   }
   // by default it calculates whats in the stack
  while(!operation.isEmpty())
   {
    
     int prevn = value.pop();
     char place = operation.pop();
     number = operate(prevn, number, place);
   }
   return number;
 }



 
