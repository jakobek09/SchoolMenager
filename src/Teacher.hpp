#ifndef TEACHER_HPP
#define TEACHER_HPP

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
    void addCourse(std::shared_ptr<Course> course);

    // Wyświetla wszystkie kursy prowadzone przez nauczyciela
    void printCourses() const;

    Role getRole() override { return m_role; }
};

#endif // TEACHER.HPP