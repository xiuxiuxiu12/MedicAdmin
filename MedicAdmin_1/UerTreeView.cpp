// UerTreeView.cpp : ʵ���ļ�
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


// CUerTreeView ���

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


// CUerTreeView ��Ϣ�������


void CUerTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();


	// TODO:  �ڴ����ר�ô����/����û���

	// TODO:  �ڴ����ר�ô����/����û���
	CMedicAdmin_1Doc *pDoc = (CMedicAdmin_1Doc *)GetDocument();
	//��ȡ���ݼ�ָ��
	CuserSet *pUserSet = pDoc->GetUserSet();
	if (pUserSet->IsOpen() == false){
		pUserSet->Open();
	}

	CLoginDlg dlg;
	dlg.DoModal();
	
	//��ȡ��ͼ���������ؼ�
	CTreeCtrl &treeCtrl = this->GetTreeCtrl();
	//�������ؼ��ķ��
	treeCtrl.ModifyStyle(NULL, WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES | TVS_DISABLEDRAGDROP);

	HICON icon[3];
	icon[0] = AfxGetApp()->LoadIconW(IDI_ICON1);
	icon[1] = AfxGetApp()->LoadIconW(IDI_ICON2);
	icon[2] = AfxGetApp()->LoadIconW(IDI_ICON3);

	//����ͼƬ
	m_imageList.Create(30, 30, ILC_COLOR32, 3, 3);
	for (int i = 0; i < 3; i++){
		m_imageList.Add(icon[i]);
	}

	//�����ؼ�����ͼ���б�
	treeCtrl.SetImageList(&m_imageList, TVSIL_NORMAL);


	CString type[3] = { TEXT("����Ա"), TEXT("ҽ��"), TEXT("��ҩԱ") };

	//��ȡ��¼�û�
	CUser *pUer = pDoc->GetUser();
	HTREEITEM cur = NULL;
	for (int i = 0; i < 3; i++){
		//�����ڵ�
		HTREEITEM Root = treeCtrl.InsertItem(type[i], 0, 0, NULL);
		//��������Ա���ӽڵ�
		CString sql;
		sql.Format(TEXT("classification = '%s'"), type[i]);
		pUserSet->m_strFilter = sql;
		pUserSet->Requery();

		while (pUserSet->IsEOF() == false){
			CString str;
			if (pUserSet->m_account == pUer->GetAccount()){
				str.Format(TEXT("%s(%s)[��¼�û�]"), pUserSet->m_name, pUserSet->m_account);
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
