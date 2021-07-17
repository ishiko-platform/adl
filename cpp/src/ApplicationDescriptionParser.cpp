/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionParser.h"
#include "ApplicationDescriptionToken.h"
#include "ErrorCategory.h"

namespace Ishiko
{
namespace Platform
{
    
void ApplicationDescriptionParser::open(const boost::filesystem::path& filename, Error& error)
{
    m_tokenizer.open(filename.string(), error);
}

ApplicationDescription ApplicationDescriptionParser::parseApplicationDescription(Error& error)
{
    ApplicationDescriptionToken token = m_tokenizer.readNextToken(error);
    if (token.isKeyword())
    {
        if (token.value() == "app")
        {
        }
        else
        {
            Fail(error, ErrorCategory::generic);
        }
    }
    else
    {
        Fail(error, ErrorCategory::generic);
    }

    return ApplicationDescription("");
}

}
}
