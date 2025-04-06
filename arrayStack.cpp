#include<iostream>
using namespace std;

int stack[100];int top=-1;
//push value to the stack
void push(int x)
{  top++;
  stack[top]=x;
  cout<<"Push "<<x<<endl;

}
//pop value from stack
void pop()
{
 top--;
 cout<<"Top Element Poped "<<endl;
}
//peek value
int peek()
{
   cout<<"Peek element "<<stack[top]<<endl;
}
//display stack
void display()
{
    for(int i=0;i<=top;i++)
    cout<<stack[i]<<" ";
    cout<<endl;
}
//main function
int main()
{    push(5);
     push(6);
     push(7);
     push(8);
     push(9);
     display();
     pop();
     display();
     peek();
    return 0;
}