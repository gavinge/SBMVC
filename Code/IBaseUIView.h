/** 
* @file IBaseUIView.h
* @brief �����ӿڶ���:IBaseUIView��ֱ�Ӻ�IBaseUIFrame���ʹ��
* @author Gavin geshan@hotmail.com
* @time�� 2015-03-12 11:24
* @comment: 
* @version: V1.0
*/
#ifndef __IBaseUIView_H_
#define __IBaseUIView_H_

#include "BaseDef\IBaseUI.h"
#include "IBaseView.h"

class MVC_NO_VTABLE IBaseUIView:public IBaseView,public IBaseUI
{
public:
	IBaseUIView(){};
	virtual ~IBaseUIView(){};
};

#endif