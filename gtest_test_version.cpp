#include <gtest/gtest.h> // googletest header file
#include "version.h"

TEST(gtest_test_version, Test1)
{
    ASSERT_TRUE(
            (versions::GetProjectVersion(versions::VersionLevel::Major) != 0)
         || (versions::GetProjectVersion(versions::VersionLevel::Minor) != 0)
         || (versions::GetProjectVersion(versions::VersionLevel::Patch) != 0)
    );
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}