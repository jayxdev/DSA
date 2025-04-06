//Problem Statement: Write a C++ function that reverses the elements of a vector 
//of integers in place. The function should not use any additional vectors or arrays.
#include <iostream>
#include <vector>
using namespace std;

void reverseVector(vector<int>& vec) {
    int start = 0;
    int end = vec.size() - 1;

    while (start < end) {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    cout << "Original vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    reverseVector(numbers);

    cout << "Reversed vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}