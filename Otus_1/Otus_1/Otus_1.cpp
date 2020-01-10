#include <iostream>
#include "version.h"
#include <string>

int main()
{
    std::cout << "Hello World!" << std::endl;
    auto versionMajor = versions::GetProjectVersion(versions::VersionLevel::Major);
    auto versionMinor = versions::GetProjectVersion(versions::VersionLevel::Minor);
    auto versionPatch = versions::GetProjectVersion(versions::VersionLevel::Patch);
    std::cout << "Version: "<< versions::GetCurrentProjectVersion() << std::endl;
    return 0;
}
