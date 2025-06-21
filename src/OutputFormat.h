//
// Created by chris on 13.08.23.
//

#ifndef OUTPUTFORMAT_H
#define OUTPUTFORMAT_H

#include "inipp.h"

class OutputFormat
{
  public:
    virtual void format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName) = 0;

    virtual ~OutputFormat() = default;
};

#endif // OUTPUTFORMAT_H
