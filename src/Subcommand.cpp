//
// Created by chris on 14.08.23.
//

#include "Subcommand.h"

#include "consts.h"

Subcommand::Subcommand(argparse::ArgumentParser *program, const char *name, const char *help, bool section_required,
                       const Subcommand::commandFunc &func)
{
    argumentParser = new argparse::ArgumentParser(name);
    argumentParser->add_description(help);
    add_common_params(section_required);
    program->add_subparser(*argumentParser);
    command = func;

    if (strstr(name, "get") == name)
    {
        argumentParser->add_argument(PARAM_FORMAT)
            .help("Select the output format. Valid formats are 'sh', 'ini','lines'")
            .metavar("FMT");
    }

    if (strstr(name, "set") == name)
    {
        argumentParser->add_argument(PARAM_VALUE).help("The value to set the param to").metavar("VALUE");
    }
}

void Subcommand::add_common_params(bool section_required)
{
    argumentParser->add_argument(PARAM_FILE).help("The ini file to process").required().metavar("FILE");

    if (section_required)
    {
        argumentParser->add_argument(PARAM_SECTION)
            .help("The section of the ini to process")
            .required()
            .metavar("section");
    }
    else
    {
        argumentParser->add_argument(PARAM_SECTION).help("The section of the ini to process").metavar("SECTION");
    }

    argumentParser->add_argument(PARAM_PARAM).help("The parameter to perform the action on").metavar("PARAM");
}

const argparse::ArgumentParser *Subcommand::getArgumentParser() const
{
    return argumentParser;
}

const Subcommand::commandFunc &Subcommand::getCommand() const
{
    return command;
}

Subcommand::~Subcommand()
{
    delete argumentParser;
}
