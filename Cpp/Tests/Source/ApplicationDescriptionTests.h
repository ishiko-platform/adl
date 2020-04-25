/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-Platform/ADL/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TEST_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTION_H_
#define _ISHIKO_TEST_PLATFORM_ADL_CPP_APPLICATIONDESCRIPTION_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class ApplicationDescriptionTests : public Ishiko::Tests::TestSequence
{
public:
    ApplicationDescriptionTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
};

#endif
