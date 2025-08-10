#include <iostream>

void clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int getIntegerInput(const std::string &prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            clearBuffer();
        }
        else
        {
            clearBuffer();
            return value;
        }
    }
}
