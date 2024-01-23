#include <iostream>

int removeDuplicates(int arr[], int length) {
    if (length <= 1) {
        // If the array has 0 or 1 element, there are no duplicates to remove
        return length;
    }

    int uniqueIndex = 0;

    for (int i = 1; i < length; ++i) {
        if (arr[i] != arr[uniqueIndex]) {
            // Move the unique element to the next position
            ++uniqueIndex;
            arr[uniqueIndex] = arr[i];
        }
    }

    // The new length is one more than the index of the last unique element
    return uniqueIndex + 1;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Calling the function to remove duplicates in-place
    int newLength = removeDuplicates(arr, length);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "New Length: " << newLength << std::endl;

    return 0;
}
