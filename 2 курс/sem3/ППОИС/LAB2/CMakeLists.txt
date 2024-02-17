cmake_minimum_required(VERSION 3.10)
project(auto_repair_shop)

# Установка стандарта C++ на C++11
set(CMAKE_CXX_STANDARD 11)

# Добавление подкаталога с библиотекой Google Test
add_subdirectory(googletest-1.14.0)

# Включение директорий с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR} googletest-1.14.0/googletest/include)

# Добавление исходных файлов
set(SOURCES
    auto_repair_shop.cpp
    auto_repair_shop.h
    my_tests.cpp
)

# Создание исполняемого файла
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
add_executable(auto_repair_shop ${SOURCES})
if(MSVC)
    target_compile_options(auto_repair_shop PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif()

# Линковка исполняемого файла с библиотекой Google Test
target_link_libraries(auto_repair_shop gtest gtest_main)
