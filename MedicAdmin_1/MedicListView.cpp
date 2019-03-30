// MedicListView.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicAdmin_1.h"
#include "MedicListView.h"


// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{

}

CMedicListView::~CMedicListView()
{
}

BEGIN_MESSAGE_MAP(CMedicListView, CListView)
END_MESSAGE_MAP()


// CMedicListView 诊断

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMedicListView 消息处理程序


void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetDocument();
	CmedicineSet *pMedicSet = pDoc->GetMedicSet();
	if (pMedicSet->IsOpen() == false){
		pMedicSet->Open();
	}
	pMedicSet->Requery();

	//获取列表视图的列表视图控件
	CListCtrl &listCtrl = this->GetListCtrl();

	//设置列表视图控件的风格
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	//设置模式
	listCtrl.ModifyStyle(0, LVS_REPORT);

	//设置表头
	CString head[] = {
		TEXT("药品代号"), TEXT("药品名称"), TEXT("药品类别"),
		TEXT("库存数目"), TEXT("出厂公司"), TEXT("产地"),
		TEXT("出厂时间"), TEXT("保质期（月）"), TEXT("单价（元）")
	};
	int headsize = sizeof(head) / sizeof(head[0]);
	for (int i = 0; i < headsize; i++){
		//设置表头
		listCtrl.InsertColumn(i, head[i], LVCFMT_LEFT, 100);
	}
	int count = pMedicSet->GetRecordCount();
	for (int i = 0; i < headsize; i++){
		//设置行数据
		//药品代号
		listCtrl.InsertItem(i, pMedicSet->m_id);

		//设置列数据
		int j = 1;
		//药品名称
		listCtrl.SetItemText(i, j++, pMedicSet->m_name);
		//药品类别
		listCtrl.SetItemText(i, j++, pMedicSet->m_classification);

		//库存数目
		CString str;
		str.Format(TEXT("%d"), pMedicSet->m_number);
		listCtrl.SetItemText(i, j++, str);

		//出厂公司
		listCtrl.SetItemText(i, j++, pMedicSet->m_produceCompany);
		//产地
		listCtrl.SetItemText(i, j++, pMedicSet->m_producePlace);

		//出厂时间
		str = pMedicSet->m_produceDate.Format(TEXT("%Y-%m-%d"));
		listCtrl.SetItemText(i, j++, str);

		//保质期（月）
		str.Format(TEXT("%d"), pMedicSet->m_quelityAssurance);
		listCtrl.SetItemText(i, j++, str);

		//单价（元）
		str.Format(TEXT("%d"), pMedicSet->m_unitPrice);
		listCtrl.SetItemText(i, j, str);

		pMedicSet->MoveNext();

	}



}
