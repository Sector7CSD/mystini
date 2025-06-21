//
// Created by chris on 15.08.23.
//

#ifndef ACTIONGET_H
#define ACTIONGET_H

#include "inipp.h"
#include <argparse/argparse.hpp>

class ActionGet
{
  public:
    static int execute(const argparse::ArgumentParser *args, inipp::Ini<char> *pIni, const std::string &inFileName,
                       const std::string &inSectionName, const std::string &inParamName);
};

#endif // ACTIONGET_H
