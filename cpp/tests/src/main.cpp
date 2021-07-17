/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-platform/adl/blob/main/LICENSE.txt
*/

#include "ApplicationDescriptionParserTests.h"
#include "ApplicationDescriptionTests.h"
#include "ApplicationDescriptionTokenizerTests.h"
#include "Ishiko/Platform/ADL/linkoptions.h"
#include <Ishiko/Tests.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoADL");

    theTestHarness.environment().setTestDataDirectory("../../data");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<ApplicationDescriptionTokenizerTests>();
    theTests.append<ApplicationDescriptionParserTests>();
    theTests.append<ApplicationDescriptionTests>();

    return theTestHarness.run();
}
