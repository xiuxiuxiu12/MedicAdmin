#pragma once
#include "MedicAdmin_1Doc.h"


// CMedicListView ��ͼ

class CMedicListView : public CListView
{
	DECLARE_DYNCREATE(CMedicListView)

protected:
	CMedicListView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMedicListView();

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
};


