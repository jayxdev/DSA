#include <iostream>
#include <unordered_set>
using namespace std;

string checkDuplicates(int arr[], int n) {
    unordered_set<int> uniqueSet;
    for (int i = 0; i < n; i++) {
        if (uniqueSet.find(arr[i]) != uniqueSet.end()) {
            return "YES";
        }
        uniqueSet.insert(arr[i]);
    }
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << checkDuplicates(arr, n) << endl;
    }
    return 0;
}