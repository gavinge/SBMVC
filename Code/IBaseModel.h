/** 
* @file IBaseModel.h
* @brief MVC基础接口定义:IBaseModel
* @author Gavin geshan@hotmail.com  
* @time： 2015-03-12 10:10
* @comment: MVC模型之Model基础定义
* @version: V1.0
*/

#ifndef __MVC_IBaseModel_H_
#define __MVC_IBaseModel_H_

#include "BaseDef\IBaseDef.h"
class MVC_NO_VTABLE IBaseModel : public IBaseOject
{
public:
	virtual ~IBaseModel() {};
public:
	///@brief 添加View到Model中
	///@param IBaseOject* 指针. 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE AddView(IBaseOject* pView);

	///@brief 删除View到Model中
	///@param IBaseOject* 指针. 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE ReMoveView(IBaseOject* pView);

	///@brief 当Model中有变化时,通知m_ViewList中的所有View更新显示
	///@param 无.
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE NotifyView();

protected:
	///@brief MVC中的Model中的维护的View的列表
	MvcList m_ViewList;
};

#endif