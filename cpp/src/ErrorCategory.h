/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_ERRORCATEGORY_H_
#define _ISHIKO_PLATFORM_ADL_CPP_ERRORCATEGORY_H_

#include <Ishiko/Errors.h>

namespace Ishiko
{
namespace Platform
{

class ErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum ErrorValues
    {
        generic = -1
    };

    static const ErrorCategory& Get() noexcept;

    const char* name() const noexcept override;

private:
    ErrorCategory() noexcept = default;
};

void Fail(Error& error, ErrorCategory::ErrorValues value) noexcept;
void Fail(Error& error, ErrorCategory::ErrorValues value, const std::string& message, const char* file,
    int line) noexcept;

}
}

#endif
