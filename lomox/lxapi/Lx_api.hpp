/*******************************************************************************
* ��Ȩ����(C) 1988-2012 All Rights Reserved.
*
* �ļ�����	: Lx_api.h
* ��    ��	: ղ���� (mailto:zch.fly@gmail.com)
* ��������	: 2012/12/21
* ��������	: 
* ��    ע	: 
********************************************************************************/
#ifndef LOMOX_API_H
#define LOMOX_API_H

#ifdef WIN32
#ifndef LOMOX_EXPORT
#ifdef	LOMOX_LIB
#define LOMOX_EXPORT __declspec(dllexport)
#else
#define LOMOX_EXPORT __declspec(dllimport)
#endif
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif
	LOMOX_EXPORT void LomoxAppRun(int argc, char *argv[]);
#ifdef __cplusplus
};
#endif // __cplusplus

#endif