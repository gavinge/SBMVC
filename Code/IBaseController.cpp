#include "IBaseController.h"

BOOL IBaseController::BindModel(IBaseOject* pModel)
{
	VERIFY_POINTER(pModel,FALSE);
	m_pModel = pModel;
	return TRUE;
}