FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse.git
        GIT_TAG af442b4da0cd7a07b56fa709bd16571889dc7fda # v3.0
)

FetchContent_GetProperties(argparse)
if (NOT argparse_POPULATED)
    FetchContent_Populate(argparse)
    add_subdirectory(${argparse_SOURCE_DIR} ${argparse_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()

FetchContent_Declare(
        inipp
        GIT_REPOSITORY https://github.com/mcmtroffaes/inipp
        GIT_TAG 32732d4e469ba7da8b5170d65e1bc0af9739e77f # 1.0.12
)

FetchContent_GetProperties(inipp)
if (NOT inipp_POPULATED)
    FetchContent_Populate(inipp)
    add_subdirectory(${inipp_SOURCE_DIR} ${inipp_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()

find_package(fmt CONFIG REQUIRED)

add_executable(mystini
        main.cpp
        inipp.h
        OutputFormat.h
        OutputFormatIni.cpp
        OutputFormatIni.h
        OutputFormatPlain.cpp
        OutputFormatPlain.h
        Subcommand.cpp
        Subcommand.h
        consts.h
        OutputFormatSh.cpp
        OutputFormatSh.h
        OutputFormatLines.cpp
        OutputFormatLines.h
        ActionGet.cpp
        ActionGet.h
        ActionSet.cpp
        ActionSet.h
        ActionDel.cpp
        ActionDel.h
        Utils.cpp
        Utils.h
)

target_link_libraries(mystini
        PRIVATE fmt::fmt
        PRIVATE argparse
)

add_custom_command(
        OUTPUT ${PROJECT_BINARY_DIR}/mystini.1
        DEPENDS ${PROJECT_SOURCE_DIR}/src/mystini.1.md
        COMMAND pandoc --standalone --to man ${PROJECT_SOURCE_DIR}/src/mystini.1.md -o ${PROJECT_BINARY_DIR}/mystini.1
        COMMENT "Generating manpage"
)

add_custom_target(generate_manpage ALL
        DEPENDS ${PROJECT_BINARY_DIR}/mystini.1
)

install(
        FILES ${CMAKE_BINARY_DIR}/mystini.1
        DESTINATION share/man/man1
)

install(TARGETS mystini DESTINATION bin)