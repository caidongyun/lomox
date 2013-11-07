/*******************************************************************************
* ��Ȩ����(C) 2010-2012 LomoX. All Rights Reserved.
*
* �ļ�����	: lxHttp.h
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2012/10/19
* ��������	: 
* ��    ע	: 
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
* ��������	: httpRequest
* ��������	: 
* �Ρ�����	: QVariant varMethod
						'post' or 'get'
* �Ρ�����	: QVariant varUrl
* �Ρ�����	: QVariant varPostData  
							for post method
* �� �� ֵ	: QVariant 
* ������ע	: �̶��S[2012-12-19]
*******************************************************************************/
	QVariant  httpRequest(QVariant varMethod,  QVariant varUrl,  QVariant varPostData); //

/*******************************************************************************
* ��������	: httpRequestWithEncode
* ��������	: 
* �Ρ�����	: QVariant varMethod  'post' or 'get'
* �Ρ�����	: QVariant varUrl		url
* �Ρ�����	: QVariant varPostData  
							if is post method,Then usr this.
							if no, use ''

* �Ρ�����	: QVariant varEncode
						 if is not utf-8 use this param
						 eg�� 'unicode'
* �� �� ֵ	: QVariant  
							return the requestdata  else 0 is failed

* ������ע	: �̶��S[2012-12-19]
*******************************************************************************/
	QVariant  httpRequestWithEncode(QVariant varMethod,  QVariant varUrl ,  QVariant varPostData, QVariant varEncode);
};

#endif // end of __LXHTTP_H__
