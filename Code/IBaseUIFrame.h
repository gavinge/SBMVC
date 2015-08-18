/** 
* @file IBaseUIFrame.h
* @brief �����ӿڶ���:IBaseUIFrame,Ϊ���崰�ڵ�����������.
* @author Gavin geshan@hotmail.com
* @time�� 2015-03-12 18:33
* @comment: 
* @version: V1.0
*/
#ifndef __IBaseUIFrame_H_
#define __IBaseUIFrame_H_

#include "BaseDef\IBaseDef.h"
#include "BaseDef\IBaseUI.h"

class MVC_NO_VTABLE IBaseUIFrame : 
	public IBaseOject,
	public IBaseUI
{
public:
	IBaseUIFrame(){};
	virtual ~IBaseUIFrame(){};
};

#endif