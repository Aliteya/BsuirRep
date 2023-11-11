cmake_minimum_required(VERSION 3.10)
project(fabriic_system2)

# Установка стандарта C++ на C++11
set(CMAKE_CXX_STANDARD 11)

# Добавление подкаталога с библиотекой Google Test
add_subdirectory(googletest-1.14.0)

# Включение директорий с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR} googletest-1.14.0/googletest/include)

# Добавление исходных файлов
set(SOURCES
    Factory.h
    Customer.h
    Human.h
    Supplier.h
    RawMaterial.h
    ProductionLine.h
    Manager.h
    Employee.h
    Engineer.h
    Product.h
    Machine.h

    Factory.cpp
    Customer.cpp
    Human.cpp
    Supplier.cpp
    RawMaterial.cpp
    ProductionLine.cpp
    Manager.cpp
    Employee.cpp
    Engineer.cpp
    Product.cpp
    Machine.cpp
    mytests.cpp
)

# Создание исполняемого файла
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
add_executable(fabriic_system2 ${SOURCES})
if(MSVC)
    target_compile_options(fabriic_system2 PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif()

# Линковка исполняемого файла с библиотекой Google Test
target_link_libraries(fabriic_system2 gtest gtest_main)
