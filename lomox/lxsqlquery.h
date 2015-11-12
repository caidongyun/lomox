/*******************************************************************************
* 版权所有(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxsqlquery.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/14
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXSQLQUERY_H__
#define __LXSQLQUERY_H__

class QSqlQuery;

class LOMOX_EXPORT LxSqlQuery : public QObject
{
public:
LxSqlQuery();
/*	explicit LxSqlQuery(QObject* parent = 0, QSqlQuery& sql);*/
	virtual ~LxSqlQuery();
 
public slots:
	bool exec(const QString& query);
	QVariant value(int i);
    bool next();
    bool previous();

private:
	QSqlQuery m_sqlquery;
};
#endif // end of __LXSQLQUERY_H__
