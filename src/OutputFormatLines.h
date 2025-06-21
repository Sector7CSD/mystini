//
// Created by chris on 14.08.23.
//

#ifndef OUTPUTFORMATLINES_H
#define OUTPUTFORMATLINES_H

#include "OutputFormat.h"

class OutputFormatLines : public OutputFormat
{
  public:
    static OutputFormat *create();

    void format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName) override;
};

#endif // OUTPUTFORMATLINES_H
