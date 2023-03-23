set(component common)
project(${project}-${component} LANGUAGES CXX)

set(${PROJECT_NAME}_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}")

file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS   "${${PROJECT_NAME}_INCLUDE_DIR}/*.hpp")

add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_HEADERS}
)

add_library(${project}::${component} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD                17
    CXX_STANDARD_REQUIRED       YES
    CXX_EXTENSIONS              NO
    POSITION_INDEPENDENT_CODE   YES
    RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY    "${CMAKE_BINARY_DIR}/lib"
    LINKER_LANGUAGE             CXX
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
     ${CMAKE_CURRENT_LIST_DIR}
)
