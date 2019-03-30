
// MedicAdmin_1Doc.h : CMedicAdmin_1Doc ��Ľӿ�
//


#pragma once
#include "medicineSet.h"
#include "userSet.h"
#include "User.h"


class CMedicAdmin_1Doc : public CDocument
{
protected: // �������л�����
	CMedicAdmin_1Doc();
	DECLARE_DYNCREATE(CMedicAdmin_1Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMedicAdmin_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

private:
	CmedicineSet pMedicSet;
	CuserSet pUserSet;
	CUser pUser;
public:
	CmedicineSet *GetMedicSet();
	CuserSet *GetUserSet();
	CUser *GetUser();
};
