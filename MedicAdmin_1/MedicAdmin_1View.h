
// MedicAdmin_1View.h : CMedicAdmin_1View 类的接口
//

#pragma once

#include "resource.h"


class CMedicAdmin_1View : public CFormView
{
protected: // 仅从序列化创建
	CMedicAdmin_1View();
	DECLARE_DYNCREATE(CMedicAdmin_1View)

public:
	enum{ IDD = IDD_MEDICADMIN_1_FORM };

// 特性
public:
	CMedicAdmin_1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMedicAdmin_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MedicAdmin_1View.cpp 中的调试版本
inline CMedicAdmin_1Doc* CMedicAdmin_1View::GetDocument() const
   { return reinterpret_cast<CMedicAdmin_1Doc*>(m_pDocument); }
#endif

