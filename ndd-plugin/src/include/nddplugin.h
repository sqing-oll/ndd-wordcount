#ifndef NDDPACKAGE_H
#define NDDPACKAGE_H

#include <cstring>

#define NDD_PLUGIN_VERSION 1

#ifdef _WIN32
#define NDD_PLUGIN_API __declspec(dllexport)
#else
#define NDD_PLUGIN_API __attribute__((visibility("default")))
#endif

typedef struct _NDD_PROC_DATA
{
    int nVersion;
    char szName[64];
} NDD_PROC_DATA;

#ifdef __cplusplus
extern "C" {
#endif

NDD_PLUGIN_API bool NDD_PROC_IDENTIFY(NDD_PROC_DATA* pData);
NDD_PLUGIN_API void NDD_PROC_MENU_CLICK(int nMenuID);

NDD_PLUGIN_API void NDD_GetText(char* szText, int nSize);
NDD_PLUGIN_API void NDD_GetSelectedText(char* szText, int nSize);
NDD_PLUGIN_API void NDD_SetText(const char* szText);
NDD_PLUGIN_API void NDD_GetCurrentFilePath(char* szPath, int nSize);

#ifdef __cplusplus
}
#endif

#endif // NDDPACKAGE_H
