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
}

ApplicationDescriptionToken ApplicationDescriptionTokenizer::readNextToken(Error& error)
{
    std::string line = m_file.readLine(error);

    if (line.size() > 0)
    {
        std::string::iterator it = line.begin();

        if (ASCII::IsAlpha(*it))
        {
            ++it;
            while (ASCII::IsAlpha(*it))
            {
                ++it;
            }
            std::string token(line.begin(), it);
            if (token == "app")
            {
                return ApplicationDescriptionToken(ApplicationDescriptionToken::keyword, token);
            }
        }
        else
        {
            Fail(error, ErrorCategory::generic);
        }
    }


    return ApplicationDescriptionToken(ApplicationDescriptionToken::invalid, "");
}

}
}
