// MedicListView.cpp : ʵ���ļ�
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


// CMedicListView ���

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


// CMedicListView ��Ϣ�������


void CMedicListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetDocument();
	CmedicineSet *pMedicSet = pDoc->GetMedicSet();
	if (pMedicSet->IsOpen() == false){
		pMedicSet->Open();
	}
	pMedicSet->Requery();

	//��ȡ�б���ͼ���б���ͼ�ؼ�
	CListCtrl &listCtrl = this->GetListCtrl();

	//�����б���ͼ�ؼ��ķ��
	listCtrl.SetExtendedStyle(listCtrl.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	//����ģʽ
	listCtrl.ModifyStyle(0, LVS_REPORT);

	//���ñ�ͷ
	CString head[] = {
		TEXT("ҩƷ����"), TEXT("ҩƷ����"), TEXT("ҩƷ���"),
		TEXT("�����Ŀ"), TEXT("������˾"), TEXT("����"),
		TEXT("����ʱ��"), TEXT("�����ڣ��£�"), TEXT("���ۣ�Ԫ��")
	};
	int headsize = sizeof(head) / sizeof(head[0]);
	for (int i = 0; i < headsize; i++){
		//���ñ�ͷ
		listCtrl.InsertColumn(i, head[i], LVCFMT_LEFT, 100);
	}
	int count = pMedicSet->GetRecordCount();
	for (int i = 0; i < headsize; i++){
		//����������
		//ҩƷ����
		listCtrl.InsertItem(i, pMedicSet->m_id);

		//����������
		int j = 1;
		//ҩƷ����
		listCtrl.SetItemText(i, j++, pMedicSet->m_name);
		//ҩƷ���
		listCtrl.SetItemText(i, j++, pMedicSet->m_classification);

		//�����Ŀ
		CString str;
		str.Format(TEXT("%d"), pMedicSet->m_number);
		listCtrl.SetItemText(i, j++, str);

		//������˾
		listCtrl.SetItemText(i, j++, pMedicSet->m_produceCompany);
		//����
		listCtrl.SetItemText(i, j++, pMedicSet->m_producePlace);

		//����ʱ��
		str = pMedicSet->m_produceDate.Format(TEXT("%Y-%m-%d"));
		listCtrl.SetItemText(i, j++, str);

		//�����ڣ��£�
		str.Format(TEXT("%d"), pMedicSet->m_quelityAssurance);
		listCtrl.SetItemText(i, j++, str);

		//���ۣ�Ԫ��
		str.Format(TEXT("%d"), pMedicSet->m_unitPrice);
		listCtrl.SetItemText(i, j, str);

		pMedicSet->MoveNext();

	}



}
