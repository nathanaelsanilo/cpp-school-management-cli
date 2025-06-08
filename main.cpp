#include <iostream>

void printTitle()
{
    std::cout << "============================" << std::endl;
    std::cout << "School Management" << std::endl;
    std::cout << "============================" << std::endl;
}

void printMainMenu()
{
    std::cout << "Main menu:" << std::endl;
    std::cout << "1. Student management" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int getUserSelectMenu()
{
    int menus[]{0, 1};
    int choice;
    std::cout << "Go to menu : ";
    std::cin >> choice;

    bool isValidChoice{false};
    for (int menu : menus)
    {
        if (menu == choice)
        {
            isValidChoice = true;
        }
    }

    if (isValidChoice == false)
    {
        std::cout << "Menu is not valid! Try again. ";
    }

    return choice;
}

int main()
{
    printTitle();

    bool isRunning{true};
    while (isRunning)
    {
        printMainMenu();

        int choice = getUserSelectMenu();
        if (choice == 0)
        {
            isRunning = false;
        }

        std::cout << "Your choice : " << choice << std::endl;
        std::cout << "============================" << std::endl;
    }
    std::cout << "Program End" << std::endl;

    return 0;
}
