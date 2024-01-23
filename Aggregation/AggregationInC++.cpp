#include <iostream>
#include <string>

class Teacher {
public:
    std::string name;

    Teacher(const std::string& teacherName) : name(teacherName) {}

    // A method to associate a student with a teacher
    void addStudent(class Student* student);
};

class Student {
public:
    std::string name;

    Student(const std::string& studentName) : name(studentName) {}

    // A method to associate a teacher with a student
    void setTeacher(class Teacher* teacher);
};

// Implementation of the method to associate a student with a teacher
void Teacher::addStudent(Student* student) {
    std::cout << "Teacher " << name << " is associated with student " << student->name << std::endl;
}

// Implementation of the method to associate a teacher with a student
void Student::setTeacher(Teacher* teacher) {
    std::cout << "Student " << name << " is associated with teacher " << teacher->name << std::endl;
}

int main() {
    // Create instances of Teacher and Student
    Teacher mathTeacher("Mr. Smith");
    Student alice("Alice");

    // Establish an association between the Teacher and Student
    mathTeacher.addStudent(&alice);
    alice.setTeacher(&mathTeacher);

    return 0;
}
