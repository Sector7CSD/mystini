//
// Created by chris on 13.08.23.
//

#ifndef OUTPUTFORMATPLAIN_H
#define OUTPUTFORMATPLAIN_H

#include "OutputFormat.h"

class OutputFormatPlain : public OutputFormat
{
  public:
    void format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName) override;
};

#endif // OUTPUTFORMATPLAIN_H
