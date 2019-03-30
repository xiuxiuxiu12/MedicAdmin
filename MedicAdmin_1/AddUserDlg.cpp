// AddUserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicAdmin_1.h"
#include "AddUserDlg.h"
#include "afxdialogex.h"


// AddUserDlg �Ի���

IMPLEMENT_DYNAMIC(AddUserDlg, CDialogEx)

AddUserDlg::AddUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddUserDlg::IDD, pParent)
	, m_uiAccount(_T(""))
	, m_uiPwd(_T(""))
	, m_uiName(_T(""))
	, m_uiclass(_T(""))
{

}

AddUserDlg::~AddUserDlg()
{
}

void AddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiAccount);
	DDX_Text(pDX, IDC_EDIT3, m_uiPwd);
	DDX_Text(pDX, IDC_EDIT2, m_uiName);
	//  DDX_Text(pDX, IDC_EDIT4, m_uiClass);
	DDX_CBString(pDX, IDC_COMBO1, m_uiclass);
	DDX_Control(pDX, IDC_COMBO1, m_uiClass);
}


BEGIN_MESSAGE_MAP(AddUserDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &AddUserDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &AddUserDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// AddUserDlg ��Ϣ�������

//ȷ����ť�Ļص�����
void AddUserDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)pFrame->GetActiveDocument();
	//��ȡ�ĵ����е�user����
	CUser *pUser = pDoc->GetUser();
	UpdateData(true);
	int ret = pUser->AddUser(m_uiAccount, m_uiPwd, m_uiName, m_uiclass);
	if (ret == -1){
		MessageBox(TEXT("���ݿ����Ӵ���"));
		return;
	}

	POSITION pos = pDoc->GetFirstViewPosition();
	CUerTreeView *treeView = NULL;
	while (pos != NULL){
		CView *view = pDoc->GetNextView(pos);
		if (view->IsKindOf(RUNTIME_CLASS(CUerTreeView))){
			treeView = (CUerTreeView *)view;
			break;
		}
	}

	if (treeView == NULL){
		return;
	}
	

	//��ȡ��ͼ���������ؼ�
	CTreeCtrl &treeCtrl = treeView->GetTreeCtrl();
	treeCtrl.DeleteAllItems();

	CuserSet *pUserSet = pDoc->GetUserSet();
	pUserSet->m_strFilter = TEXT("");
	pUserSet->Requery();

	CString type[3] = { TEXT("����Ա"), TEXT("ҽ��"), TEXT("��ҩԱ") };

	HTREEITEM cur = NULL;
	for (int i = 0; i < 3; i++){
		//�����ڵ�
		HTREEITEM Root = treeCtrl.InsertItem(type[i], 0, 0, NULL);
		//��������Ա���ӽڵ�
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type[i]);
		pUserSet->m_strFilter = sql;
		pUserSet->Requery();

		while (pUserSet->IsEOF() == false){
			CString str;
			if (pUserSet->m_account == pUser->GetAccount()){
				str.Format(TEXT("%s(%s)[��¼�û�]"), pUserSet->m_name, pUserSet->m_account);
				cur = treeCtrl.InsertItem(str, 1, 1, Root);
			}
			else
			{
				str.Format(TEXT("%s(%s)"), pUserSet->m_name, pUserSet->m_account);
				treeCtrl.InsertItem(str, 1, 1, Root);
			}

			pUserSet->MoveNext();

		}
		if (cur != NULL){
			treeCtrl.SelectItem(cur);
		}

	}


	
	CDialogEx::OnCancel();

}


BOOL AddUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_uiClass.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

//ȡ����ť
void AddUserDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
