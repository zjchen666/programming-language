#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // Number of elements
    cin >> n; // Read the number of elements
    vector<int> arr(n); // Create a vector to hold the elements
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Read each element
    }
    
    // Process the input as needed
    // Example: print the elements
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
