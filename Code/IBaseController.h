/** 
* @file IBaseController.h
* @brief MVC�����ӿڶ���:IBaseController
* @author Gavin geshan@hotmail.com   
* @time�� 2015-03-11 17:24
* @comment: MVCģ��֮Controller��������
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
	///@brief ��View��Model���
	///@param �� 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE BindModel(IBaseOject* pModel);
protected:
	///@brief MVC�е�Controll�е�Model���
	IBaseOject* m_pModel;
};

#endif