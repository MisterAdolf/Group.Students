#include <iostream>
#include <cstring>

class Student {
public:
    std::string name;
    int age;

    Student(const std::string& name = "", int age = 0) : name(name), age(age) {}
};

class Group {
private:
    Student* students;
    int size;

public:
    // конструктор без параметров
    Group() : students(nullptr), size(0) {}

    // конструктор с глубоким копированием
    Group(const Group& other) {
        size = other.size;
        if (size > 0) {
            students = new Student[size];
            for (int i = 0; i < size; ++i) {
                students[i] = other.students[i];
            }
        }
        else {
            students = nullptr;
        }
    }

    // деструктор
    ~Group() {
        delete[] students;
    }

    // метод для добавления студента
    void addStudent(const Student& student) {
        Student* newStudents = new Student[size + 1];
        for (int i = 0; i < size; ++i) {
            newStudents[i] = students[i];
        }
        newStudents[size] = student;
        delete[] students;
        students = newStudents;
        ++size;
    }

    // метод для вывода информации про группу
    void printGroup() const {
        for (int i = 0; i < size; ++i) {
            std::cout << "Student " << i + 1 << ": " << students[i].name << ", Age: " << students[i].age << std::endl;
        }
    }
};

int main() {
    Group group1;
    group1.addStudent(Student("Alice", 20));
    group1.addStudent(Student("Bob", 22));

    std::cout << "Group 1:" << std::endl;
    group1.printGroup();

    //использование конструктора копирования
    Group group2 = group1;
    std::cout << "\nGroup 2 (copied from Group 1):" << std::endl;
    group2.printGroup();

    return 0;
}
