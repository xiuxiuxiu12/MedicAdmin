
// MedicAdmin_1View.cpp : CMedicAdmin_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMedicAdmin_1View ����/����

CMedicAdmin_1View::CMedicAdmin_1View()
	: CFormView(CMedicAdmin_1View::IDD)
{
	// TODO:  �ڴ˴���ӹ������

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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMedicAdmin_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMedicAdmin_1View ���

#ifdef _DEBUG
void CMedicAdmin_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMedicAdmin_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMedicAdmin_1Doc* CMedicAdmin_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedicAdmin_1Doc)));
	return (CMedicAdmin_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMedicAdmin_1View ��Ϣ�������
