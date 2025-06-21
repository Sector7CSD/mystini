//
// Created by chris on 13.08.23.
//

#include "OutputFormatIni.h"

#include <iostream>

#include <fmt/core.h>

void OutputFormatIni::format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName)
{
    for (const auto &[sectionName, sectionContent] : ini.sections)
    {
        if (sectionName == inSectionName || inSectionName.empty())
        {
            std::cout << fmt::format("[{}]", sectionName) << std::endl;
            for (const auto &[paramName, value] : sectionContent)
            {
                if (paramName == inParamName || inParamName.empty())
                {
                    std::cout << fmt::format("{} = {}", paramName, value) << std::endl;
                }
            }
        }
    }
}
OutputFormat *OutputFormatIni::create()
{
    return new OutputFormatIni();
}
