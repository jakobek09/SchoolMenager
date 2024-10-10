#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

// Klasa Course
class Course {
private:
    std::string m_courseName;
    std::string m_courseCode;

public:
    Course(const std::string& name, const std::string& code)
        : m_courseName(name), m_courseCode(code) {}

    std::string getCourseName() const { return m_courseName; }
    std::string getCourseCode() const { return m_courseCode; }

    // Przeciążenie operatora << do wyświetlania kursów
    friend std::ostream& operator<<(std::ostream& os, const Course& course) {
        os << course.m_courseName << " (" << course.m_courseCode << ")";
        return os;
    }
};

// Klasa zarządzająca kursami (CourseRegistry)
class CourseRegistry {
private:
    std::unordered_map<std::string, std::shared_ptr<Course>> courses;

public:
    // Funkcja do pobrania kursu z rejestru, tworzy kurs jeśli nie istnieje
    std::shared_ptr<Course> getCourse(const std::string& name, const std::string& code);
};

#endif // COURSE_HPP