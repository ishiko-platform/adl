/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescription.h"
#include "ApplicationDescriptionParser.h"

namespace Ishiko
{
namespace Platform
{
    
ApplicationDescription::ApplicationDescription(const std::string& applicatioName)
    : m_applicationName(applicatioName)
{
}

ApplicationDescription ApplicationDescription::CreateFromFile(const std::string& path, Error& error)
{
    ApplicationDescriptionParser parser;
    parser.open(path, error);
    return parser.parseApplicationDescription(error);
}

const std::string& ApplicationDescription::applicationName() const
{
    return m_applicationName;
}

}
}
