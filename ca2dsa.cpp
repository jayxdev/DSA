#include<iostream>
using namespace std;

//node class
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


//linklist class
class LinkList{
  Node *head;
  public:
  LinkList()
  {
    head=NULL;
  }

  //insert element to end
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

 //search element in the list
  void linearSearch(int x)
  { bool flag=false;//true if element found
    int index=0;
    Node *thead=head;
   if(head==NULL)
   cout<<"Empty list"<<endl; //if list is empty print error message
   else
   while (thead!=NULL)
   { 
    if(thead->data==x)//condition to check for element
    {
        cout<<"Element "<<x<<" found at index "<<index<<endl;//if present print its index
        flag=true;
        break;
    }
    thead=thead->next;//traverse to next element
    index++;
   }
   if(flag==false)//condition to check if element not found
   cout<<"Element "<<x<<" Not Found"<<endl; 
  }

  //display list
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
  list.linearSearch(5);
  list.linearSearch(8);
  return 0;
}