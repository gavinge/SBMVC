/** 
* @file IBaseController.h
* @brief MVC基础接口定义:IBaseController
* @author Gavin geshan@hotmail.com   
* @time： 2015-03-11 17:24
* @comment: MVC模型之Controller基础定义
* @version: V1.0
*/
#ifndef __MVC_IBaseController_H_
#define __MVC_IBaseController_H_

#include "BaseDef\IBaseDef.h"

class MVC_NO_VTABLE IBaseController : public IBaseOject
{
public:
	IBaseController():m_pModel(NULL){};
	virtual ~IBaseController() {};
	
public:
	///@brief 绑定View的Model组件
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE BindModel(IBaseOject* pModel);
protected:
	///@brief MVC中的Controll中的Model组件
	IBaseOject* m_pModel;
};

#endif