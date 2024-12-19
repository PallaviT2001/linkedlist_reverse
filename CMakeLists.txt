cmake_minimum_required(VERSION 3.16)

project(Linkedlist_reverse LANGUAGES C)

add_executable(Linkedlist_reverse main.c)

include(GNUInstallDirs)
install(TARGETS Linkedlist_reverse
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
