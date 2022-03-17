#include <catch2/catch_test_macros.hpp>
#include <catch2/internal/catch_test_case_info_hasher.hpp>

static constexpr Catch::SourceLineInfo dummySourceLineInfo = CATCH_INTERNAL_LINEINFO;

TEST_CASE( "TestCaseInfoHasher produces equal hashes." ) {
    SECTION( "class names and names and tags are equal." ) {
        Catch::TestCaseInfo testCase1("", {"name", "[.magic-tag1]"}, dummySourceLineInfo);
        Catch::TestCaseInfo testCase2("", {"name", "[.magic-tag1]"}, dummySourceLineInfo);

        Catch::TestCaseInfoHasher h;
        CHECK(h(testCase1) == h(testCase2));
    }
}

TEST_CASE( "TestCaseInfoHasher produces different hashes." ) {
    SECTION( "class names are equal, names are equal but tags are different." ) {
        Catch::TestCaseInfo testCase1("", {"name", "[.magic-tag1]"}, dummySourceLineInfo);
        Catch::TestCaseInfo testCase2("", {"name", "[.magic-tag2]"}, dummySourceLineInfo);

        Catch::TestCaseInfoHasher h;
        CHECK(h(testCase1) != h(testCase2));
    }

    SECTION( "class names are equal, tags are equal but names are different" ) {
        Catch::TestCaseInfo testCase1("", {"name1", "[.magic-tag]"}, dummySourceLineInfo);
        Catch::TestCaseInfo testCase2("", {"name2", "[.magic-tag]"}, dummySourceLineInfo);

        Catch::TestCaseInfoHasher h;
        CHECK(h(testCase1) != h(testCase2));
    }

    SECTION( "names are equal, tags are equal but class names are different" ) {
        Catch::TestCaseInfo testCase1("class1", {"name", "[.magic-tag]"}, dummySourceLineInfo);
        Catch::TestCaseInfo testCase2("class2", {"name", "[.magic-tag]"}, dummySourceLineInfo);

        Catch::TestCaseInfoHasher h;
        CHECK(h(testCase1) != h(testCase2));
    }
}
