cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(StudentManager)

include_directories(include)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS NO) 

# Dodanie podkatalogu src do budowania
add_subdirectory(src)

add_library(sqlite3 STATIC include/SQLite/sqlite3.c)

# Możesz dodać opcjonalne flagi kompilacji dla SQLite (np. wyłączenie ostrzeżeń)
target_compile_options(sqlite3 PRIVATE -w)
