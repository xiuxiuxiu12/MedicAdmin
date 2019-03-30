// medicineSet.h : CmedicineSet ���ʵ��



// CmedicineSet ʵ��

// ���������� 2019��3��28��, 19:42

#include "stdafx.h"
#include "medicineSet.h"
IMPLEMENT_DYNAMIC(CmedicineSet, CRecordset)

CmedicineSet::CmedicineSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_id = L"";
	m_name = L"";
	m_classification = L"";
	m_produceDate;
	m_producePlace = L"";
	m_discription = L"";
	m_produceCompany = L"";
	m_quelityAssurance = 0;
	m_unitPrice = 0;
	m_number = 0;
	m_nFields = 10;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CmedicineSet::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=root;DATABASE=medicine;PORT=3306");
}

CString CmedicineSet::GetDefaultSQL()
{
	return _T("[medicine]");
}

void CmedicineSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[classification]"), m_classification);
	RFX_Date(pFX, _T("[produceDate]"), m_produceDate);
	RFX_Text(pFX, _T("[producePlace]"), m_producePlace);
	RFX_Text(pFX, _T("[discription]"), m_discription);
	RFX_Text(pFX, _T("[produceCompany]"), m_produceCompany);
	RFX_Long(pFX, _T("[quelityAssurance]"), m_quelityAssurance);
	RFX_Long(pFX, _T("[unitPrice]"), m_unitPrice);
	RFX_Long(pFX, _T("[number]"), m_number);

}
/////////////////////////////////////////////////////////////////////////////
// CmedicineSet ���

#ifdef _DEBUG
void CmedicineSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CmedicineSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


