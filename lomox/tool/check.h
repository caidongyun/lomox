
/*
MARK:2011-6-13 蔡东赟 迁移改造 
*/
// -------------------------------------------------------------------------- //

#pragma once


//check error
#include <assert.h>
#ifndef ASSERT
#define ASSERT(e) assert(e)
#endif

// -------------------------------------------------------------------------- //

// 定义统一出口名称
#define LX_EXIT					LX_EXIT_HERE

// -------------------------------------------------------------------------- //
// LX_CHECK
// -------------------------------------------------------------------------- //

// 当条件为假时跳转：
#define LX_CHECK_BOOLEX(result, expr)										\
	if (!(result))															\
	{																		\
		expr;																\
		goto LX_EXIT;														\
	}

#define LX_CHECK_BOOL(result)		LX_CHECK_BOOLEX(result, 0)
#define LX_CHECK(hr)				LX_CHECK_BOOL(SUCCEEDED(hr))


#define LX_CHECK_BOOLEX1(result, expr)											\
	if (!(result))															\
	{																		\
		expr;																\
		goto LX_EXIT;														\
	}

#define LX_CHECK_BOOL1(result)			LX_CHECK_BOOLEX1(result, 0)
#define LX_CHECK1(hr)					LX_CHECK_BOOL1(SUCCEEDED(hr))

#define RETURN						return

// -------------------------------------------------------------------------- //
// [obsolete]
// LX_CHECK宏使用在菜单状态查询不合适，如果没有成功得到一个合法的返回值
#define LX_VALID_HR(hr)	{if(FAILED(hr))	return hr;}		

// 检查输入指针，如果为空返回 E_INVALIDARG
#define LX_VERIFY_IN_POINTER(p)			if (p == NULL) { /*ASSERT(false);*/ return false; }
#define LX_VERIFY_IN_2_POINTERS(p1, p2)	if (p1 == NULL || p2 == NULL) {/* ASSERT(false);*/ return false; }
#define LX_VERIFY_IN_3_POINTERS(p1, p2, p3)	if (p1 == NULL || p2 == NULL || p3 == NULL) { /*ASSERT(false); */return false; }
#define LX_VERIFY_IN_4_POINTERS(p1, p2, p3, p4)	if (p1 == NULL || p2 == NULL || p3 == NULL || p4 == NULL) { /*ASSERT(false);*/ return false; }


#define VERIFY_IN_POINTER(p)			if (p == NULL) { Q_ASSERT(false);return ; }
#define VERIFY_IN_2_POINTERS(p1, p2)	if (p1 == NULL || p2 == NULL) {Q_ASSERT(false); return ; }
#define VERIFY_IN_3_POINTERS(p1, p2, p3)	if (p1 == NULL || p2 == NULL || p3 == NULL) { Q_ASSERT(false);return ; }
#define VERIFY_IN_4_POINTERS(p1, p2, p3, p4)	if (p1 == NULL || p2 == NULL || p3 == NULL || p4 == NULL) { Q_ASSERT(false); return ; }

#define G_OK QVariant(true)
#define G_FAILE QVariant(false)
#define HrToVarResult(x) (SUCCEEDED(x) ? G_OK : G_FAILE)
