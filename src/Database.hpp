#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "../include/SQLite/sqlite3.h"
#include <iostream>
#include <string>

class Database {
private:
    sqlite3* db;
    char* errorMessage = 0;

public:
    Database(std::string& dbName);

    ~Database();
    void executeSQL(const std::string& sql);

    void createStudentTable();
};

#endif // DATABASE_HPP
