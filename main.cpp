#include <iostream>
#include <string>
#include <vector>

void printTitle(std::string title);
void printMainMenu();
bool validateSelectedMenu(int menus[], int menusSize, int selectedMenu);
int getUserSelectMainMenu();
void printStudentManagementMainMenu();
int getUserStudentManagementMenu();
void enterStudentManagementMainMenu();
void insertNewStudent();
void printStudentList();
void deleteStudent();

std::vector<std::string> students{};

int main()
{

    printTitle("School Management");

    bool isRunning{true};
    while (isRunning)
    {
        printMainMenu();

        int choice = getUserSelectMainMenu();
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

int getUserSelectMainMenu()
{
    int menus[]{0, 1};
    int menusSize{sizeof(menus) / sizeof(menus[0])};
    bool validating{true};
    int choice;

    while (validating)
    {
        std::cout << std::endl;
        std::cout << "Go to menu : ";
        std::cin >> choice;
        if (validateSelectedMenu(menus, menusSize, choice) == true)
        {
            validating = false;
        }
        else
        {
            std::cout << "Menu is not valid! Try again. " << std::endl;
        }
    }

    return choice;
}

void printStudentManagementMainMenu()
{
    std::cout << std::endl;
    std::cout << "Main menu:" << std::endl;
    std::cout << "1. Register New Student" << std::endl;
    std::cout << "2. Show Student List" << std::endl;
    std::cout << "3. Delete student by name" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
}

int getUserStudentManagementMenu()
{
    int menus[]{0, 1, 2, 3}; // student management menus
    int menusSize{sizeof(menus) / sizeof(menus[0])};
    bool validating{true};
    int choice;

    while (validating)
    {
        std::cout << std::endl;
        std::cout << "Go to menu : ";
        std::cin >> choice;
        if (validateSelectedMenu(menus, menusSize, choice) == true)
        {
            validating = false;
        }
        else
        {
            std::cout << "Menu is not valid! Try again. " << std::endl;
        }
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
            insertNewStudent();
            break;
        }
        case 2:
        {
            printStudentList();
            break;
        }
        case 3:
        {
            deleteStudent();
            break;
        }
        default:
            break;
        }
    }
}

void insertNewStudent()
{
    std::string inputStudent{};
    std::cout << "Insert new student name : " << std::endl;
    std::cin >> inputStudent;
    students.push_back(inputStudent);
    std::cout << "Data inserted!" << std::endl;
}

void printStudentList()
{
    std::cout << "List of students : " << std::endl;
    if (students.size() == 0)
    {
        std::cout << "List is empty. Create a new one!" << std::endl;
    }
    else
    {
        for (size_t i{0}; i < students.size(); ++i)
        {
            std::cout << (i + 1) << ". " << students.at(i) << std::endl;
        }
    }
}

void deleteStudent()
{
    if (students.empty())
    {
        std::cout << "Student list is empty. Nothing has deleted" << std::endl;
        return;
    }

    std::string inputStudent{};
    std::cout << "You wish to delete student. Enter student name : ";
    std::cin >> inputStudent;
    std::cout << std::endl;

    bool isStudentExist{false};
    std::vector<std::string>::iterator studentIterator{};
    for (std::vector<std::string>::iterator it = students.begin(); it != students.end(); ++it)
    {
        if (*it == inputStudent)
        {
            isStudentExist = true;
            studentIterator = it;
        }
    }

    if (isStudentExist == false)
    {
        std::cout << "This name \"" << inputStudent << "\" is not exist !" << std::endl;
        return;
    }

    students.erase(studentIterator);

    std::cout << std::endl;
    std::cout << inputStudent << " has been deleted!" << std::endl;
}
