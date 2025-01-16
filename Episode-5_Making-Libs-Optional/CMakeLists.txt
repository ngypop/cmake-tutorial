cmake_minimum_required(VERSION 3.28.3)

project(Making_Libs_Optional)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

option(USE_ADDER "Use adder library" ON)

configure_file(config.h.in config.h)

if(USE_ADDER)
    add_subdirectory(adder)    
        list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/adder")
        list(APPEND EXTRA_LIBS adder)
endif()


target_include_directories(${PROJECT_NAME}
    PUBLIC ${EXTRA_INCLUDES}
)    
    
target_link_libraries(${PROJECT_NAME}
    PUBLIC ${EXTRA_LIBS}
)