#include "student.h"
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
void findStudentByName();
void clearBuffer();
int getIntegerInput(const std::string &prompt);

int seqStudentId{0};
std::vector<Student> students{};

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

int getUserSelectMainMenu()
{
    int menus[]{0, 1};
    int menusSize{sizeof(menus) / sizeof(menus[0])};
    bool validating{true};
    int choice;

    while (validating)
    {
        std::cout << std::endl;
        choice = getIntegerInput("Go to menu : ");
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

int getUserStudentManagementMenu()
{
    int menus[]{0, 1, 2, 3, 4}; // student management menus
    int menusSize{sizeof(menus) / sizeof(menus[0])};
    bool validating{true};
    int choice;

    while (validating)
    {
        std::cout << std::endl;
        choice = getIntegerInput("Go to menu : ");
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
        case 4:
        {
            findStudentByName();
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
    clearBuffer();
    std::getline(std::cin, inputStudent);
    Student student(++seqStudentId, inputStudent);
    students.push_back(student);
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
            Student student{students.at(i)};
            std::cout << (i + 1) << ". " << student.getName() << std::endl;
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
    clearBuffer();
    std::getline(std::cin, inputStudent);
    std::cout << std::endl;

    bool isStudentExist{false};
    std::vector<Student>::iterator studentIterator{};
    for (std::vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
    {
        if (it->getName() == inputStudent)
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

void findStudentByName()
{
    std::vector<Student> foundList{};

    std::string inputStudent{};
    std::cout << "Input name : ";
    clearBuffer();
    std::getline(std::cin, inputStudent);

    for (std::vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
    {
        if (it->getName().find(inputStudent) != std::string::npos)
        {
            foundList.push_back(*it);
        }
    }

    if (foundList.size() == 0)
    {
        std::cout << "Not found!" << std::endl;
        return;
    }

    std::cout << "Results : " << std::endl;
    for (Student item : foundList)
    {
        std::cout << "id : " << item.getId() << std::endl;
        std::cout << "name : " << item.getName() << std::endl;
    }

    std::cout << std::endl;
}
