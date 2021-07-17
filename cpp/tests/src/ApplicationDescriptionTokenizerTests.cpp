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
    append<HeapAllocationErrorsTest>("readNextToken test 1", ReadNextTokenTest1);
    append<HeapAllocationErrorsTest>("readNextToken test 2", ReadNextTokenTest2);
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

void ApplicationDescriptionTokenizerTests::ReadNextTokenTest1(Test& test)
{
    boost::filesystem::path inputPath = test.environment().getTestDataPath("TestApplication1.ikpadl");

    Error error;
    ApplicationDescriptionTokenizer tokenizer;
    tokenizer.open(inputPath, error);

    ISHTF_ABORT_IF(error);

    ApplicationDescriptionToken token = tokenizer.readNextToken(error);

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NEQ(token.type(), ApplicationDescriptionToken::keyword);
    ISHTF_FAIL_IF_NEQ(token.value(), "app");
    ISHTF_PASS();
}

void ApplicationDescriptionTokenizerTests::ReadNextTokenTest2(Test& test)
{
    boost::filesystem::path inputPath = test.environment().getTestDataPath("TestApplication1.ikpadl");

    Error error;
    ApplicationDescriptionTokenizer tokenizer;
    tokenizer.open(inputPath, error);

    ISHTF_ABORT_IF(error);

    ApplicationDescriptionToken token1 = tokenizer.readNextToken(error);

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NEQ(token1.type(), ApplicationDescriptionToken::keyword);
    ISHTF_FAIL_IF_NEQ(token1.value(), "app");

    ApplicationDescriptionToken token2 = tokenizer.readNextToken(error);

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NEQ(token2.type(), ApplicationDescriptionToken::whitespace);
    ISHTF_FAIL_IF_NEQ(token2.value(), " ");

    ApplicationDescriptionToken token3 = tokenizer.readNextToken(error);

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NEQ(token3.type(), ApplicationDescriptionToken::name);
    ISHTF_FAIL_IF_NEQ(token3.value(), "TestApplication1");

    ISHTF_PASS();
}
