#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include "nddplugin.h"

#ifdef __cplusplus
extern "C" {
#endif

NDD_PLUGIN_API bool NDD_PROC_IDENTIFY(NDD_PROC_DATA* pData);

NDD_PLUGIN_API void NDD_PROC_MENU_CLICK(int nMenuID);

#ifdef __cplusplus
}
#endif

#endif // WORDCOUNT_H
