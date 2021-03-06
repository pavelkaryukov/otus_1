﻿cmake_minimum_required (VERSION 3.8)

if (NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
	set(ENV{TRAVIS_BUILD_NUMBER} 1) # не считается ли назначение TRAVIS_BUILD_NUMBER дурным тоном ?
	message("Failed to find ENV TRAVIS_BUILD_NUMBER, set default value = 1")
endif()

project ("Otus_1" VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER}) 

configure_file (configure_version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/configure_version.h
)

set (VERSION_SRC "version.cpp" "version.h" "configure_version.h")

add_executable(Otus_1 "otus_1.cpp" ${VERSION_SRC}) 

set_target_properties (
	Otus_1 PROPERTIES 
	CXX_STANDARD 17 
	CXX_STANDARD_REQUIRED ON	
)

target_include_directories(
	Otus_1 
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)

#Boost Test
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if(NOT Boost_FOUND)
	message(SEND_ERROR "Failed to find boost")
	return()
endif()

add_executable(boost_test_version "boost_test_version.cpp" ${VERSION_SRC} )

set_target_properties (
	boost_test_version PROPERTIES 
	CXX_STANDARD 17 
	CXX_STANDARD_REQUIRED ON	
)
target_include_directories(
	boost_test_version 
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
	${Boost_INCLUDE_DIR}
)
target_link_libraries(boost_test_version
    ${Boost_LIBRARIES}
)

#Google Test
find_package(GTest REQUIRED)

if(NOT GTEST_FOUND )
	message(SEND_ERROR "Failed to find GTest")
	return()
endif()

add_executable(gtest_test_version "gtest_test_version.cpp" ${VERSION_SRC} )
set_target_properties (
	gtest_test_version PROPERTIES 
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON	
)

target_link_libraries(gtest_test_version ${GTEST_BOTH_LIBRARIES})
if (NOT MSVC)
	target_link_libraries(gtest_test_version pthread)
endif()

target_include_directories(
	gtest_test_version 
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
	${GTEST_INCLUDE_DIRS}
)


if (MSVC)
    target_compile_options(Otus_1 PRIVATE
        /W4
    )
    target_compile_options(boost_test_version PRIVATE
        /W4
    )
	target_compile_options(gtest_test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(Otus_1 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(boost_test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
	set_target_properties( boost_test_version PROPERTIES
		COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	)
    target_compile_options(gtest_test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

enable_testing()
add_test(boost_test_version boost_test_version)
add_test(gtest_test_version gtest_test_version)

#Сборка пакета
install(TARGETS Otus_1 DESTINATION bin)
set(CPACK_PACKAGE_NAME "OtusHomework_1")
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_VENDOR "Karyukov")
set(CPACK_PACKAGE_CONTACT "pavelkaryukov@gmail.com")
include (CPack)