FILE(GLOB_RECURSE app_sources 
    ${CMAKE_SOURCE_DIR}/src/*.* 
    ${CMAKE_SOURCE_DIR}/framework/*.cpp
)

idf_component_register(
    SRCS ${app_sources}
    INCLUDE_DIRS 
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/framework
        ${CMAKE_SOURCE_DIR}/framework/drivers
)