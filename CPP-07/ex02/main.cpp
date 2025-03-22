#include "Array.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#define MAX_VAL 750

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define PURP "\033[1;95m"
# define PURP2 "\033[1;35m"
# define ORANGE "\033[1;91m"
# define LIGHTB "\033[1;36m"
# define BLUE "\033[1;94m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"


int main()
{
    std::cout << std::endl << RED "---------------------------------------------------"<< std::endl;
	std::cout <<"ALL TEST FOR INT ARRAY:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    std::cout << std::endl << GREEN "SHOW SIZES NEW ARRAYS AND CONSTRUCTORS:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;

    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;

    std::cout << std::endl << GREEN "TEST [] OPERATOR:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    arr2[0] = 10;
    arr2[1] = 20;
    arr2[2] = 30;
    std::cout << "arr2[0]: " << arr2[0] << std::endl;
    std::cout << "arr2[1]: " << arr2[1] << std::endl;
    std::cout << "arr2[2]: " << arr2[2] << std::endl;

    std::cout << std::endl << GREEN "TEST COPY ASSIGNMENT OPERATOR:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    Array<int> arr3(arr2);
    std::cout << "arr3 size: " << arr3.size() << std::endl;
    std::cout << "arr3[0]: " << arr3[0] << std::endl;

    Array<int> arr4;
    arr4 = arr2;
    std::cout << "arr4 size: " << arr4.size() << std::endl;
    std::cout << "arr4[1]: " << arr4[1] << std::endl;

    std::cout << std::endl << GREEN "TEST OUT OF RANGE:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    try
    {
        std::cout << "arr2[10]: " << arr2[10] << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << RED "---------------------------------------------------"<< std::endl;
	std::cout <<"TEST DIFFERENT KINDS OF ARRAY:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    std::cout << std::endl << GREEN "INT ARRAY:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    Array<int> intArray(5);
    for (int i = 0; i < 5; ++i) {
        intArray[i] = i * 10;
    }
    std::cout << "Int array:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i] << std::endl;
    }

    std::cout << std::endl << GREEN "CHAR ARRAY:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    Array<char> charArray(5);
    for (int i = 0; i < 5; ++i) {
        charArray[i] = 'A' + i;
    }
    std::cout << "Char array:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << charArray[i] << std::endl;
    }

    std::cout << std::endl << GREEN "STRING ARRAY:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "hello";
    stringArray[1] = "world";
    stringArray[2] = "!";
    std::cout << "String array:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << stringArray[i] << std::endl;
    }

    std::cout << std::endl << GREEN "STRING CONST ARRAY:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl;
    Array<std::string> stringArray2(3);
    stringArray2[0] = "hello";
    stringArray2[1] = "world";
    stringArray2[2] = "!";
    const Array<std::string> stringArray3(stringArray2);
    std::cout << "String array:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << stringArray3[i] << std::endl;
    }

    std::cout << std::endl << RED "---------------------------------------------------"<< std::endl;
	std::cout <<"TEST GIVEN MAIN:" << std::endl;
	std::cout << "---------------------------------------------------" RESET << std::endl << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return (0);
}