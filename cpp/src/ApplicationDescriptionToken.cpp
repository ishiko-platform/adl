/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionToken.h"

namespace Ishiko
{
namespace Platform
{

ApplicationDescriptionToken::ApplicationDescriptionToken(Type type, const std::string& value)
    : m_type(type), m_value(value)
{
}

ApplicationDescriptionToken::Type ApplicationDescriptionToken::type() const
{
    return m_type;
}

bool ApplicationDescriptionToken::isKeyword() const
{
    return (m_type == keyword);
}

bool ApplicationDescriptionToken::isEOF() const
{
    return (m_type == eof);
}

const std::string& ApplicationDescriptionToken::value() const
{
    return m_value;
}

}
}
