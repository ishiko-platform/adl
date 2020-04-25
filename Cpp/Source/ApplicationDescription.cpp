/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-Platform/ADL/blob/master/LICENSE.txt
*/

#include "ApplicationDescription.h"

namespace Ishiko
{
namespace Platform
{
    
ApplicationDescription::ApplicationDescription(const std::string& applicatioName)
    : m_applicationName(applicatioName)
{
}

const std::string& ApplicationDescription::applicationName() const
{
    return m_applicationName;
}

}
}
