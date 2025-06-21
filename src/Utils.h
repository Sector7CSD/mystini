//
// Created by chris on 15.08.23.
//

#ifndef UTILS_H
#define UTILS_H

#include "inipp.h"
class Utils
{
  public:
    static inipp::Ini<char> *loadIniFile(const std::string &fileName);
    static int saveIniFile(inipp::Ini<char> *pIni, const std::string &fileName);
};

#endif // UTILS_H
