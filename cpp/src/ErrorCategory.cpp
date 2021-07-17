/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ErrorCategory.h"

namespace Ishiko
{
namespace Platform
{

const ErrorCategory& ErrorCategory::Get() noexcept
{
    static ErrorCategory theCategory;
    return theCategory;
}

const char* ErrorCategory::name() const noexcept
{
    return "Ishiko::Platform::ErrorCategory";
}

void Fail(Error& error, ErrorCategory::ErrorValues value) noexcept
{
    error.fail(value, ErrorCategory::Get());
}

void Fail(Error& error, ErrorCategory::ErrorValues value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(value, ErrorCategory::Get(), message, file, line);
}

}
}
