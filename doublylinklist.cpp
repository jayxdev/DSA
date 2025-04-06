#include<iostream>
using namespace std;

class Node{
    public:
int data;
Node *next;
Node *prev;
Node(){}
Node(int x)
{
    this->data=x;
    this->next= NULL;
    this->prev=NULL;
}
};

class DLinkList{
  Node *head;
  public:
  DLinkList()
  {
    head=NULL;
  }
  void insertEnd(int x)
  { 
   Node *thead=head;
   Node *temp=new Node(x);
   if(head==NULL)
   head=temp;
   else{
   while (thead->next!=NULL)
   { 
    thead=thead->next;
   }
   thead->next=temp;
   temp->prev=thead;
   }
  }
  void insertBegin(int x)  
  {
   Node *temp=new Node(x);
   if(head==NULL)
   head=temp;
   else
   {head->prev=temp;
    temp->next=head;
   head=temp;}
  }
  void deleteEnd()
  {
   Node *thead=head;
   Node *temp=new Node();
   if(head==NULL)
   cout<<"Underflow"<<endl;
   else{
   while (thead->next!=NULL)
   { temp=thead;
    thead=thead->next;
   }
   temp=thead;
   thead=thead->prev;
   thead->next=NULL;
   cout<<"deleted from end"<<endl;
   }
  }
  void deleteFront()
  {
   Node *temp=new Node();
   if(head==NULL)
   cout<<"Underflow"<<endl;
   else
   { temp=head;
   head=head->next;
   head->prev=NULL;
   cout<<"deleted from front"<<endl;
   }
   delete temp;
  }
  void display()
  {
    Node *thead=head;
   if(head==NULL)
   cout<<"Empty list"<<endl;
   else
   while (thead!=NULL)
   { 
    cout<<thead->data<<" " ;
    thead=thead->next;
   }
   cout<<endl;
  }
};
int main()
{
  DLinkList list;
  list.insertEnd(2);
  list.insertEnd(5);
  list.insertEnd(6);
  list.insertEnd(7);
  list.insertBegin(9);
  list.display();
  list.deleteEnd();
  list.display();
  list.deleteFront();
  list.display();
  return 0;
}