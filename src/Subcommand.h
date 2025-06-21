//
// Created by chris on 14.08.23.
//

#ifndef SUBCOMMAND_H
#define SUBCOMMAND_H

#include "inipp.h"
#include <argparse/argparse.hpp>

class Subcommand
{
  public:
    using commandFunc =
        std::function<int(const argparse::ArgumentParser *args, inipp::Ini<char> *pIni, const std::string &inFileName,
                          const std::string &inSectionName, const std::string &inParamName)>;

    Subcommand(argparse::ArgumentParser *program, const char *name, const char *help, bool section_required,
               const commandFunc &func);
    ~Subcommand();

    void add_common_params(bool section_required);

    [[nodiscard]] const argparse::ArgumentParser *getArgumentParser() const;

    [[nodiscard]] const commandFunc &getCommand() const;

  protected:
    argparse::ArgumentParser *argumentParser;

    commandFunc command;
};

#endif // SUBCOMMAND_H
