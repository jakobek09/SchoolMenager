#include "Admin.hpp"
#include "Teacher.hpp"
#include "Database.hpp"
#include <memory>
#include <filesystem>

int main()
{
    std::cout << "Bieżący katalog roboczy: " << std::filesystem::current_path() << std::endl;
    CourseRegistry& courses = CourseRegistry::getInstance();
    std::string databaseName = "Students.db";
    Database database(databaseName);

    database.createStudentTable();

    int x;

    Admin admin("John", "Doe", "admin1", "password");
    std::shared_ptr<Admin> user = std::make_shared<Admin>("Jakub","Blazejewicz","BLAJAK","pwd");
    std::shared_ptr<Admin> user2 = std::make_shared<Admin>("Jakub","Blazejewicz","BLAJAK2","pwd");
    std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Pan", "Nauczyciel", "NAUCZ", "pwd");
    admin.addUser(user);
    admin.addUser(user2);
    admin.addUser(teacher);
    admin.listUsers();
    teacher->addCourse(courses.getCourse("Math", "ma1"));
    teacher->printCourses();

    // User* findTeacher = admin.findUser("NAUCZ");
    // Teacher* t = dynamic_cast<Teacher*>(findTeacher);

    // t->printCourses();

    // std::cin >> x;
    return 0;
}