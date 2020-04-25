/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-Platform/ADL/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTION_H_
#define _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTION_H_

#include <string>

namespace Ishiko
{
namespace Platform
{

class ApplicationDescription
{
public:
    explicit ApplicationDescription(const std::string& applicatioName);

    const std::string& applicationName() const;

private:
    std::string m_applicationName;
};

}
}

#include "linkoptions.h"

#endif
