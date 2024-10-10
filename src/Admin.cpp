#include "Admin.hpp"
#include <algorithm>

void Admin::addUser(const std::shared_ptr<User>& user)
{
   // Sprawdzenie, czy użytkownik o tej nazwie już istnieje
    if (findUser(user->getUsername()) != nullptr) {
        std::cout << "Error: User with username " << user->getUsername() << " already exists." << std::endl;
        return;
    }

    // Dodanie nowego użytkownika
    users.push_back(user);

    // Sprawdzenie, czy użytkownik został dodany
    if (findUser(users.back()->getUsername()) != nullptr) {
        std::cout << "User " << user->getUsername() << " added to the system." << std::endl;
    } else {
        std::cout << "Error: Failed to add user." << std::endl;
    } 
}

void Admin::deleteUser(const std::string& username)
{
    auto it = std::remove_if(users.begin(), users.end(), [&username](const std::shared_ptr<User>& user) { return user->getUsername() == username; });

    if(it != users.end())
    {
        users.erase(it);
        std::cout << "User has been deleted!\n";
    }
    else 
    {
        std::cout << "User not found!\n";
    }
    return;
    
}

User* Admin::findUser(const std::string& username) const
{
    for(auto& user : users)
    {
        if(user->getUsername() == username)
            return user.get();
    }
    return nullptr;
}

void Admin::listUsers() const
{
    for(auto& user : users)
        std::cout << *user << std::endl;
}