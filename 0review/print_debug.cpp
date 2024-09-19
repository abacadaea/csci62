#include <iostream>

using namespace std;

int findMax(vector<int> arr) {
    int max = 0;
    for (int i = 1; i <= arr.size(); i++) {  
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    vector<int> numbers {8, 5, 7, 2, 3};
    cout << "Maximum value in the array: " << findMax(numbers) << endl;  
}
