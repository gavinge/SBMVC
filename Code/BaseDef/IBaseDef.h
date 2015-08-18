/** 
* @file IBaseDef.h
* @brief MVC基础接口定义:IBaseDef
* @author Gavin geshan@hotmail.com
* @time： 2015-03-11 17:24
* @comment: 定义包含MVC相关组件的所有公共及定义.
* @version: V1.0
*/
#ifndef __MVC_IBaseDef_H_
#define __MVC_IBaseDef_H_

#include "windows.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <assert.h>
using namespace std; 

#define  MVC_NO_VTABLE __declspec(novtable)

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#endif

#ifndef VERIFY_POINTER
#define VERIFY_POINTER(pt, hr)  {if (!pt) {assert(!"the  pointer is null!!");return hr;}}
#endif

#ifndef VERIFY_POINTER_NORET
#define VERIFY_POINTER_NORET(pt)  {if (!pt) {assert(!"the  pointer is null!!");return ;}}
#endif

#ifndef DYNAMIC_CAST
#define DYNAMIC_CAST(ClassPtr, ptr)  dynamic_cast<ClassPtr>((ClassPtr)(ptr))
#endif

__interface IBaseOject
{
};

typedef std::list<IBaseOject*>  MvcList; 
typedef std::list<IBaseOject*>::iterator  iterMvcValue; 

class IBaseUI;
typedef std::list<IBaseUI*>  MvcUIList; 
typedef std::list<IBaseUI*>::iterator  iterMvcUIValue; 

#endif