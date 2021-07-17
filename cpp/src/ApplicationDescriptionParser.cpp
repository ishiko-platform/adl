/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionParser.h"

namespace Ishiko
{
namespace Platform
{
    
void ApplicationDescriptionParser::open(const boost::filesystem::path& filename, Error& error)
{
    m_file.open(filename.string(), error);
}

ApplicationDescription ApplicationDescriptionParser::parseApplicationDescription()
{
    return ApplicationDescription("");
}

}
}
