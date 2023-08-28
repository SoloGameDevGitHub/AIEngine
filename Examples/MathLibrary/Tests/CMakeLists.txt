set(FILES
        MathLibraryTestMain.cpp
)
add_executable(MathLibrary ${FILES})

# link static library into executable
add_library(MathLibraryLib STATIC IMPORTED)
set_target_properties(MathLibraryLib PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/build/Libs/libMathLibrary.a)
target_link_libraries(MathLibrary PRIVATE MathLibraryLib)
