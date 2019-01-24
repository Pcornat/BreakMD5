cmake_minimum_required(VERSION 3.12)
project(Code_Base C)

set(CMAKE_C_STANDARD 99)

find_package(OpenMP REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(.)

set(OPTIONS_FLAGS
		PRIVATE -Wall)

if (${CMAKE_C_COMPILER_ID} STREQUAL "Intel")
	message("Intel compiler is used.")
	set(OPTIONS_FLAGS
			${OPTIONS_FLAGS}
			PRIVATE -Wextra-tokens)
	set(CMAKE_C_FLAGS_RELEASE "-Ofast -DNDEBUG")
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
	message("GNU compiler is used.")
	set(OPTIONS_FLAGS
			${OPTIONS_FLAGS}
			PRIVATE -pipe
			PRIVATE -Wextra)
endif ()

set(LINKER_OPTIONS
		PRIVATE -Wl,--as-needed)

set(OPTIONS_FLAGS ${OPTIONS_FLAGS} ${OpenMP_C_FLAGS})
set(LINKER_FLAGS ${OpenMP_C_LIBRARIES} ${OPENSSL_CRYPTO_LIBRARY})

set(SOURCES
		bf.c
		bf.h
		princ.c)

add_executable(Code_Base ${SOURCES})
target_compile_options(Code_Base ${OPTIONS_FLAGS})
#target_link_options(Code_Base ${LINKER_OPTIONS})
target_link_libraries(Code_Base ${LINKER_OPTIONS} ${LINKER_FLAGS} m)