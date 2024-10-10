#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "User.hpp"
#include <memory>
#include <vector>

class Admin : public User
{
private:
std::vector<std::shared_ptr<User>> users;

public:
    Admin(const std::string& name, const std::string& surname, const std::string& username, const std::string& password)
        : User(name, surname, username, password)  { m_role = Role::ADMIN; }

    Role getRole() override { return m_role; }

    void addUser(const std::shared_ptr<User>& user);
    void deleteUser(const std::string& username);
    void listUsers() const;

    User* findUser(const std::string& username) const;

};

#endif // ADMIN_HPP