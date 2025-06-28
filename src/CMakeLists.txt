FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse.git
        GIT_TAG af442b4da0cd7a07b56fa709bd16571889dc7fda # v3.0
)
FetchContent_MakeAvailable(argparse)

FetchContent_Declare(
        inipp
        GIT_REPOSITORY https://github.com/mcmtroffaes/inipp
        GIT_TAG 3c1668812026f1a94471b85ac5ab11ab87c43607 # 1.0.13
)
FetchContent_MakeAvailable(inipp)

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

install(TARGETS mystini DESTINATION bin)
