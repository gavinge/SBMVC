/** 
* @file IBaseView.h
* @brief MVC基础接口定义:IBaseView
* @author Gavin geshan@hotmail.com
* @time： 2015-03-11 17:24
* @comment: MVC模型之View基础定义
* @version: V1.0
* @version: V1.1 增加Bind_Model_Controller 函数 2015.5.29
*/

#ifndef __MVC_IBaseView_H_
#define __MVC_IBaseView_H_

#include "BaseDef\IBaseDef.h"


class MVC_NO_VTABLE IBaseView : public IBaseOject
{
public:
	IBaseView():m_pController(NULL),m_pModel(NULL){};
	virtual ~IBaseView() {};
public:
	///@brief 更新自身View显示
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE UpdateView() PURE;

	///@brief 绑定View的Controller组件
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE BindController(IBaseOject* pController);

	///@brief 绑定View的Model组件
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE BindModel(IBaseOject* pModel);

	///@brief 绑定View的Model组件
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE Bind_Model_Controller(IBaseOject* pModel,IBaseOject* pController);
protected:
	///@brief MVC中的View中的Controller组件
	IBaseOject* m_pController;

	///@brief MVC中的View中的Model组件
	IBaseOject* m_pModel;
};

#endif