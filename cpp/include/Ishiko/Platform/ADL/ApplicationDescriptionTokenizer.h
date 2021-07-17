/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTIONTOKENIZER_H_
#define _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTIONTOKENIZER_H_

#include "ApplicationDescriptionToken.h"
#include <boost/filesystem.hpp>
#include <Ishiko/Errors.h>
#include <Ishiko/FileSystem.h>

namespace Ishiko
{
namespace Platform
{

class ApplicationDescriptionTokenizer
{
public:
    void open(const boost::filesystem::path& filename, Error& error);

    ApplicationDescriptionToken readNextToken(Error& error);

private:
    FileSystem::TextFile m_file;
};

}
}

#endif
