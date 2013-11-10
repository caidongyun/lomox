/*******************************************************************************
* 版权所有(C) 1988-2012  All Rights Reserved.
*
* 文件名称	: jsonhelper.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011-7-6
* 功能描述	: 包含QVariantMap 表示一条json 
			QVariantList 表示多条json

			KJsonHelper 拼接一个json串
			KJsArrayHelper 拼接一个数组
* 备    注	: 
********************************************************************************/
#ifndef __JSONHELPER_H__
#define __JSONHELPER_H__

class KJsonHelper
{
public:
	KJsonHelper(){};
	~KJsonHelper(){};

public:
	bool Add(QString strName, QVariant varValue);
	QVariant GetResultJsonVariant();//一个则返回一个var

private:
	QVariantMap m_varMap;
};

inline bool KJsonHelper::Add(QString strName, QVariant varValue)
{
	if (strName.isEmpty() || varValue.isNull() || !varValue.isValid())
		return false;
	m_varMap.insert(strName, varValue);
	return true;//暂时这样吧
}

inline QVariant KJsonHelper::GetResultJsonVariant()
{
	return m_varMap;
}

class KJsArrayHelper
{
public:
	KJsArrayHelper(){};
	~KJsArrayHelper(){};

public:
	bool Add(QVariant varValue);
	QVariant GetResultJsonVariant();//超过两个返回数组，一个则返回一个即使第一个varmap的 variant内部自己判断

private:
	QVariantList m_varList;
};

inline bool KJsArrayHelper::Add(QVariant varValue)
{
	if (varValue.isNull() || !varValue.isValid())
		return false;
	m_varList.append(varValue);
	return true;
}

inline QVariant KJsArrayHelper::GetResultJsonVariant()
{
	return QVariant(m_varList);
}

#endif // end of __JSONHELPER_H__
