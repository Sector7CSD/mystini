//
// Created by chris on 15.08.23.
//

#include "ActionSet.h"
#include "Utils.h"
#include "consts.h"

int ActionSet::execute(const argparse::ArgumentParser *args, inipp::Ini<char> *pIni, const std::string &inFileName,
                       const std::string &inSectionName, const std::string &inParamName)
{
    const auto &inParamValue = args->is_used(PARAM_VALUE) ? args->get(PARAM_VALUE) : "";

    // check if we have an existing section where we can store our data
    auto sectionIter = pIni->sections.find(inSectionName);
    if (sectionIter == pIni->sections.end())
    {
        // no, we have to create the section first
        pIni->sections.insert({{inSectionName}, {}});
        sectionIter = pIni->sections.find(inSectionName);
    }

    // insert data into section
    sectionIter->second[inParamName] = inParamValue;

    Utils::saveIniFile(pIni, inFileName);

    return 0;
}
