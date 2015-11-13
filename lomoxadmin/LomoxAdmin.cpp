// lomoxwin32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "LomoxAdmin.h"
#include <WinNls.h>
#include "../lomox/lxapi/Lx_api.hpp"


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
					 int       nCmdShow)
{
	LomoxAppRun(0, 0);
	return 0;
}

