#include "meet.hpp"
#include <iostream>
#include <fstream>

double findMedian(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Error opening file.\n";
        return 0;
    }

    int capacity = 10;
    int size = 0;
    int* data = new int[capacity];

    int num;
    char comma;

    // Read numbers from CSV
    while (file >> num) {
        // Resize array if needed
        if (size == capacity) {
            capacity *= 2;
            int* newData = new int[capacity];

            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }

        data[size++] = num;

        // Skip comma
        file >> comma;
    }

    double median = 0;

    if (size == 0) {
        delete[] data;
        return 0;
    }

    if (size % 2 == 1) {
        // odd
        median = data[size / 2];
    } else {
        // even
        median = (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }

    delete[] data;
    return median;
}