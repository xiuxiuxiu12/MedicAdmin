
// MedicAdmin_1View.cpp : CMedicAdmin_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MedicAdmin_1.h"
#endif

#include "MedicAdmin_1Doc.h"
#include "MedicAdmin_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMedicAdmin_1View

IMPLEMENT_DYNCREATE(CMedicAdmin_1View, CFormView)

BEGIN_MESSAGE_MAP(CMedicAdmin_1View, CFormView)
END_MESSAGE_MAP()

// CMedicAdmin_1View 构造/析构

CMedicAdmin_1View::CMedicAdmin_1View()
	: CFormView(CMedicAdmin_1View::IDD)
{
	// TODO:  在此处添加构造代码

}

CMedicAdmin_1View::~CMedicAdmin_1View()
{
}

void CMedicAdmin_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMedicAdmin_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMedicAdmin_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMedicAdmin_1View 诊断

#ifdef _DEBUG
void CMedicAdmin_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMedicAdmin_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMedicAdmin_1Doc* CMedicAdmin_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedicAdmin_1Doc)));
	return (CMedicAdmin_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMedicAdmin_1View 消息处理程序
