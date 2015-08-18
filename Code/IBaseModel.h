/** 
* @file IBaseModel.h
* @brief MVC�����ӿڶ���:IBaseModel
* @author Gavin geshan@hotmail.com  
* @time�� 2015-03-12 10:10
* @comment: MVCģ��֮Model��������
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
	///@brief ���View��Model��
	///@param IBaseOject* ָ��. 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE AddView(IBaseOject* pView);

	///@brief ɾ��View��Model��
	///@param IBaseOject* ָ��. 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE ReMoveView(IBaseOject* pView);

	///@brief ��Model���б仯ʱ,֪ͨm_ViewList�е�����View������ʾ
	///@param ��.
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE NotifyView();

protected:
	///@brief MVC�е�Model�е�ά����View���б�
	MvcList m_ViewList;
};

#endif