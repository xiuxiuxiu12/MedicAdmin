#pragma once
#include "MedicAdmin_1Doc.h"
#include "LoginDlg.h"


// CUerTreeView ��ͼ

class CUerTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CUerTreeView)

protected:
	CUerTreeView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUerTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
private:
	CImageList m_imageList;
};


