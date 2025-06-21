//
// Created by chris on 15.08.23.
//

#ifndef ACTIONSET_H
#define ACTIONSET_H

#include "inipp.h"
#include <argparse/argparse.hpp>

class ActionSet
{
  public:
    static int execute(const argparse::ArgumentParser *args, inipp::Ini<char> *pIni, const std::string &inFileName,
                       const std::string &inSectionName, const std::string &inParamName);
};

#endif // ACTIONSET_H
