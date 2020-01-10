#define BOOST_TEST_MODULE test_version

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "version.h"
#include <string>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(
           (versions::GetProjectVersion(versions::VersionLevel::Major) != 0) 
        || (versions::GetProjectVersion(versions::VersionLevel::Minor) != 0) 
        || (versions::GetProjectVersion(versions::VersionLevel::Patch) != 0)
    );
}
}


