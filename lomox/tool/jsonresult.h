/*******************************************************************************
* 版权所有(C) 1988-2012  All Rights Reserved.
*
* 文件名称	: jsonresult.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011-7-11
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __JSONRESULT_H__
#define __JSONRESULT_H__

#include "jsonhelper.h"
#include "include/errordefine.h"


class KJsonResult
{
public:
	KJsonResult(){};
	~KJsonResult(){};

public:
	static QVariant CreateJsonResultByNRESULT(NRESULT nr)
	{
		if (ISNOK(nr))
		{
			//true
			return CreateJsonResult(true, QString::fromWCharArray(MSGSTRLIST[nr]));
		}
		else
		{
			return CreateJsonResult(false, QString::fromWCharArray(MSGSTRLIST[nr]));
		}
	}

	static QVariant CreateJsonResult(bool bResult, QString strMsg)
	{
		KJsonHelper Json;
		Json.Add(QString("result"), QVariant(bResult));
		Json.Add(QString("msg"), QVariant(strMsg));
		return Json.GetResultJsonVariant();
	}

	static QVariant CreateJsonResultByBOOL(bool bOk)
	{
		if (bOk)
		{
			return CreateJsonResult(true, QString(""));
		}
		else
		{
			return CreateJsonResult(false, QString(""));
		}
	}
};

#define JSonResult(x)  KJsonResult::CreateJsonResultByNRESULT(x);
#define JSonBoolResult(x) KJsonResult::CreateJsonResultByBOOL(x);

/*
{Result:bool;  Msg: string ;  Type : int;  Data:[{}{}{}{}]};
*/

class KJsonPro
{
public:
	KJsonPro(){};
	~KJsonPro(){};
public:
	static QVariant CreateJsonProResult(bool result, QString msg,  QVariant data, int type = 0)
	{
		KJsonHelper Json;
		Json.Add(QString("result"), QVariant(result));
		Json.Add(QString("msg"), QVariant(msg));
		Json.Add(QString("type"), QVariant(type));
		Json.Add(QString("data"), QVariant(data));
		return Json.GetResultJsonVariant();
	}
};

#define JsonProResult(x,y,z,m) KJsonPro::CreateJsonProResult(x,y,z,m)
#define JsonProResultData(x)  JsonProResult(true, QString(""),x,0)
#define JsonProResultBool(x)  JsonProResult(x, QString(""), QVariant(),0)
#define JsonProResultBoolMsg(x,y)  JsonProResult(x, y, QVariant(),0)
#define JsonProResultBoolData(x,y) JsonProResult(x, QString(""), y, 0)

#define Ret_Param_Failed JsonProResultBoolMsg(false, QString::fromWCharArray(MSGSTRLIST[MSG_PARAMS_ERROR]))

#define Check_Ret_Msg(x) if (!x)\
	return Ret_Param_Failed;

#define  Check_JPro_Ret(X) if (false == X)	\
	return JsonProResultBool(false);

#endif // end of __JSONRESULT_H__
