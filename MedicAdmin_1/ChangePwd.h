#pragma once
#include "MedicAdmin_1Doc.h"
#include "MainFrm.h"


// ChangePwd �Ի���

class ChangePwd : public CDialogEx
{
	DECLARE_DYNAMIC(ChangePwd)

public:
	ChangePwd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ChangePwd();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_uiAccount;
	CString m_oriPwd;
	CString m_newPwd;
	CString m_uiSurePwd;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
};
