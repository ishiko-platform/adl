/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionTokenizer.h"
#include "ErrorCategory.h"
#include <Ishiko/Text.h>

using namespace Ishiko::Text;

namespace Ishiko
{
namespace Platform
{
    
void ApplicationDescriptionTokenizer::open(const boost::filesystem::path& filename, Error& error)
{
    m_file.open(filename.string(), error);
    m_currentLine = "";
    m_currentLineIt = m_currentLine.begin();
}

ApplicationDescriptionToken ApplicationDescriptionTokenizer::readNextToken(Error& error)
{
    // If we are at the end of the current line, try to read the next line. The loop is to skip blank lines.
    while (m_currentLineIt == m_currentLine.end())
    {
        Error readError;
        m_currentLine = m_file.readLine(readError);
        m_currentLineIt = m_currentLine.begin();

        if (readError)
        {
            if (readError.condition().value() == FileSystem::ErrorCategory::eEndOfFile)
            {
                return ApplicationDescriptionToken(ApplicationDescriptionToken::eof, "");
            }
            else
            {
                error.fail(readError);
                return ApplicationDescriptionToken(ApplicationDescriptionToken::invalid, "");
            }
        }
    }

    std::string::iterator it = m_currentLineIt;
    if (ASCII::IsAlpha(*it))
    {
        ++it;
        while ((it != m_currentLine.end()) && ASCII::IsAlpha(*it))
        {
            ++it;
        }
        std::string token(m_currentLineIt, it);
        if (token == "app")
        {
            return ApplicationDescriptionToken(ApplicationDescriptionToken::keyword, token);
        }
    }
    else
    {
        Fail(error, ErrorCategory::generic);
    }
    

    return ApplicationDescriptionToken(ApplicationDescriptionToken::invalid, "");
}

}
}
