// AddUserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin_1.h"
#include "AddUserDlg.h"
#include "afxdialogex.h"


// AddUserDlg 对话框

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


// AddUserDlg 消息处理程序

//确定按钮的回调函数
void AddUserDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)pFrame->GetActiveDocument();
	//获取文档类中的user对象
	CUser *pUser = pDoc->GetUser();
	UpdateData(true);
	int ret = pUser->AddUser(m_uiAccount, m_uiPwd, m_uiName, m_uiclass);
	if (ret == -1){
		MessageBox(TEXT("数据库连接错误"));
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
	

	//获取视图关联的树控件
	CTreeCtrl &treeCtrl = treeView->GetTreeCtrl();
	treeCtrl.DeleteAllItems();

	CuserSet *pUserSet = pDoc->GetUserSet();
	pUserSet->m_strFilter = TEXT("");
	pUserSet->Requery();

	CString type[3] = { TEXT("管理员"), TEXT("医生"), TEXT("售药员") };

	HTREEITEM cur = NULL;
	for (int i = 0; i < 3; i++){
		//创建节点
		HTREEITEM Root = treeCtrl.InsertItem(type[i], 0, 0, NULL);
		//创建管理员的子节点
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type[i]);
		pUserSet->m_strFilter = sql;
		pUserSet->Requery();

		while (pUserSet->IsEOF() == false){
			CString str;
			if (pUserSet->m_account == pUser->GetAccount()){
				str.Format(TEXT("%s(%s)[登录用户]"), pUserSet->m_name, pUserSet->m_account);
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

	// TODO:  在此添加额外的初始化
	m_uiClass.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

//取消按钮
void AddUserDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
