# CMakeList.txt : CMake project for lesson3_2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("lesson3_2")

# Find SFML on the system
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

# Add source to this project's executable.
add_executable (lesson3_2 "main.cpp")

# Link SFML to executable
target_link_libraries(lesson3_2
    PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lesson3_2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
