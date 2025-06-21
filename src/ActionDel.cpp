//
// Created by chris on 15.08.23.
//

#include "ActionDel.h"
#include "Utils.h"

int ActionDel::execute(const argparse::ArgumentParser *args, inipp::Ini<char> *pIni, const std::string &inFileName,
                       const std::string &inSectionName, const std::string &inParamName)
{
    auto sectionIter = pIni->sections.find(inSectionName);
    if (sectionIter != pIni->sections.end())
    {
        auto paramIter = sectionIter->second.find(inParamName);
        if (paramIter != sectionIter->second.end())
        {
            sectionIter->second.erase(paramIter);
            Utils::saveIniFile(pIni, inFileName);
        }
    }

    return 0;
}
