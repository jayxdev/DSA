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

class LinkList{
  Node *head;
  public:
  LinkList()
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
   }
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
  LinkList list;
  list.insertEnd(2);
  list.insertEnd(5);
  list.insertEnd(6);
  list.insertEnd(7);
  list.display();
  list.linearSearch
  return 0;
}