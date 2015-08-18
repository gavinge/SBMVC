/** 
* @file IBaseUI.h
* @brief 基础接口定义:IBaseUI，UI基本操作接口
* @author Gavin geshan@hotmail.com
* @time： 2015-03-13 15:55
* @comment: 
* @version: V1.0
*/
#ifndef __IBaseUI__H_
#define __IBaseUI__H_
#include "IBaseDef.h"

typedef struct tagDRAWSTRUCT {
	int x;         //距离父窗口左边
	int y;         //距离父窗口上边
	int width;     //宽度 
	int height;    //高度
}DRAWSTRUCT,*LPDRAWSTRUCT;

//以下宏定义为了在继承实现时方便,选择使用.
//-----------------------------------------------------------------------------------------------------------------------------//
//如果继承之后不用实现全部想要的接口，直接用这个宏处理吧
#ifndef IBaseUI_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent,DRAWSTRUCT& _drawRegion){return NULL;}\
virtual HWND STDMETHODCALLTYPE GetHWnd(){return NULL;}\
virtual BOOL STDMETHODCALLTYPE UpdateLayOut(DRAWSTRUCT & _drawRegion){return FALSE;}\
virtual DRAWSTRUCT STDMETHODCALLTYPE GetRegion(){DRAWSTRUCT info = {};return info;}
#endif

//如果继承之后不想实现Create接口，直接用这个宏处理吧
#ifndef IBaseUI_Create_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_Create_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent){return NULL;}
#endif

//如果继承之后不想实现Create接口，直接用这个宏处理吧
#ifndef IBaseUI_Create2_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_Create2_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent,DRAWSTRUCT& _drawRegion){return NULL;}
#endif

//如果继承之后不想实现GetHWnd接口，直接用这个宏处理吧
#ifndef IBaseUI_GetHWnd_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_GetHWnd_NO_IMPlEMENT_VIRTURE_FUNCTION virtual HWND STDMETHODCALLTYPE GetHWnd(){return NULL;}
#endif

//如果继承之后不想实现UpdateLayOut接口，直接用这个宏处理吧
#ifndef IBaseUI_UpdateLayOut_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_UpdateLayOut_NO_IMPlEMENT_VIRTURE_FUNCTION virtual BOOL STDMETHODCALLTYPE UpdateLayOut(DRAWSTRUCT & _drawRegion){return FALSE;}
#endif

//如果继承之后不想实现GetRegion接口，直接用这个宏处理吧
#ifndef IBaseUI_GetRegion_NO_IMPlEMENT_VIRTURE_FUNCTION
#define IBaseUI_GetRegion_NO_IMPlEMENT_VIRTURE_FUNCTION virtual DRAWSTRUCT STDMETHODCALLTYPE GetRegion(){DRAWSTRUCT info = {};return info;}
#endif
//-----------------------------------------------------------------------------------------------------------------------------//

///IBaseUI接口为UI最基本的操作定义接口.
class MVC_NO_VTABLE IBaseUI 
{
public:
	IBaseUI(){};
	virtual ~IBaseUI(){};
public:

	///@brief 创建接口
	///@param IBaseObject* 父容器指针(可能是IBaseUIFrame或者IBaseUIView).
	///@return 成功返回TRUE，失败返回FALSE 
	virtual HWND STDMETHODCALLTYPE CreateUI(IBaseUI* pParent,DRAWSTRUCT& _drawRegion) PURE;

	///@brief 获取句柄的接口
	///@param 无 
	///@return 成功返回View句柄，失败返回NULL
	virtual HWND STDMETHODCALLTYPE GetHWnd() PURE;

	///@brief 更新布局的接口
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE UpdateLayOut(DRAWSTRUCT & _drawRegion) PURE;

	///@brief 获取当前容器的显示参数
	///@param 无 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual DRAWSTRUCT STDMETHODCALLTYPE GetRegion() PURE;

public:
	///@brief 加UI子容器(子容器可能是IBaseUIFrame或者IBaseUIView)
	///@param IBaseOject* 指针. 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE AddChild(IBaseUI* pChildObj);

	///@brief 删除UI子容器(子容器可能是IBaseUIFrame或者IBaseUIView)
	///@param IBaseOject* 指针. 
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE ReMoveChild(IBaseUI* pChildObj);

	///@brief 更新所有子容器(子容器可能是IBaseUIFrame或者IBaseUIView)
	///@param 无.
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE UpdateLayOutChildren();


	///@brief 删除当前所有的子容器
	///@param 无.
	///@return 成功返回TRUE，失败返回FALSE 
	virtual BOOL STDMETHODCALLTYPE DeleteAllChildren();
protected:
	///@brief 子容器列表
	MvcUIList m_ChildList;
    
	///@brief 当前UI容器显示的位置
	DRAWSTRUCT m_DrawInfo;
};

#endif