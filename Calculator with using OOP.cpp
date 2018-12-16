#include <iostream>
using namespace std;

int A, B;
char symbol;

class operation
{
    int a;
    int b;
  public:
    void Setvalue(int a, int b);
    int add();
    int mul();
    int sub();
    double div();
};

void operation::Setvalue(int x, int y)
{
  a = x;
  b = y;
}

int operation::add()
{
  return a + b;
}

int operation::mul()
{
  return a * b;
}

int operation::sub()
{
  return a-b;
}

double operation::div()
{
  if(b != 0) return (double)a / (double)b;
  else 
  {
    cout << "Div0 Error";
    return 0; 
  }
}

int main(void)
{
  operation cal;
  cout << "input two numbers and operation\n";
  cin >> A >> symbol >> B;
  cal.Setvalue(A, B);
  switch(symbol)
  {
    case '+':
      cout << cal.add();
      break;
    case '-':
      cout << cal.sub();
      break;
    case '*':
      cout << cal.mul();
      break;
    case '/':
      cout << cal.div();
      break;           
  }
  return 0;
}