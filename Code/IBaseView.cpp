#include "IBaseView.h"

BOOL IBaseView::BindController(IBaseOject* pController)
{
	m_pController = pController;
	return TRUE;
}

BOOL IBaseView::BindModel(IBaseOject* pModel)
{
	m_pModel = pModel;
	return TRUE;
}

BOOL IBaseView::Bind_Model_Controller(IBaseOject* pModel,IBaseOject* pController)
{
	m_pModel      = pModel;
	m_pController = pController;
	return TRUE;
}