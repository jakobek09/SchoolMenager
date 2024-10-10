#include "Course.hpp"


CourseRegistry& CourseRegistry::getInstance()
{
    static CourseRegistry instance;
    return instance;
}

// Funkcja do pobrania kursu z rejestru, tworzy kurs jeśli nie istnieje
std::shared_ptr<Course> CourseRegistry::getCourse(const std::string& name, const std::string& code) {
    auto it = courses.find(code);
    if (it != courses.end()) {
        return it->second;  // Zwraca istniejący kurs
    }
    
    // Jeśli kurs nie istnieje, utwórz nowy i dodaj do rejestru
    auto course = std::make_shared<Course>(name, code);
    courses[code] = course;
    return course;
}

void CourseRegistry::listCourses()
{
    for(auto& course : courses)
    {
        std::cout << course.second->getCourseName() << " - " << course.second->getCourseCode();
    }
}