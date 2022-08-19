cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

cmake_policy(SET CMP0048 NEW) # for version
project (Observer_mode VERSION 1.0.0)

SET(CMAKE_BUILE_TYPE "build")

find_package(Qt5 COMPONENTS Widgets  REQUIRED)

include_directories (${CMAKE_SOURCE_DIR}/include)# ${CMAKE_SOURCE_DIR}/src/googletest/googletest/include  )

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

SET(GTEST_LIB_1 ${CMAKE_CURRENT_SOURCE_DIR}/src/googletest/build/lib/libgtest.a)
SET(GTEST_LIB_2 ${CMAKE_CURRENT_SOURCE_DIR}/src/googletest/build/lib/libgtest_main.a)

# Tell CMake to run moc when necessary:
SET(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET  (PROJECT_SOURCES
	${CMAKE_SOURCE_DIR}/src/main.cpp
  ${CMAKE_SOURCE_DIR}/src/observer.cpp
  ${CMAKE_SOURCE_DIR}/src/subject.cpp
  # ${CMAKE_SOURCE_DIR}/src/gtest.cpp
	) 

SET  (PROJECT_HEADERS
  ${CMAKE_SOURCE_DIR}/include/base.h
  ${CMAKE_SOURCE_DIR}/include/observer.h
  ${CMAKE_SOURCE_DIR}/include/subject.h
	)

INCLUDE_DIRECTORIES(src include ${CMAKE_CURRENT_BINARY_DIR} ${Qt5_INCLUDE_DIRS})
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib/linux )
ADD_EXECUTABLE(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}  )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} -pthread gtest Qt5::Core Qt5::Widgets Qt5::Gui ) #${GTEST_LIB_1} ${GTEST_LIB_2}


