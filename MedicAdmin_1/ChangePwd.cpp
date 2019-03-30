// ChangePwd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin_1.h"
#include "ChangePwd.h"
#include "afxdialogex.h"


// ChangePwd �Ի���

IMPLEMENT_DYNAMIC(ChangePwd, CDialogEx)

ChangePwd::ChangePwd(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChangePwd::IDD, pParent)
	, m_uiAccount(_T(""))
	, m_oriPwd(_T(""))
	, m_newPwd(_T(""))
	, m_uiSurePwd(_T(""))
{

}

ChangePwd::~ChangePwd()
{
}

void ChangePwd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Text(pDX, IDC_EDIT2, m_oriPwd);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_uiSurePwd);
}


BEGIN_MESSAGE_MAP(ChangePwd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &ChangePwd::OnBnClickedButton3)
END_MESSAGE_MAP()


// ChangePwd ��Ϣ�������


BOOL ChangePwd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)pFrame->GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(pUser->GetAccount());


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void ChangePwd::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)pFrame->GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	UpdateData(true);
	int ret = pUser->ChangePwd(m_oriPwd, m_newPwd, m_uiSurePwd);
	if (ret == -1){
		MessageBox(TEXT("��������������벻һ��"));
		return;
	}if (ret == -2){
		MessageBox(TEXT("ԭʼ���벻��ȷ"));
		return;
	}
	MessageBox(TEXT("�޸�����ɹ�"));
	CDialogEx::OnCancel();
}
