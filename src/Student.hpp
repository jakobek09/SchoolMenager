#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "User.hpp"


class Student : public User
{
    Student(const std::string& name, const std::string& surname, const std::string& username, const std::string& password)
        : User(name, surname, username, password) { m_role = Role::STUDENT; }


    Role getRole() override { return m_role; }

};

#endif // STUDENT_HPP