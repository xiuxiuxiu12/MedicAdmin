
// MedicAdmin_1.h : MedicAdmin_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMedicAdmin_1App:
// �йش����ʵ�֣������ MedicAdmin_1.cpp
//

class CMedicAdmin_1App : public CWinApp
{
public:
	CMedicAdmin_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMedicAdmin_1App theApp;
