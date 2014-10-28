cmake_minimum_required( VERSION 2.8 )

SET( INCLUDE_DIRS
)
SET( LINK_DIRS
)
SET( LINK_LIBS
)

#add_definitions("-D_GLFW_USE_CONFIG_H")
ADD_DEFINITIONS("-D_GLFW_USE_OPENGL" "-D_GLFW_WIN32" "-D_GLFW_WGL")
ADD_DEFINITIONS("-DGLEW_STATIC")

parse_directory_name(PROJECT_NAME)
project( ${PROJECT_NAME} )
create_project_ex(STATIC "${INCLUDE_DIRS}" "${LINK_DIRS}" "${LINK_LIBS}")
