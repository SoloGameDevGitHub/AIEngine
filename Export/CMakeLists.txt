add_definitions(-D MATHLIBRARY_EXPORTS)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/DLL)

set(FILES
        MathLibrary.cpp
        )
add_executable(MathLibrary ${FILES})

add_library(MathLibrary_DLL SHARED MathLibrary.cpp)
