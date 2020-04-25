/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-Platform/ADL/blob/master/LICENSE.txt
*/

#include "ApplicationDescriptionTests.h"
#include "Ishiko/Platform/ADL/ApplicationDescription.h"

using namespace Ishiko::Tests;

ApplicationDescriptionTests::ApplicationDescriptionTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "ApplicationDescription tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void ApplicationDescriptionTests::ConstructorTest1(Test& test)
{
    Ishiko::Platform::ApplicationDescription applicationDescription("ConstructorTest1");

    ISHTF_FAIL_IF_NEQ(applicationDescription.applicationName(), "ConstructorTest1");
    ISHTF_PASS();
}
