# Dodanie plików źródłowych
add_executable(StudentManager main.cpp Admin.cpp Course.cpp Teacher.cpp Student.cpp)

target_link_libraries(StudentManager sqlite3)

# Uwzględnienie katalogu z plikami nagłówkowymi (src)
target_include_directories(StudentManager PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(StudentManager PRIVATE ${CMAKE_SOURCE_DIR}/include/SQLite)
