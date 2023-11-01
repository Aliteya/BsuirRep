cmake_minimum_required(VERSION 3.10)
project(fabriic_system)

# Установка стандарта C++ на C++11
set(CMAKE_CXX_STANDARD 11)

# Добавление подкаталога с библиотекой Google Test
add_subdirectory(googletest-1.14.0)

# Включение директорий с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR} googletest-1.14.0/googletest/include)

# Добавление исходных файлов
set(SOURCES
    fabriic_system.cpp
    fabriic_system.h
    mytests.cpp
)

# Создание исполняемого файла
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
add_executable(fabriic_system ${SOURCES})
if(MSVC)
    target_compile_options(fabriic_system PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif()

# Линковка исполняемого файла с библиотекой Google Test
target_link_libraries(fabriic_system gtest gtest_main)
