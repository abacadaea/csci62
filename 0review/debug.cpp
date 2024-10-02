// This program can be debugged with print statements 

#include <iostream>

using namespace std;

int findMax(vector<int> arr) {
    int max = 0;
    for (int i = 1; i <= arr.size(); i++) {  
      cout << "i=" << i << ", arr[i]=" << arr[i] << ", max=" << max << endl;
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    //cout << "max: " <<  max << endl;
    return max;
}

int main() {
    vector<int> numbers;
    numbers.push_back(8);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(2);
    numbers.push_back(3);
    int m = findMax(numbers);
    cout << "Maximum value in the array: " << m << endl;  
}
