#include "Teacher.hpp"

void Teacher::addCourse(std::shared_ptr<Course> course) 
{
    courses.push_back(course);
}

void Teacher::printCourses() const 
{
    std::cout << "Courses taught by " << *this << ":\n";
    for (const auto& course : courses) {
        std::cout << *course << "\n";  // Dereferencja std::shared_ptr<Course>
    }
}