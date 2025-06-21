//
// Created by chris on 14.08.23.
//

#ifndef OUTPUTFORMATSH_H
#define OUTPUTFORMATSH_H

#include "OutputFormat.h"

class OutputFormatSh : public OutputFormat
{
  public:
    static OutputFormat *create();

    void format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName) override;
};

#endif // OUTPUTFORMATSH_H
