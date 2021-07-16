/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-Platform/ADL/blob/master/LICENSE.txt
*/

#include "ApplicationDescription.h"
#include "yaml-cpp/yaml.h"

namespace Ishiko
{
namespace Platform
{
    
ApplicationDescription::ApplicationDescription(const std::string& applicatioName)
    : m_applicationName(applicatioName)
{
}

ApplicationDescription ApplicationDescription::CreateFromFile(const std::string& path)
{
    ApplicationDescription result;
    YAML::Node config = YAML::LoadFile(path);
    result.m_applicationName = config["application"]["name"].as<std::string>();
    return result;
}

const std::string& ApplicationDescription::applicationName() const
{
    return m_applicationName;
}

}
}
