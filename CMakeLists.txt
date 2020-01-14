cmake_minimum_required (VERSION 3.8)

project ("Otus_1" VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER}) 

configure_file (configure_version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/configure_version.h
)
set (SOURCES "otus_1.cpp" "version.cpp")
set (HEADERS "version.h" "configure_version.h")
add_executable(Otus_1 ${SOURCES})

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


find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if(NOT Boost_FOUND)
	message(SEND_ERROR "Failed to find boost")
	return()
else()	 
	include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(test_version "test_version.cpp" "version.cpp")

set_target_properties (
	test_version PROPERTIES 
	CXX_STANDARD 17 
	CXX_STANDARD_REQUIRED ON	
)
target_include_directories(
	test_version 
	PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(test_version
    ${Boost_LIBRARIES}
)

if (MSVC)
    target_compile_options(Otus_1 PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(Otus_1 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

if (NOT MSVC)
   set_target_properties( test_version PROPERTIES
		COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
		INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
	)
endif()

enable_testing()
add_test(test_version test_version)