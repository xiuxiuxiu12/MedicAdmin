#pragma once
#include "MedicAdmin_1Doc.h"
#include "MainFrm.h"


// ChangePwd 对话框

class ChangePwd : public CDialogEx
{
	DECLARE_DYNAMIC(ChangePwd)

public:
	ChangePwd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ChangePwd();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
