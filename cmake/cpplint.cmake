find_program(CPPLINT_BIN NAMES cpplint)

if(CPPLINT_BIN)
  message(STATUS "Found: cpplint")
  list(
        APPEND CMAKE_CXX_CPPLINT
            "${CPPLINT_BIN}"
            "--filter=-legal/copyright"
    )
endif()
