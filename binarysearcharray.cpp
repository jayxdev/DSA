#include<iostream>
using namespace std;

int binarySearch(int arr[], int f, int l, int key){
    int mid = (f+l)/2;
    while (f<=l){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            f = mid+1;
        }
        else if(arr[mid]>key){
            l = mid-1;
        }
        mid = (f+l)/2;
    }
    return -1;
}

int main(){
    int arr[10];
    int size, key;
    cout<<"Enter the size: ";
    cin>>size;
    cout<<"Enter the "<< size <<" elements of array: ";
    for (int i = 0; i < size; i++)
 {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: ";
    cin>>key;
    int response = binarySearch(arr, 0, size-1, key);
    if (response == -1)
    {
        cout<<"Element Not Found!"<<endl;
    }
    else{
        cout<<"Element Found At Index: "<< response <<endl;
    }
    return 0;
}