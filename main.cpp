#include <iostream>
#include <string>

/** @param arr pointer to array */
int getArrSize(int arr[])
{
    return sizeof(arr) / sizeof(arr[0]);
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
    int choice;
    std::cout << std::endl;
    std::cout << "Go to menu : ";
    std::cin >> choice;

    bool isValidChoice{validateSelectedMenu(menus, getArrSize(menus), choice)};

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
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
}

int getUserStudentManagementMenu()
{
    int menus[]{0, 1};
    int choice;
    std::cout << "Go to menu : ";
    std::cin >> choice;

    bool isValidChoice{validateSelectedMenu(menus, getArrSize(menus), choice)};

    if (isValidChoice == false)
    {
        std::cout << "Menu is not valid! Try again. " << std::endl;
    }

    return choice;
}

void enterStudentManagementMainMenu()
{
    printTitle("Student Management Main Menu");
    bool isRunning{true};
    while (isRunning)
    {
        printStudentManagementMainMenu();
        int choice = getUserStudentManagementMenu();
        if (choice == 0)
        {
            std::cout << "Exit Student Management." << std::endl;
            isRunning = false;
        }
        else
        {
            std::cout << "user choice : " << choice << std::endl;
        }
    }
}

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
