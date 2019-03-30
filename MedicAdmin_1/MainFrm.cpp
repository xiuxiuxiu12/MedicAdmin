
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO:  �ڴ����ר�ô����/����û���
	m_sWnd.CreateStatic(this, 1, 2);
	//������ͼ
	/*��һ�������͵ڶ�����������ͼ�ŵ�λ��
	�����������������з��õ���
	���ĸ���������ͼ�Ĵ�С*/
	m_sWnd.CreateView(0, 0, RUNTIME_CLASS(CUerTreeView), CSize(230, 600), pContext);
	m_sWnd.CreateView(0, 1, RUNTIME_CLASS(CMedicListView), CSize(720, 600), pContext);

	return TRUE;


	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

//����û�����
void CMainFrame::OnUpdateAddUser(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	//����ǹ���Ա������ʹ�ã����򲻿���ʹ��
	if (pUser->GetClass() == TEXT("����Ա")){
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(false);
	}
}

//ɾ���û�����
void CMainFrame::OnUpdateDelUser(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	//����ǹ���Ա������ʹ�ã����򲻿���ʹ��
	if (pUser->GetClass() == TEXT("����Ա")){
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(false);
	}
}

//��ѯ�û�����
void CMainFrame::OnUpdateSelectUser(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetActiveDocument();
	CUser *pUser = pDoc->GetUser();
	//����ǹ���Ա������ʹ�ã����򲻿���ʹ��
	if (pUser->GetClass() == TEXT("����Ա")){
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(false);
	}
}

//ϵͳ�˳��Ļص�����
void CMainFrame::OnSysClose()
{
	// TODO:  �ڴ���������������
	exit(0);
}

//����û��Ļص�����
void CMainFrame::OnAddUser()
{
	// TODO:  �ڴ���������������
	AddUserDlg aul;
	aul.DoModal();
}


void CMainFrame::OnChanPwd()
{
	// TODO:  �ڴ���������������
	ChangePwd cpd;
	cpd.DoModal();

}
