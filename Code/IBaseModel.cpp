#include "IBaseModel.h"
#include "IBaseView.h"
BOOL IBaseModel::AddView(IBaseOject* pView)
{
	VERIFY_POINTER(pView,FALSE);

	iterMvcValue itor = find(m_ViewList.begin(), m_ViewList.end(), pView);

	if (itor != m_ViewList.end())
	{
		return FALSE;
	}
	m_ViewList.push_back(pView);
	return TRUE;
}
BOOL IBaseModel::ReMoveView(IBaseOject* pView)
{
	BOOL bRet = FALSE;
	iterMvcValue itor = find(m_ViewList.begin(), m_ViewList.end(), pView);
	
	if (itor != m_ViewList.end())
	{
		m_ViewList.remove(pView);
		bRet = TRUE;
	}
	return bRet;
}

BOOL IBaseModel::NotifyView()
{
	iterMvcValue itor = m_ViewList.begin();
	for (; itor != m_ViewList.end(); itor++)
	{
		IBaseView* p = DYNAMIC_CAST(IBaseView*,*itor);
		if (p)
		{
			p->UpdateView();
		}
	}
	return TRUE;
}