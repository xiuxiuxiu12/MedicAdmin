
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "MedicAdmin_1.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_ADD_USER, &CMainFrame::OnUpdateAddUser)
	ON_UPDATE_COMMAND_UI(ID_DEL_USER, &CMainFrame::OnUpdateDelUser)
	ON_UPDATE_COMMAND_UI(ID_SELECT_USER, &CMainFrame::OnUpdateSelectUser)
	ON_COMMAND(ID_SYS_CLOSE, &CMainFrame::OnSysClose)
	ON_COMMAND(ID_ADD_USER, &CMainFrame::OnAddUser)
	ON_COMMAND(ID_CHAN_PWD, &CMainFrame::OnChanPwd)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO:  在此添加专用代码和/或调用基类
	m_sWnd.CreateStatic(this, 1, 2);
	//创建视图
	/*第一个参数和第二个参数：视图放的位置
	第三个参数：窗口中放置的类
	第四个参数：视图的大小*/
	m_sWnd.CreateView(0, 0, RUNTIME_CLASS(CUerTreeView), CSize(230, 600), pContext);
	m_sWnd.CreateView(0, 1, RUNTIME_CLASS(CMedicListView), CSize(720, 600), pContext);

	return TRUE;


	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

//添加用户更新
void CMainFrame::OnUpdateAddUser(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	//如果是管理员，可以使用，否则不可以使用
	if (pUser->GetClass() == TEXT("管理员")){
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(false);
	}
}

//删除用户更新
void CMainFrame::OnUpdateDelUser(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	//如果是管理员，可以使用，否则不可以使用
	if (pUser->GetClass() == TEXT("管理员")){
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(false);
	}
}

//查询用户更新
void CMainFrame::OnUpdateSelectUser(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	//如果是管理员，可以使用，否则不可以使用
	if (pUser->GetClass() == TEXT("管理员")){
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(false);
	}
}

//系统退出的回调函数
void CMainFrame::OnSysClose()
{
	// TODO:  在此添加命令处理程序代码
	exit(0);
}

//添加用户的回调函数
void CMainFrame::OnAddUser()
{
	// TODO:  在此添加命令处理程序代码
	AddUserDlg aul;
	aul.DoModal();
}


void CMainFrame::OnChanPwd()
{
	// TODO:  在此添加命令处理程序代码
	ChangePwd cpd;
	cpd.DoModal();

}
