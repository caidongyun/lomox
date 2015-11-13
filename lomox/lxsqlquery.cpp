/*******************************************************************************
* 版权所有(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxsqlquery.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/14
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include <QtSql/qsql.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "lxsqlquery.h"

// 
// LxSqlQuery::LxSqlQuery( QObject* parent /*= 0*/, QSqlQuery sql )
// :QObject(parent)
// {
// 	m_pSqlquery = sql;
// }

LxSqlQuery::~LxSqlQuery()
{
	
}

bool LxSqlQuery::exec( const QString& query )
{
	return m_sqlquery.exec(query);
}

QVariant LxSqlQuery::value( int i )
{
	return m_sqlquery.value(i);
}

bool LxSqlQuery::next()
{
	return m_sqlquery.next();
}

bool LxSqlQuery::previous()
{
	return m_sqlquery.previous();
}

LxSqlQuery::LxSqlQuery()
{

}
