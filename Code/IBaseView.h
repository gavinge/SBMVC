/** 
* @file IBaseView.h
* @brief MVC�����ӿڶ���:IBaseView
* @author Gavin geshan@hotmail.com
* @time�� 2015-03-11 17:24
* @comment: MVCģ��֮View��������
* @version: V1.0
* @version: V1.1 ����Bind_Model_Controller ���� 2015.5.29
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
	///@brief ��������View��ʾ
	///@param �� 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE UpdateView() PURE;

	///@brief ��View��Controller���
	///@param �� 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE BindController(IBaseOject* pController);

	///@brief ��View��Model���
	///@param �� 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE BindModel(IBaseOject* pModel);

	///@brief ��View��Model���
	///@param �� 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE Bind_Model_Controller(IBaseOject* pModel,IBaseOject* pController);
protected:
	///@brief MVC�е�View�е�Controller���
	IBaseOject* m_pController;

	///@brief MVC�е�View�е�Model���
	IBaseOject* m_pModel;
};

#endif