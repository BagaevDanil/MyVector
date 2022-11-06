cmake_minimum_required(VERSION 3.5)

project(MyProject)

add_subdirectory(
	"${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest"
	"googletest"
)

add_executable(
	prog
	src/main.cpp
	src/TMyVector.h
)

add_executable(
	test
	test/main.cpp
)

target_link_libraries(
	test PRIVATE
	gtest gtest_main
)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	target_compile_options(
		prog PRIVATE
		/W4
	)
	target_compile_options(
		test PRIVATE
		/W4
	)
else ()
	target_compile_options(
		prog PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
	target_compile_options(
		test PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()