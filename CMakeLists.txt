cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (CMakeCI VERSION 0.1)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeCI 
    "Items/Item.h" "Config.h"
    "Component.cpp" "HealthComponent.cpp"
    "Entity.cpp"
    "Header.h"
    "Tests/ListTests.cpp" "Tests/ItemsTests.cpp" "Tests/HealthComponentTests.cpp"
    Source.cpp "temp.cpp")
target_link_libraries(
  CMakeCI
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(CMakeCI)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeCI PROPERTY CXX_STANDARD 20)
endif()

# Добавление тестов 
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP NEW
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)