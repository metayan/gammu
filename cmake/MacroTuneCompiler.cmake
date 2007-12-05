# Adds flag to compiler if it supports it

macro (MACRO_TUNE_COMPILER _flag)
    string (TOUPPER "${_flag}" FLAGNAME)
    string (REPLACE "-" "_" FLAGNAME "${FLAGNAME}")
    string (REPLACE "=" "_" FLAGNAME "${FLAGNAME}")
    string (REPLACE "," "_" FLAGNAME "${FLAGNAME}")
    set (FLAGNAME "COMPILER_HAS${FLAGNAME}")
    check_c_compiler_flag("${_flag}" ${FLAGNAME})
    if (${FLAGNAME})
        set (CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} ${_flag}")
    endif (${FLAGNAME})
endmacro (MACRO_TUNE_COMPILER)
