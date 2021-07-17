/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionTests.h"
#include "Ishiko/Platform/ADL/ApplicationDescription.h"

using namespace Ishiko;
using namespace Ishiko::Platform;
using namespace Ishiko::Tests;

ApplicationDescriptionTests::ApplicationDescriptionTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "ApplicationDescription tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("CreateFromFile test 1", CreateFromFileTest1);
    append<HeapAllocationErrorsTest>("CreateFromFile test 2", CreateFromFileTest2);
}

void ApplicationDescriptionTests::ConstructorTest1(Test& test)
{
    ApplicationDescription applicationDescription("ConstructorTest1");

    ISHTF_FAIL_IF_NEQ(applicationDescription.applicationName(), "ConstructorTest1");
    ISHTF_PASS();
}

void ApplicationDescriptionTests::CreateFromFileTest1(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "doesnotexist");

    Error error;
    ApplicationDescription applicationDescription = ApplicationDescription::CreateFromFile(inputPath.string(), error);

    ISHTF_FAIL_IF_NOT(error);
    ISHTF_PASS();
}

void ApplicationDescriptionTests::CreateFromFileTest2(Test& test)
{
    boost::filesystem::path inputPath(test.environment().getTestDataDirectory() / "TestApplication1.ikpadl");

    Error error;
    ApplicationDescription applicationDescription = ApplicationDescription::CreateFromFile(inputPath.string(), error);

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NEQ(applicationDescription.applicationName(), "TestApplication1");
    ISHTF_PASS();
}
