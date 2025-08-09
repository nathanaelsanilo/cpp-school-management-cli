#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
    int id;
    std::string name;

public:
    Student(int studentId, std::string studentName);

    void setId(int value);

    int getId();

    void setName(std::string value);

    std::string getName();
};

#endif