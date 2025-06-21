//
// Created by chris on 13.08.23.
//

#include "OutputFormatPlain.h"

void OutputFormatPlain::format(inipp::Ini<char> &ini, std::string inSectionName, std::string inParamName)
{
    if (!inSectionName.empty())
    {
        if (!inParamName.empty())
        {
            // both arguments given, plain print value
            const auto &value = ini.sections[inSectionName][inParamName];
            std::cout << value << std::endl;
        }
        else
        {
            // only section name is given, plain print all keys for that section
            for (const auto &[sectionName, sectionContent] : ini.sections)
            {
                if (sectionName == inSectionName)
                {
                    for (const auto &[paramName, value] : sectionContent)
                    {
                        std::cout << paramName << std::endl;
                    }
                }
            }
        }
    }
    else
    {
        // if no section is given, plain print all section names
        for (const auto &[sectionName, sectionContent] : ini.sections)
        {
            std::cout << sectionName << std::endl;
        }
    }
}
