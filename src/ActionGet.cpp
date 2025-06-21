//
// Created by chris on 15.08.23.
//

#include "ActionGet.h"
#include "consts.h"

#include "OutputFormatIni.h"
#include "OutputFormatLines.h"
#include "OutputFormatPlain.h"
#include "OutputFormatSh.h"
#include "Utils.h"

int ActionGet::execute(const argparse::ArgumentParser *args, inipp::Ini<char> *pIni, const std::string &inFileName,
                       const std::string &inSectionName, const std::string &inParamName)
{
    // use specific format (plain (just print section names -> default), ini, sh, lines)
    using createFunc = std::function<OutputFormat *()>;

    std::map<std::string, createFunc> outputFormats;
    outputFormats.insert({PARAM_FORMAT_INI, OutputFormatIni::create});
    outputFormats.insert({PARAM_FORMAT_SH, OutputFormatSh::create});
    outputFormats.insert({PARAM_FORMAT_LINES, OutputFormatLines::create});

    OutputFormatPlain plainOutputFormat;
    OutputFormat *outputFormat = &plainOutputFormat;

    if (args->is_used(PARAM_FORMAT))
    {
        const auto &wantedFormat = args->get(PARAM_FORMAT);
        auto result = outputFormats.find(wantedFormat);
        if (result != outputFormats.end())
        {
            outputFormat = result->second();
        }
    }

    // output
    outputFormat->format(*pIni, inSectionName, inParamName);

    // clean up
    if (outputFormat != &plainOutputFormat)
    {
        delete outputFormat;
    }

    delete pIni;

    return 0;
}
