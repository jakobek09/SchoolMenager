#include "Admin.hpp"
#include "Teacher.hpp"
#include <memory>

int main()
{
    int x;

    Admin admin("John", "Doe", "admin1", "password");
    std::shared_ptr<Admin> user = std::make_shared<Admin>("Jakub","Blazejewicz","BLAJAK","pwd");
    std::shared_ptr<Admin> user2 = std::make_shared<Admin>("Jakub","Blazejewicz","BLAJAK2","pwd");
    std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Pan", "Nauczyciel", "NAUCZ", "pwd");
    admin.addUser(user);
    admin.addUser(user2);
    admin.addUser(teacher);
    admin.listUsers();

    teacher->printCourses();

    // User* findTeacher = admin.findUser("NAUCZ");
    // Teacher* t = dynamic_cast<Teacher*>(findTeacher);

    // t->printCourses();

    // std::cin >> x;
    return 0;
}