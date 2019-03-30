#pragma once
#include "MainFrm.h"
#include "MedicAdmin_1Doc.h"
#include "afxwin.h"
#include "UerTreeView.h"


// AddUserDlg 对话框

class AddUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddUserDlg)

public:
	AddUserDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddUserDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
