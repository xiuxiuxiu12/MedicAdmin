// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin_1.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_uiAccount(_T(""))
	, m_uiPwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Text(pDX, IDC_EDIT2, m_uiPwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

//取消
void CLoginDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	exit(1);
}

//登录
void CLoginDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);

	//获得文本类对象
	CMainFrame *pFram = (CMainFrame *)AfxGetMainWnd();
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)pFram->GetActiveDocument();

	//获得文本类对象中的登录用户对象
	CuserSet *pUserSet = pDoc->GetUserSet();

	//获得用户指针
	CUser *pUser = pDoc->GetUser();
	pUser->SetAccount(m_uiAccount);
	pUser->SetPwd(m_uiPwd);
	pUser->SetUserSet(pUserSet);
	
	if (pUser->Login() == 0){
		CDialogEx::OnCancel();
	}
	else
	{
		AfxMessageBox(TEXT("账户和密码不正确"));
		return;
	}

	
	

}


void CLoginDlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLoginDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类
	exit(1);

	//CDialogEx::OnCancel();
}
