add_library(my_print
src/print_result.cpp
)

target_include_directories(my_print PUBLIC include)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/my_print/print_result.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/my_print)
install(TARGETS my_print DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/my_print)
