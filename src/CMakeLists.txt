cmake_minimum_required(VERSION 3.0)

IF(NOT WIN32)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF()

file(
        GLOB_RECURSE

        source_files

        ./*
    )

ADD_EXECUTABLE( Compiler 

    ${source_files}
)
