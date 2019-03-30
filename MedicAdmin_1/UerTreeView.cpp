// UerTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin_1.h"
#include "UerTreeView.h"


// CUerTreeView

IMPLEMENT_DYNCREATE(CUerTreeView, CTreeView)

CUerTreeView::CUerTreeView()
{

}

CUerTreeView::~CUerTreeView()
{
}

BEGIN_MESSAGE_MAP(CUerTreeView, CTreeView)
END_MESSAGE_MAP()


// CUerTreeView 诊断

#ifdef _DEBUG
void CUerTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CUerTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUerTreeView 消息处理程序


void CUerTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();


	// TODO:  在此添加专用代码和/或调用基类

	// TODO:  在此添加专用代码和/或调用基类
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetDocument();
	//获取数据集指针
	CuserSet *pUserSet = pDoc->GetUserSet();
	if (pUserSet->IsOpen() == false){
		pUserSet->Open();
	}

	CLoginDlg dlg;
	dlg.DoModal();
	
	//获取视图关联的树控件
	CTreeCtrl &treeCtrl = this->GetTreeCtrl();
	//设置树控件的风格
	treeCtrl.ModifyStyle(NULL, WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES | TVS_DISABLEDRAGDROP);

	HICON icon[3];
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);

	//加载图片
	m_imageList.Create(30, 30, ILC_COLOR32, 3, 3);
	for (int i = 0; i < 3; i++){
		m_imageList.Add(icon[i]);
	}

	//给树控件设置图像列表
	treeCtrl.SetImageList(&m_imageList, TVSIL_NORMAL);


	CString type[3] = { TEXT("管理员"), TEXT("医生"), TEXT("售药员") };

	//获取登录用户
	CUser *pUer = pDoc->GetUser();
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
			if (pUserSet->m_account == pUer->GetAccount()){
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


}
