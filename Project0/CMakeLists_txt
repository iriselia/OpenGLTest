cmake_minimum_required( VERSION 2.8 )

find_package(OpenGL REQUIRED)

#ADD_DEFINITIONS("-D_GLFW_USE_OPENGL" "-D_GLFW_WIN32" "-D_GLFW_WGL")
#add_definitions("-D_GLFW_USE_CONFIG_H")


SET( INCLUDE_DIRS
	${common_INCLUDE_DIRS}
	${glm_INCLUDE_DIRS}
	${glew_INCLUDE_DIRS}
	${glfw_INCLUDE_DIRS}
)
SET( LINK_DIRS
)
SET( LINK_LIBS
	${OPENGL_LIBRARIES}
	common
	glm
	glew
	glfw
	zlib
	assimp
)

parse_directory_name(PROJECT_NAME)
project( ${PROJECT_NAME} )
create_project_ex(CONSOLE "${INCLUDE_DIRS}" "${LINK_DIRS}" "${LINK_LIBS}")
