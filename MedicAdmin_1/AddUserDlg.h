#pragma once
#include "MainFrm.h"
#include "MedicAdmin_1Doc.h"
#include "afxwin.h"
#include "UerTreeView.h"


// AddUserDlg �Ի���

class AddUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddUserDlg)

public:
	AddUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddUserDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_uiAccount;
	CString m_uiPwd;
	CString m_uiName;
//	CString m_uiClass;
public:
	afx_msg void OnBnClickedButton3();
private:
	CString m_uiclass;
public:
	virtual BOOL OnInitDialog();
private:
	CComboBox m_uiClass;
public:
	afx_msg void OnBnClickedButton4();
};
