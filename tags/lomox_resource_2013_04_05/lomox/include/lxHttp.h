/*******************************************************************************
* 版权所有(C) 2010-2012 LomoX. All Rights Reserved.
*
* 文件名称	: lxHttp.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/10/19
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXHTTP_H__
#define __LXHTTP_H__

#include <QHttp>
#include <QtNetwork/QHttp>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptContext>
#include <QtScript/QScriptEngine>


class LxHttp : public QObject
{
	Q_OBJECT
public:
	LxHttp(QObject* parent);
	virtual ~LxHttp();

public slots:
	
/*******************************************************************************
* 函数名称	: httpRequest
* 功能描述	: 
* 参　　数	: QVariant varMethod
						'post' or 'get'
* 参　　数	: QVariant varUrl
* 参　　数	: QVariant varPostData  
							for post method
* 返 回 值	: QVariant 
* 备　　注	: 蔡东赟[2012-12-19]
*******************************************************************************/
	QVariant  httpRequest(QVariant varMethod,  QVariant varUrl,  QVariant varPostData); //

/*******************************************************************************
* 函数名称	: httpRequestWithEncode
* 功能描述	: 
* 参　　数	: QVariant varMethod  'post' or 'get'
* 参　　数	: QVariant varUrl		url
* 参　　数	: QVariant varPostData  
							if is post method,Then usr this.
							if no, use ''

* 参　　数	: QVariant varEncode
						 if is not utf-8 use this param
						 eg： 'unicode'
* 返 回 值	: QVariant  
							return the requestdata  else 0 is failed

* 备　　注	: 蔡东赟[2012-12-19]
*******************************************************************************/
	QVariant  httpRequestWithEncode(QVariant varMethod,  QVariant varUrl ,  QVariant varPostData, QVariant varEncode);
};

#endif // end of __LXHTTP_H__
