//
// Created by chris on 14.08.23.
//

#include "OutputFormatLines.h"
#include <fmt/core.h>

void OutputFormatLines::format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName)
{
    for (const auto &[sectionName, sectionContent] : ini.sections)
    {
        if (sectionName == inSectionName || inSectionName.empty())
        {
            for (const auto &[paramName, value] : sectionContent)
            {
                if (paramName == inParamName || inParamName.empty())
                {
                    std::cout << fmt::format("[ {} ] {} = {}", sectionName, paramName, value) << std::endl;
                }
            }
        }
    }
}

OutputFormat *OutputFormatLines::create()
{
    return new OutputFormatLines();
}
