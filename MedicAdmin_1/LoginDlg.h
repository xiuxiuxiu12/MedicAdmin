#pragma once
#include "MedicAdmin_1Doc.h"
#include "MainFrm.h"


// CLoginDlg �Ի���

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_uiAccount;
	CString m_uiPwd;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	virtual void OnOK();
	virtual void OnCancel();
};
