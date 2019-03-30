
// MedicAdmin_1Doc.cpp : CMedicAdmin_1Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MedicAdmin_1.h"
#endif

#include "MedicAdmin_1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMedicAdmin_1Doc

IMPLEMENT_DYNCREATE(CMedicAdmin_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMedicAdmin_1Doc, CDocument)
END_MESSAGE_MAP()


// CMedicAdmin_1Doc ����/����

CMedicAdmin_1Doc::CMedicAdmin_1Doc()
{
	// TODO:  �ڴ����һ���Թ������

}

CMedicAdmin_1Doc::~CMedicAdmin_1Doc()
{
}

BOOL CMedicAdmin_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMedicAdmin_1Doc ���л�

void CMedicAdmin_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMedicAdmin_1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMedicAdmin_1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMedicAdmin_1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMedicAdmin_1Doc ���

#ifdef _DEBUG
void CMedicAdmin_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMedicAdmin_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMedicAdmin_1Doc ����

CmedicineSet* CMedicAdmin_1Doc::GetMedicSet(){
	return &pMedicSet;
}

CuserSet* CMedicAdmin_1Doc::GetUserSet(){
	return &pUserSet;
}

CUser *CMedicAdmin_1Doc::GetUser(){
	return &pUser;
}
