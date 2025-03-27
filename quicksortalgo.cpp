#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot
    int a = (low - 1); // Index of smaller element

    for (int b = low; b <= high - 1; b++) {
        // If current element is smaller than or equal to pivot
        if (arr[b] <= pivot) {
            a++; // Increment index of smaller element
            swap(arr[a], arr[b]);
        }
    }
    swap(arr[a + 1], arr[high]);
    return (a + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int a = 0; a < size; a++) {
        cout << arr[a] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
