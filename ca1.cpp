#include <iostream>
using namespace std;

int main() {
    int n;
    int count = 0;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; ++i) {
       cin>>arr[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 != 0) {
            ++count;
        }
    }

    cout <<count;

    return 0;
}
