#include<string>
#include<iostream>
#include<stack>
#include<ctype.h>
using namespace std;

int GetOperatorWeight(char op)
{
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
  int i,j;
  stack<char> S;
  string res;
  res.clear();
  for(i=0;i<exp.length();i++)
  {
    char ch=exp[i];
    if(isdigit(ch)){
      res+=ch;
    }
    else{
      if(ch=='('){
        S.push(ch);
      }
      else if(ch==')')
      {
        while(S.empty()!=0 && S.top()!='(')
        {
          res+=S.top();
          S.pop();
        }
        S.pop();
      }
      else if(higherprecedence(S.top(),ch)==0){
      S.push(ch);
      }
      else if(higherprecedence(S.top(),ch)==1)
      {
        while(S.top()=='/'||S.top()=='*'||S.top()=='-'||S.top()=='+'){
          res+=S.top();
          S.pop();
        }
        S.push(ch);
      }
    }
  }
  while(S.empty()!=0)
  {
    res+=S.top();
    S.pop();
  }
  return res;
}
int main(){
  string exp;
  cin>>exp;
  string postfix = itp(exp);
  cout<<"Output = "<<postfix<<"\n";
}