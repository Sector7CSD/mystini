//
// Created by chris on 15.08.23.
//

#include "Utils.h"
#include <fstream>

inipp::Ini<char> *Utils::loadIniFile(const std::string &fileName)
{
    auto pIni = new inipp::Ini<char>;
    std::ifstream is(fileName);

    pIni->parse(is);
    pIni->interpolate();

    return pIni;
}

int Utils::saveIniFile(inipp::Ini<char> *pIni, const std::string &fileName)
{
    std::ofstream os(fileName);
    pIni->generate(os);

    return 0;
}
