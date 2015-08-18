/** 
* @file IBaseUI.h
* @brief �����ӿڶ���:IBaseUI��UI���������ӿ�
* @author Gavin geshan@hotmail.com
* @time�� 2015-03-13 15:55
* @comment: 
* @version: V1.0
*/
#ifndef __IBaseUI__H_
#define __IBaseUI__H_
#include "IBaseDef.h"

typedef struct tagDRAWSTRUCT {
	int x;         //���븸�������
	int y;         //���븸�����ϱ�
	int width;     //��� 
	int height;    //�߶�
}DRAWSTRUCT,*LPDRAWSTRUCT;

//���º궨��Ϊ���ڼ̳�ʵ��ʱ����,ѡ��ʹ��.
//-----------------------------------------------------------------------------------------------------------------------------//
//����̳�֮����ʵ��ȫ����Ҫ�Ľӿڣ�ֱ��������괦���
#ifndef IBaseUI_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent,DRAWSTRUCT& _drawRegion){return NULL;}\
virtual HWND STDMETHODCALLTYPE GetHWnd(){return NULL;}\
virtual BOOL STDMETHODCALLTYPE UpdateLayOut(DRAWSTRUCT & _drawRegion){return FALSE;}\
virtual DRAWSTRUCT STDMETHODCALLTYPE GetRegion(){DRAWSTRUCT info = {};return info;}
#endif

//����̳�֮����ʵ��Create�ӿڣ�ֱ��������괦���
#ifndef IBaseUI_Create_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_Create_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent){return NULL;}
#endif

//����̳�֮����ʵ��Create�ӿڣ�ֱ��������괦���
#ifndef IBaseUI_Create2_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_Create2_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent,DRAWSTRUCT& _drawRegion){return NULL;}
#endif

//����̳�֮����ʵ��GetHWnd�ӿڣ�ֱ��������괦���
#ifndef IBaseUI_GetHWnd_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_GetHWnd_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE GetHWnd(){return NULL;}
#endif

//����̳�֮����ʵ��UpdateLayOut�ӿڣ�ֱ��������괦���
#ifndef IBaseUI_UpdateLayOut_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_UpdateLayOut_NO_IMPlEMENT_VIRTURE_FUNCTION virtual BOOL STDMETHODCALLTYPE UpdateLayOut(DRAWSTRUCT & _drawRegion){return FALSE;}
#endif

//����̳�֮����ʵ��GetRegion�ӿڣ�ֱ��������괦���
#ifndef IBaseUI_GetRegion_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_GetRegion_NO_IMPlEMENT_VIRTURE_FUNCTION virtual DRAWSTRUCT STDMETHODCALLTYPE GetRegion(){DRAWSTRUCT info = {};return info;}
#endif
//-----------------------------------------------------------------------------------------------------------------------------//

///IBaseUI�ӿ�ΪUI������Ĳ�������ӿ�.
class MVC_NO_VTABLE IBaseUI 
{
public:
	IBaseUI(){};
	virtual ~IBaseUI(){};
public:

	///@brief �����ӿ�
	///@param IBaseObject* ������ָ��(������IBaseUIFrame����IBaseUIView).
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent,DRAWSTRUCT& _drawRegion) PURE;

	///@brief ��ȡ����Ľӿ�
	///@param �� 
	///@return �ɹ�����View�����ʧ�ܷ���NULL
	virtual HWND STDMETHODCALLTYPE GetHWnd() PURE;

	///@brief ���²��ֵĽӿ�
	///@param �� 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE UpdateLayOut(DRAWSTRUCT & _drawRegion) PURE;

	///@brief ��ȡ��ǰ��������ʾ����
	///@param �� 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual DRAWSTRUCT STDMETHODCALLTYPE GetRegion() PURE;

public:
	///@brief ��UI������(������������IBaseUIFrame����IBaseUIView)
	///@param IBaseOject* ָ��. 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE AddChild(IBaseUI* pChildObj);

	///@brief ɾ��UI������(������������IBaseUIFrame����IBaseUIView)
	///@param IBaseOject* ָ��. 
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE ReMoveChild(IBaseUI* pChildObj);

	///@brief ��������������(������������IBaseUIFrame����IBaseUIView)
	///@param ��.
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE UpdateLayOutChildren();


	///@brief ɾ����ǰ���е�������
	///@param ��.
	///@return �ɹ�����TRUE��ʧ�ܷ���FALSE 
	virtual BOOL STDMETHODCALLTYPE DeleteAllChildren();
protected:
	///@brief �������б�
	MvcUIList m_ChildList;
    
	///@brief ��ǰUI������ʾ��λ��
	DRAWSTRUCT m_DrawInfo;
};

#endif