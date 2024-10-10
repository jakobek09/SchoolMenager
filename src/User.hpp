#ifndef USER_HPP
#define USER_HPP

#include <iostream>

enum Role
{
    ADMIN = 0,
    TEACHER,
    STUDENT
};


class User
{
protected:
    std::string m_name, m_surname, m_username, m_password;
    Role m_role;

public:
    User(const std::string& name, const std::string& surname, const std::string& username, const std::string& password) : m_name(name), m_surname(surname), m_username(username), m_password(password) {}
    virtual ~User() = default;

    std::string getName() const { return m_name; }

    std::string getSurname() const { return m_surname; }

    std::string getUsername() const { return m_username; }

    bool checkPassword(const std::string& pwd) const { return m_password == pwd; }

    void setName(const std::string& name) { m_name = name; }

    void setSurname(const std::string& surname) { m_surname = surname; }

    void setUsername(const std::string& username) { m_username = username; }

    void setPassword(const std::string& password)
    {
        m_password = password;
    }

    virtual Role getRole() = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

inline std::ostream& operator<<(std::ostream& os, const User& user) 
{
    std::string role_str;
    switch (user.m_role) {
        case Role::ADMIN:
            role_str = "ADMIN";
            break;
        case Role::TEACHER:
            role_str = "TEACHER";
            break;
        case Role::STUDENT:
            role_str = "STUDENT";
            break;
        }
    os << user.m_name << " " << user.m_surname << " (" << user.m_username << ") - " << role_str;
    return os;
}

#endif // USER.HPP