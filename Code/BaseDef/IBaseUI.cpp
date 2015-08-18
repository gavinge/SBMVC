#include "IBaseUI.h"


BOOL IBaseUI::AddChild(IBaseUI* pChildObj)
{
	VERIFY_POINTER(pChildObj,FALSE);

	iterMvcUIValue itor = find(m_ChildList.begin(), m_ChildList.end(), pChildObj);
	if (itor != m_ChildList.end())
	{
		return FALSE;
	}

	m_ChildList.push_back(pChildObj);
	return TRUE;
}

BOOL IBaseUI::ReMoveChild(IBaseUI* pChildObj)
{
	BOOL bRet = FALSE;
	iterMvcUIValue itor = find(m_ChildList.begin(), m_ChildList.end(), pChildObj);

	if (itor != m_ChildList.end())
	{
		m_ChildList.remove(pChildObj);
		bRet = TRUE;
	}
	return bRet;
}

BOOL IBaseUI::UpdateLayOutChildren()
{
	iterMvcUIValue itor = m_ChildList.begin();
	for (; itor != m_ChildList.end(); itor++)
	{
		IBaseUI* p = DYNAMIC_CAST(IBaseUI*,*itor);
		if (p)
		{
			p->UpdateLayOut(p->GetRegion());
		}
	}
	return TRUE;
}

BOOL IBaseUI::DeleteAllChildren()
{
	MvcUIList::const_reverse_iterator itor = m_ChildList.rbegin();
	for (; itor != m_ChildList.rend(); itor ++)
	{
		IBaseUI* p = DYNAMIC_CAST(IBaseUI*,*itor);
		SAFE_DELETE(p);
	}
	m_ChildList.clear();
	return TRUE;
}
