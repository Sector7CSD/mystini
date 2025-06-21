//
// Created by chris on 13.08.23.
//

#ifndef OUTPUTFORMATINI_H
#define OUTPUTFORMATINI_H

#include "OutputFormat.h"

class OutputFormatIni : public OutputFormat
{
  public:
    static OutputFormat *create();

    void format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName) override;
};

#endif // OUTPUTFORMATINI_H
