cmake_minimum_required(VERSION 3.23)
project(display_text)

set(CMAKE_CXX_STANDARD 14)

find_package(Freetype REQUIRED)

include_directories(GLAD/include)
include_directories(${FREETYPE_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp GLAD/src/glad.c)

set(OpenGlLinkers -lglut -lGLU -lGL)
set(FreetypeLinkers -lfreetype)

add_executable(display_text ${SOURCE_FILES})
target_link_libraries(display_text ${OpenGlLinkers} ${FREETYPE_LIBRARIES})