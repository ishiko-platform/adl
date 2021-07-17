/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTION_H_
#define _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTION_H_

#include <Ishiko/Errors.h>
#include <string>

namespace Ishiko
{
namespace Platform
{

class ApplicationDescription
{
public:
    explicit ApplicationDescription(const std::string& applicationName);
    static ApplicationDescription CreateFromFile(const std::string& path, Error& error);

    const std::string& applicationName() const;

private:
    ApplicationDescription() = default;

private:
    std::string m_applicationName;
};

}
}

#endif
