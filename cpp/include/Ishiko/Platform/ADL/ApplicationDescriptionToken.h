/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTIONTOKEN_H_
#define _ISHIKO_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTIONTOKEN_H_

#include <string>

namespace Ishiko
{
namespace Platform
{

class ApplicationDescriptionToken
{
public:
    enum Type
    {
        invalid,
        keyword,
        name,
        whitespace,
        eof
    };

    ApplicationDescriptionToken(Type type, const std::string& value);

    Type type() const;
    bool isKeyword() const;
    bool isName() const;
    bool isEOF() const;

    const std::string& value() const;

private:
    Type m_type;
    std::string m_value;
};

}
}

#endif
