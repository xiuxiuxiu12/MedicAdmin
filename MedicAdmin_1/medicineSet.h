// medicineSet.h : CmedicineSet ������

#pragma once

// ���������� 2019��3��28��, 19:42

class CmedicineSet : public CRecordset
{
public:
	CmedicineSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CmedicineSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	m_id;
	CStringW	m_name;
	CStringW	m_classification;
	CTime	m_produceDate;
	CStringW	m_producePlace;
	CStringW	m_discription;
	CStringW	m_produceCompany;
	long	m_quelityAssurance;
	long	m_unitPrice;
	long	m_number;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


