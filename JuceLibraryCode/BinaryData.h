/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   libMTS_so;
    const int            libMTS_soSize = 29288;

    extern const char*   libMTS_dylib;
    const int            libMTS_dylibSize = 84704;

    extern const char*   libMTSMac_v1_00_pkg;
    const int            libMTSMac_v1_00_pkgSize = 44343;

    extern const char*   libMTS_dylib2;
    const int            libMTS_dylib2Size = 159696;

    extern const char*   libMTSMacARM_v1_00_pkg;
    const int            libMTSMacARM_v1_00_pkgSize = 41144;

    extern const char*   LIBMTS_dll;
    const int            LIBMTS_dllSize = 54080;

    extern const char*   LIBMTS_dll2;
    const int            LIBMTS_dll2Size = 59200;

    extern const char*   libMTSWin_v1_00_exe;
    const int            libMTSWin_v1_00_exeSize = 1526976;

    extern const char*   MTSESP_conf;
    const int            MTSESP_confSize = 504;

    extern const char*   LICENSE;
    const int            LICENSESize = 661;

    extern const char*   README_md;
    const int            README_mdSize = 5937;

    extern const char*   APIIdeas;
    const int            APIIdeasSize = 79712;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 12;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
