#include "version.h"
#include "configure_version.h"

#ifndef	PROJECT_VERSION_PATCH
#define  PROJECT_VERSION_PATCH  0
#endif

#ifndef	PROJECT_VERSION_MINOR
#define  PROJECT_VERSION_MINOR  0
#endif

#ifndef	PROJECT_VERSION_MAJOR
#define  PROJECT_VERSION_MAJOR  0
#endif


int GetProjectVersionMajor()
{
    return PROJECT_VERSION_MAJOR;
}

int GetProjectVersionMinor()
{
    return PROJECT_VERSION_MINOR;
}

int GetProjectVersionPatch()
{
    return PROJECT_VERSION_PATCH;
}

int versions::GetProjectVersion(const VersionLevel aLevel)
{
    switch (aLevel)
    {
    case VersionLevel::Major:
        return GetProjectVersionMajor();
    case VersionLevel::Minor:
        return GetProjectVersionMinor();
    case VersionLevel::Patch:
        return GetProjectVersionPatch();
    default:
        return 0;
    }
}

std::string versions::GetCurrentProjectVersion()
{
    auto versionMajor = GetProjectVersionMajor();
    auto versionMinor = GetProjectVersionMinor();
    auto versionPatch = GetProjectVersionPatch();
    char buffer[256] = {};
    sprintf(buffer, "%d.%d.%d", versionMajor, versionMinor, versionPatch);
    return  std::string(buffer);
}