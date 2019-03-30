// userSet.h : CuserSet ���ʵ��



// CuserSet ʵ��

// ���������� 2019��3��28��, 19:51

#include "stdafx.h"
#include "userSet.h"
IMPLEMENT_DYNAMIC(CuserSet, CRecordset)

CuserSet::CuserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_account = L"";
	m_password = L"";
	m_name = L"";
	m_classification = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CuserSet::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=root;DATABASE=medicine;PORT=3306");
}

CString CuserSet::GetDefaultSQL()
{
	return _T("[user]");
}

void CuserSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[account]"), m_account);
	RFX_Text(pFX, _T("[password]"), m_password);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[classification]"), m_classification);

}
/////////////////////////////////////////////////////////////////////////////
// CuserSet ���

#ifdef _DEBUG
void CuserSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CuserSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


