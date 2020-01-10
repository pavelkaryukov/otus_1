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

std::string ConvertToStr(const int aNumber)
{
    char buffer[256] = {};
    auto convertRes = _itoa_s(aNumber, buffer, sizeof(buffer), 10);
    if (convertRes) {
        return ".Cant convert version to string.";
    }
    return std::string(buffer);
};


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
    if ((GetProjectVersionMajor()) == 0 && (GetProjectVersionMinor() == 0) && (GetProjectVersionPatch() == 0))
        return std::string();
    return  ConvertToStr(GetProjectVersionMajor()) + "." + ConvertToStr(GetProjectVersionMinor()) + "." + ConvertToStr(GetProjectVersionPatch());
}