#pragma once

#ifdef X_WINDOWS
	#ifdef X_BUILD_DLL
     #define X_API __declspec(dllexport)
	#else
	 #define X_API __declspec(dllimport)
	#endif
#else
	#error Only support Windows
#endif