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
    Database(std::string& dbName) {
        dbName = "../../Database/" + dbName + ".db";
        if (sqlite3_open(dbName.c_str(), &db)) {
            std::cerr << "Błąd otwarcia bazy danych: " << sqlite3_errmsg(db) << std::endl;
        } else {
            std::cout << "Pomyślnie otwarto bazę danych: " << dbName << std::endl;
        }
    }

    ~Database() {
        sqlite3_close(db);
    }

    void executeSQL(const std::string& sql) {
        int result = sqlite3_exec(db, sql.c_str(), 0, 0, &errorMessage);
        if (result != SQLITE_OK) {
            std::cerr << "Błąd SQL: " << errorMessage << std::endl;
            sqlite3_free(errorMessage);
        } else {
            std::cout << "Pomyślnie wykonano SQL" << std::endl;
        }
    }

    void createStudentTable() {
        std::string sql = "CREATE TABLE IF NOT EXISTS Student("
                          "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "Name TEXT NOT NULL, "
                          "Surname TEXT NOT NULL, "
                          "StudentID TEXT NOT NULL UNIQUE);";
        executeSQL(sql);
    }
};

#endif // DATABASE_HPP
