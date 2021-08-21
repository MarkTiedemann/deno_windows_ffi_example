@echo off
setlocal

rem Download Visual Studio 2019 and install the "Desktop development with C++" workload

set msvc_version=14.29.30133
set kit_version=10.0.19041.0

set "vc_path=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\%msvc_version%"
set "kit_include_path=C:\Program Files (x86)\Windows Kits\10\Include\%kit_version%"
set "kit_lib_path=C:\Program Files (x86)\Windows Kits\10\Lib\%kit_version%"

set "path=%vc_path%\bin\Hostx64\x64;%path%"
set "include=%kit_include_path%\um;%kit_include_path%\shared;%kit_include_path%\ucrt;%vc_path%\include"
set "lib=%vc_path%\lib\x64;%kit_lib_path%\um\x64;%kit_lib_path%\ucrt\x64"

cl /nologo /WX /Wall /LD /MD ver.c /link /DEFAULTLIB:advapi32.lib /EXPORT:CurrentMajorVersionNumber /EXPORT:CurrentMinorVersionNumber /EXPORT:CurrentBuildNumber /EXPORT:UpdateBuildRevision
