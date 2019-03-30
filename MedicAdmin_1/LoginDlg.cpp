// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin_1.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������

//ȡ��
void CLoginDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	exit(1);
}

//��¼
void CLoginDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);

	//����ı������
	CMainFrame *pFram = (CMainFrame *)AfxGetMainWnd();
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)pFram->GetActiveDocument();

	//����ı�������еĵ�¼�û�����
	CuserSet *pUserSet = pDoc->GetUserSet();

	//����û�ָ��
	CUser *pUser = pDoc->GetUser();
	pUser->SetAccount(m_uiAccount);
	pUser->SetPwd(m_uiPwd);
	pUser->SetUserSet(pUserSet);
	
	if (pUser->Login() == 0){
		CDialogEx::OnCancel();
	}
	else
	{
		AfxMessageBox(TEXT("�˻������벻��ȷ"));
		return;
	}

	
	

}


void CLoginDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CLoginDlg::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���
	exit(1);

	//CDialogEx::OnCancel();
}
