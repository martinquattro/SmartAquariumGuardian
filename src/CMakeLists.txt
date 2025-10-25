file(GLOB_RECURSE app_sources 
    "${PROJECT_DIR}/src/*.cpp"
    "${PROJECT_DIR}/framework/*.cpp"
)

idf_component_register(
    SRCS ${app_sources}
    INCLUDE_DIRS
        ${PROJECT_DIR}
        ${PROJECT_DIR}/include
    REQUIRES
        mqtt
)