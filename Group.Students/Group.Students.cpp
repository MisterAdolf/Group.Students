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
    // ����������� ��� ����������
    Group() : students(nullptr), size(0) {}

    // ����������� � �������� ������������
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

    // ����������
    ~Group() {
        delete[] students;
    }

    // ����� ��� ���������� ��������
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

    // ����� ��� ������ ���������� ��� ������
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

    //������������� ������������ �����������
    Group group2 = group1;
    std::cout << "\nGroup 2 (copied from Group 1):" << std::endl;
    group2.printGroup();

    return 0;
}
