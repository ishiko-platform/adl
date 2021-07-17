/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionTokenizerTests.h"
#include "Ishiko/Platform/ADL/ApplicationDescriptionTokenizer.h"

using namespace Ishiko;
using namespace Ishiko::Platform;
using namespace Ishiko::Tests;

ApplicationDescriptionTokenizerTests::ApplicationDescriptionTokenizerTests(const TestNumber& number,
    const TestEnvironment& environment)
    : TestSequence(number, "ApplicationDescriptionTokenizer tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("open test 1", OpenTest1);
}

void ApplicationDescriptionTokenizerTests::ConstructorTest1(Test& test)
{
    ApplicationDescriptionTokenizer tokenizer;

    ISHTF_PASS();
}

void ApplicationDescriptionTokenizerTests::OpenTest1(Test& test)
{
    boost::filesystem::path inputPath = test.environment().getTestDataPath("TestApplication1.ikpadl");

    ApplicationDescriptionTokenizer tokenizer;

    Error error;
    tokenizer.open(inputPath, error);

    ISHTF_FAIL_IF(error);
    ISHTF_PASS();
}