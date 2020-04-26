#include<string>
#include<iostream>
#include<stack>
#include<ctype.h>
using namespace std;

int GetOperatorWeight(char op)
{
  int weight = -1;      //Brackets '(', ')' will be assigned lowest weight, either increse this
  switch(op)            //Or add case for brackets too
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
    weight=3;
  }
  return weight;
}



int higherprecedence(char op1 , char op2)
{
  int op1Weight = GetOperatorWeight(op1);
  int op2Weight = GetOperatorWeight(op2);
  return (op1Weight>= op2Weight ?  1:0);
}

string itp(string exp)
{
  int i,j;                    //j unused, remove j
  stack<char> S;
  string res;
  res.clear();
  for(i=0;i<exp.length();i++)
  {
    char ch=exp[i];
    if(isdigit(ch)){
      res+=ch;
    }                   //Add check for other inputs
    else{
      if(ch=='('){
        S.push(ch);
      }
      else if(ch==')')
      {           //S.empty() true when stack empty. S.empty()!=0 false when stack not empty
        while(S.empty()!=0 && S.top()!='(') //Change to S.empty()!= 0 or !S.empty()
        {
          res+=S.top();
          S.pop();
        }
        S.pop();
      }
      else if(higherprecedence(S.top(),ch)==0){   //S.top() will error if empty stack, add checking condition
        S.push(ch);
      }
      else if(higherprecedence(S.top(),ch)==1)
      {       //Only pop till weight of S.top() >= weight of ch
              //Eg.-stack = ['-', '+', '*', ('/')], top = '/', ch = '/'. Then pop till '*'
        while(S.top()=='/'||S.top()=='*'||S.top()=='-'||S.top()=='+'){  //Add appropriate logic
          res+=S.top();
          S.pop();
        }
        S.push(ch);
      }
    }
  }
  while(S.empty()!=0) //S.empty() true when stack empty. S.empty()!=0 false when stack not empty
  {                   //Change to S.empty()!= 0 or !S.empty()
    res+=S.top();
    S.pop();
  }
  return res;
}
int main(){       //Provide some info about program to user
  string exp;
  cin>>exp;       //Add input prompt message
  string postfix = itp(exp);
  cout<<"Output = "<<postfix<<"\n";
}