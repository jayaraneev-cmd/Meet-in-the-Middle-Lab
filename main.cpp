#include <iostream>
#include "src/meet.hpp"

int main() {
    std::string filename;

    std::cout << "Enter the filename: ";
    std::cin >> filename;

    double median = findMedian(filename);

    std::cout << "The median of the dataset is " << median << std::endl;

    return 0;
}