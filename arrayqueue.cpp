#include <iostream>
using namespace std;
int a[10];
int front=-1,rear=-1;
int max=5;
bool isempty()
{
if(front==-1&&rear==-1)
return true;
else return false;
}
bool is_full()
{
if(rear==sizeof(a)-1)
return true;
else return false;
}
void enquee(int num)
{
    if(isempty()){
        front++;
        rear++;
        a[rear]=num;
    }
    else if(is_full()){
    cout<<"full"<<endl;
    return ;
    }

    else {
        
        a[++rear]=num;
    }   
}
int dequee()
{ int n=0;
if(front==rear)
{n=a[front];
    front=-1;
    rear=-1;
}
else if(isempty())
return -1;

else {
    n=a[front];
    front++;
}
return n;
}
int main()
{      
enquee(1);
enquee(2);
enquee(3);
enquee(4);
enquee(5);
cout<<dequee()<<endl;
cout<<dequee()<<endl;
cout<<dequee()<<endl;
cout<<dequee()<<endl;
cout<<dequee()<<endl;

}