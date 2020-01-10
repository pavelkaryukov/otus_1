#pragma once
#include <string>
namespace versions
{
    enum class VersionLevel
    {
        Major,
        Minor,
        Patch
    };

    int GetProjectVersion(const VersionLevel aLevel);

    std::string GetCurrentProjectVersion();
}
