set(FILES
        FSM.cpp
)
add_compile_definitions(ENABLE_FSM_DEBUG)
add_executable(FSM ${FILES})
