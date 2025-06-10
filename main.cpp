#include <iostream>
#include <string>
#include <vector>

void printTitle(std::string title);
void printMainMenu();
bool validateSelectedMenu(int menus[], int menusSize, int selectedMenu);
int getUserSelectMenu();
void printStudentManagementMainMenu();
int getUserStudentManagementMenu();
void enterStudentManagementMainMenu();

int main()
{

    printTitle("School Management");

    bool isRunning{true};
    while (isRunning)
    {
        printMainMenu();

        int choice = getUserSelectMenu();
        switch (choice)
        {
        case 1:
        {
            enterStudentManagementMainMenu();
            break;
        }
        case 0:
        {
            isRunning = false;
        }
        }

        std::cout << "============================" << std::endl;
    }
    std::cout << "Program End" << std::endl;

    return 0;
}

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

bool validateSelectedMenu(int menus[], int menusSize, int selectedMenu)
{
    bool isValidChoice{false};
    for (int i{0}; i < menusSize; ++i)
    {
        if (menus[i] == selectedMenu)
        {
            isValidChoice = true;
        }
    }
    return isValidChoice;
}

int getUserSelectMenu()
{
    int menus[]{0, 1};
    int menusSize{sizeof(menus) / sizeof(menus[0])};
    int choice;
    std::cout << std::endl;
    std::cout << "Go to menu : ";
    std::cin >> choice;

    bool isValidChoice{validateSelectedMenu(menus, menusSize, choice)};

    if (isValidChoice == false)
    {
        std::cout << "Menu is not valid! Try again. " << std::endl;
    }

    return choice;
}

void printStudentManagementMainMenu()
{
    std::cout << std::endl;
    std::cout << "Main menu:" << std::endl;
    std::cout << "1. Register New Student" << std::endl;
    std::cout << "2. Show Student List" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
}

int getUserStudentManagementMenu()
{
    int menus[]{0, 1, 2};
    int menusSize{sizeof(menus) / sizeof(menus[0])};
    int choice;
    std::cout << "Go to menu : ";
    std::cin >> choice;

    bool isValidChoice{validateSelectedMenu(menus, menusSize, choice)};

    if (isValidChoice == false)
    {
        std::cout << "Menu is not valid! Try again. " << std::endl;
    }

    return choice;
}

void enterStudentManagementMainMenu()
{
    printTitle("Student Management Main Menu");
    std::vector<std::string> students{};
    bool isRunning{true};
    while (isRunning)
    {
        printStudentManagementMainMenu();
        int choice = getUserStudentManagementMenu();
        switch (choice)
        {
        case 0:
        {
            std::cout << "Exit Student Management." << std::endl;
            isRunning = false;
            break;
        }
        case 1:
        {
            std::string inputStudent{};
            std::cout << "Insert new student name : " << std::endl;
            std::cin >> inputStudent;
            students.push_back(inputStudent);
            std::cout << "Data inserted" << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "List of students : " << std::endl;
            for (size_t i{0}; i < students.size(); ++i)
            {
                std::cout << (i + 1) << ". " << students.at(i) << std::endl;
            }
        }
        default:
            break;
        }
    }
}
