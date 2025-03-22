#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: " << std::endl;
    iter(arr, 5, printTemplate);
    std::cout << std::endl;
	iter(arr,5,increment);
    std::cout << std::endl;
    iter(arr, 5, printTemplate);
    std::cout << std::endl;

    std::string strArr[] = {"Hello", "World", "C++"};
    std::cout << "String array: " << std::endl;
    iter(strArr, 3, printTemplate);
    std::cout << std::endl;
    return 0;
}