
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

#include "UerTreeView.h"
#include "MedicListView.h"
#include "MedicAdmin_1Doc.h"
#include "AddUserDlg.h"
#include "ChangePwd.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
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


