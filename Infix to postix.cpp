#include<string>
#include<iostream>
#include<stack>
#include<ctype.h>
using namespace std;

int GetOperatorWeight(char op)
{     /*Assign Weights to operators*/
  int weight = -1;
  switch(op)
  {
  case '+':
  case '-':
    weight = 1;
    break;
  case '*':
  case '/':
    weight = 2;
    break;
  case '^':
    weight = 3;
    break;
  case '(':
  case ')':
    weight = 4;
    break;
  }
  return weight;
}

int higherprecedence(char op1 , char op2)
{     /*Compares two operands, returns on with larger weight*/
  int op1Weight = GetOperatorWeight(op1);
  int op2Weight = GetOperatorWeight(op2);
  return (op1Weight>= op2Weight ?  1:0);
}

string itp(string exp)
{     /*function that converts infix to postfix*/
  int i;
  stack<char> S;
  string res;
  res.clear();
  for(i=0;i<exp.length();i++)
  {                        //Iterates over characters
    char ch=exp[i];
    if(isdigit(ch)){       //Add to result if digit
      res+=ch;
    }
    else if(GetOperatorWeight(ch) == -1){   //Add to result if not digit or supported operand
      res += ch;
    }
    else{                  //Logic for supported operands
      if(ch=='('){
        S.push(ch);
      }
      else if(ch==')')
      {
        while(!S.empty() && S.top()!='(')
        {                  //Pop and add to result till '(' encountered, or stack empty
          res += ' ';
          res+=S.top();
          S.pop();
        }
        S.pop();          //Pop to remove '('
      }
      else if(S.empty() || higherprecedence(S.top(),ch)==0){
        S.push(ch);       //Push on empty stack or if ch precedes top element
        res += ' ';
      }
      else if(higherprecedence(S.top(),ch)==1)
      {                   //Pop till '(' or lower precedence operand encountered, or stack empty
        while(!S.empty() && higherprecedence(S.top(),ch)==1 && S.top()!='('){
          res += ' ';
          res+=S.top();
          S.pop();
        }
        S.push(ch);       //Push new operand
        res += ' ';
      }
    }
  }
  while(!S.empty())
  {         //To empty stack after expression iteration completed
    res += ' ';
    res+=S.top();
    S.pop();
  }
  return res;
}
int main(){
  cout << "This program converts infix expression to postfix expression\n";
  string exp;
  cout << "Enter an infix expression :";
  cin >> exp;
  string postfix = itp(exp);
  cout << "Output = " << postfix << "\n";
}