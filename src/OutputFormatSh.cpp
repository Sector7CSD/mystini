//
// Created by chris on 14.08.23.
//

#include "OutputFormatSh.h"

#include <fmt/core.h>

void OutputFormatSh::format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName)
{
    for (const auto &[sectionName, sectionContent] : ini.sections)
    {
        if (sectionName == inSectionName || inSectionName.empty())
        {
            for (const auto &[paramName, value] : sectionContent)
            {
                if (paramName == inParamName || inParamName.empty())
                {
                    // check if value string contains spaces, if so, warp it in single quotes
                    if (value.find_first_of(' ') != std::string::npos)
                    {
                        std::cout << fmt::format("{}='{}'", paramName, value) << std::endl;
                    }
                    else
                    {
                        std::cout << fmt::format("{}={}", paramName, value) << std::endl;
                    }
                }
            }
        }
    }
}

OutputFormat *OutputFormatSh::create()
{
    return new OutputFormatSh();
}
