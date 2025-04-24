#include <iostream>
using namespace std;

int fun(int arr[], int low, int hig, int len) {
    int mid = low + (hig - low) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == len - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    }
    else if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return fun(arr, low, mid - 1, len);
    }
    else {
        return fun(arr, mid + 1, hig, len);
    }
}

int main() {
    int arr[] = {1, 3, 4, 3, 5, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int idx = fun(arr, 0, len - 1, len);
    cout << "1D peak at idx: " << idx << ", val: " << arr[idx] << endl;
    return 0;
}
