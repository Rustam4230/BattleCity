cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME BattleCity)
project(${PROJECT_NAME})

# Установите стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавьте поддиректории с библиотеками ПЕРЕД созданием исполняемого файла
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)

# Создайте исполняемый файл ПОСЛЕ добавления поддиректорий
add_executable(${PROJECT_NAME} src/main.cpp)

# Добавьте пути к заголовочным файлам
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include
)

# Свяжите все библиотеки в ОДНОЙ команде
target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw            # GLFW библиотека (строчные буквы!)
    glad            # Glad библиотека (строчные буквы!)
    opengl32.lib    # Системная библиотека OpenGL
)