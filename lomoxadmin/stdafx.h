// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once


#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// Preprocessor definitions
#ifndef STRICT
#define STRICT
#endif


// Change these values to use different versions
#define WINVER			0x0500
#define _WIN32_WINNT	0x0501  // Require Windows 2000 "500" or later 501xp
#define _WIN32_IE		0x0501  // Require IE 5.01 or later (comes with Windows 2000 or later)
#define _RICHEDIT_VER	0x0100

// ATL related preprocessor definitions
#if (_ATL_VER >= 0x0700)
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit
#define _ATL_USE_CSTRING_FLOAT
#define _ATL_USE_DDX_FLOAT
#define _ATL_NO_OLD_NAMES
#define _ATL_DISABLE_DEPRECATED
#define _ATL_ALL_WARNINGS
#define _ATL_NO_OLD_HEADERS_WIN64
#endif

// Includes
#include <atlbase.h>
#if (_ATL_VER >= 0x0700)
#include <atlstr.h>
#include <atltypes.h>
#endif

// WTL related preprocessor definitions
#if (_ATL_VER >= 0x0700)
#define _WTL_NO_WTYPES
#define _WTL_NO_UNION_CLASSES
#define _WTL_NO_CSTRING
#endif

#include <wtypes.h>

#include <atlapp.h>


// TODO: reference additional headers your program requires here
