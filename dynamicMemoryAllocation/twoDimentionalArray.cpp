#include <iostream>
#include <cstdlib>

int main() {
    // Declare dimensions for the array
    const int rows = 3, cols = 4;

    // Dynamically allocate the 2D array
    float** arr = new float*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new float[cols];
    }

    // Initialize the elements of the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = static_cast<float>(i * cols + j + 1);
        }
    }

    // Print the initial values of the array
    std::cout << "Initial values of arr:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Update the values of the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] *= 2.0;
        }
    }

    // Print the updated values of the array
    std::cout << "\nUpdated values of arr:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}