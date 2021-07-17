/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_PLATFORM_ADL_CPP_TESTS_APPLICATIONDESCRIPTIONTESTS_H_
#define _ISHIKO_PLATFORM_ADL_CPP_TESTS_APPLICATIONDESCRIPTIONTESTS_H_

#include <Ishiko/Tests.h>

class ApplicationDescriptionTests : public Ishiko::Tests::TestSequence
{
public:
    ApplicationDescriptionTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void CreateFromFileTest1(Ishiko::Tests::Test& test);
};

#endif
