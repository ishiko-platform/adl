/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTIONPARSER_H_
#define _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTIONPARSER_H_

#include "ApplicationDescription.h"
#include "ApplicationDescriptionTokenizer.h"
#include <boost/filesystem.hpp>
#include <Ishiko/Errors.h>
#include <string>

namespace Ishiko
{
namespace Platform
{

class ApplicationDescriptionParser
{
public:
    void open(const boost::filesystem::path& filename, Error& error);

    ApplicationDescription parseApplicationDescription(Error& error);

private:
    ApplicationDescriptionTokenizer m_tokenizer;
};

}
}

#endif
