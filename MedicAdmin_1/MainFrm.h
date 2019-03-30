
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

#include "UerTreeView.h"
#include "MedicListView.h"
#include "MedicAdmin_1Doc.h"
#include "AddUserDlg.h"
#include "ChangePwd.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_sWnd;

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnUpdateAddUser(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDelUser(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSelectUser(CCmdUI *pCmdUI);
	afx_msg void OnSysClose();
	afx_msg void OnAddUser();
	afx_msg void OnChanPwd();
};


