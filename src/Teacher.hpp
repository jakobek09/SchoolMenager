#ifndef TEACHER_HPP
#define TEACHER_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "User.hpp"
#include "Course.hpp"

class Teacher : public User {
private:
    std::vector<std::shared_ptr<Course>> courses;  // Wektor współdzielonych wskaźników do kursów

public:
    Teacher(const std::string& name, const std::string& surname, const std::string& username, const std::string& password)
        : User(name, surname, username, password) { m_role = Role::TEACHER; }

    // Dodaje kurs
    void addCourse(std::shared_ptr<Course> course) {
        courses.push_back(course);
    }

    // Wyświetla wszystkie kursy prowadzone przez nauczyciela
    void printCourses() const {
        std::cout << "Courses taught by " << *this << ":\n";
        for (const auto& course : courses) {
            std::cout << *course << "\n";  // Dereferencja std::shared_ptr<Course>
        }
    }

    Role getRole() override { return m_role; }
};

#endif // TEACHER.HPP