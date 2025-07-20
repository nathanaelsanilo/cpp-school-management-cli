#include <string>
#include <iostream>

void printTitle(std::string text)
{
    std::cout << "============================" << std::endl;
    std::cout << text << std::endl;
    std::cout << "============================" << std::endl;
}

void printMainMenu()
{
    std::cout << std::endl;
    std::cout << "Main menu:" << std::endl;
    std::cout << "1. Student Management" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void printStudentManagementMainMenu()
{
    std::cout << std::endl;
    std::cout << "Main menu:" << std::endl;
    std::cout << "1. Register New Student" << std::endl;
    std::cout << "2. Show Student List" << std::endl;
    std::cout << "3. Delete student by name" << std::endl;
    std::cout << "4. Find student by name" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
}