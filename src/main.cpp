#include "Subcommand.h"

#include "ActionDel.h"
#include "ActionGet.h"
#include "ActionSet.h"
#include "Utils.h"
#include "consts.h"
#include <argparse/argparse.hpp>

#include <functional>
#include <iostream>
#include <map>

argparse::ArgumentParser program("mystini", "0.1");

int main(int argc, char *argv[])
{
    std::map<std::string, const Subcommand *> commandMap;

    commandMap["get"] = new Subcommand(&program, "get", "Get a value from given Ini file", false, ActionGet::execute);

    commandMap["set"] =
        new Subcommand(&program, "set", "Set a value for given Ini file and parameter", true, ActionSet::execute);

    commandMap["del"] =
        new Subcommand(&program, "del", "Deletes a value for given Ini file and parameter", true, ActionDel::execute);

    try
    {
        program.parse_args(argc, argv);

        for (const auto &[key, value] : commandMap)
        {
            if (program.is_subcommand_used(key))
            {
                auto args = value->getArgumentParser();

                const auto &inFileName = args->get(PARAM_FILE);
                const auto &inSectionName = args->is_used(PARAM_SECTION) ? args->get(PARAM_SECTION) : "";
                const auto &inParamName = args->is_used(PARAM_PARAM) ? args->get(PARAM_PARAM) : "";

                auto pIni = Utils::loadIniFile(inFileName);
                auto command = value->getCommand();

                return command(args, pIni, inFileName, inSectionName, inParamName);
            }
        }
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    // clean up
    for (const auto &[key, value] : commandMap)
    {
        delete value;
    }

    return 0;
}
