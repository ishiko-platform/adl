/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_TESTS_APPLICATIONDESCRIPTIONTOKENIZERTESTS_H_
#define _ISHIKO_PLATFORM_ADL_CPP_TESTS_APPLICATIONDESCRIPTIONTOKENIZERTESTS_H_

#include <Ishiko/Tests.h>

class ApplicationDescriptionTokenizerTests : public Ishiko::Tests::TestSequence
{
public:
    ApplicationDescriptionTokenizerTests(const Ishiko::Tests::TestNumber& number,
        const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void OpenTest1(Ishiko::Tests::Test& test);
    static void ReadNextTokenTest1(Ishiko::Tests::Test& test);
    static void ReadNextTokenTest2(Ishiko::Tests::Test& test);
};

#endif
