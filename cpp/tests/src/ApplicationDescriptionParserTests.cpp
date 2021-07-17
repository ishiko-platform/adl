/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionParserTests.h"
#include "Ishiko/Platform/ADL/ApplicationDescriptionParser.h"

using namespace Ishiko;
using namespace Ishiko::Platform;
using namespace Ishiko::Tests;

ApplicationDescriptionParserTests::ApplicationDescriptionParserTests(const TestNumber& number,
    const TestEnvironment& environment)
    : TestSequence(number, "ApplicationDescriptionParser tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("open test 1", OpenTest1);
}

void ApplicationDescriptionParserTests::ConstructorTest1(Test& test)
{
    ApplicationDescriptionParser parser;

    ISHTF_PASS();
}

void ApplicationDescriptionParserTests::OpenTest1(Test& test)
{
    boost::filesystem::path inputPath = test.environment().getTestDataPath("TestApplication1.ikpadl");

    ApplicationDescriptionParser parser;

    Error error;
    parser.open(inputPath, error);

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}
