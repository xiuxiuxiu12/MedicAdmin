
// MedicAdmin_1View.h : CMedicAdmin_1View ��Ľӿ�
//

#pragma once

#include "resource.h"


class CMedicAdmin_1View : public CFormView
{
protected: // �������л�����
	CMedicAdmin_1View();
	DECLARE_DYNCREATE(CMedicAdmin_1View)

public:
	enum{ IDD = IDD_MEDICADMIN_1_FORM };

// ����
public:
	CMedicAdmin_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMedicAdmin_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MedicAdmin_1View.cpp �еĵ��԰汾
inline CMedicAdmin_1Doc* CMedicAdmin_1View::GetDocument() const
   { return reinterpret_cast<CMedicAdmin_1Doc*>(m_pDocument); }
#endif

