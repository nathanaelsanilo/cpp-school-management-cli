#include "student.h"
#include <string>

// use member initializer is recommended for efficiency and clarity
// class members are always initialized in the order
// they are declared in the class
// not the order in the initializer list
Student::Student(int valId, std::string valName) : id(valId), name(valName)
{
}

void Student::setId(int val)
{
    id = val;
}

int Student::getId()
{
    return id;
}

void Student::setName(std::string val)
{
    name = val;
}

std::string Student::getName()
{
    return name;
}
