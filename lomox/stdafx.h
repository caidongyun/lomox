#pragma once

//fixed QT qdatetime min error by Colin3dmax
/* Include this file instead of including <windows.h> directly. */
#ifdef NOMINMAX
#include <windows.h>
#else
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
#endif


#include <winuser.h>

#include <vector>
#include <string>
using namespace std;

#include <algorithm>





