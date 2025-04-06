#include<iostream>
using namespace std;

class Node{
    public:
int data;
Node *next;
Node(){}
Node(int x)
{
    this->data=x;
    this->next= NULL;
}
};

class Stack{
  Node *top;
  public:
  Stack()
  {
    top=NULL;
  }
  
  void push(int x)
  {
   Node *temp=new Node(x);
   if(top==NULL)
   top=temp;
   else
   {
    temp->next=top;
   top=temp;}
  }
 
  void pop()
  {
   Node *temp=new Node();
   if(top==NULL)
   cout<<"Underflow"<<endl;
   else
   { temp=top;
   top=top->next;
   cout<<"popped "<<temp->data<<endl;
   }
   delete temp;
  }
  void peek()
  {
    if(top==NULL)
      cout<<"Stack empty "<<endl;
   else
    cout<<"Peek element is "<<top->data<<endl;
  }
  void display()
  {
    Node *ttop=top;
    cout<<"Display Stack :";
   if(top==NULL)
   cout<<"Empty Stack"<<endl;
   else
   while (ttop!=NULL)
   { 
    cout<<ttop->data<<" " ;
    ttop=ttop->next;
   }
   cout<<endl;
  }
};
int main()
{
  Stack list;
  list.push(2);
  list.push(5);
  list.push(6);
  list.push(7);
  list.display();
  list.pop();
  list.display();
  list.peek();
  return 0;
}