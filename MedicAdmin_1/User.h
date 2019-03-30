#pragma once
#include "userSet.h"
class CUser
{
public:
	CUser();
	virtual ~CUser();
private:
	CString m_account;
	CString m_pwd;
	CString m_name;
	CString m_classification;
	CuserSet *m_userSet;

public:
	//����˻�
	CString GetAccount();

	//�������
	CString GetPwd();

	//�������
	CString GetName();

	//������
	CString GetClass();

	//�����˻�
	void SetAccount(CString account);

	//��������
	void SetPwd(CString pwd);

	//��������
	void SetName(CString name);

	//�������
	void SetClass(CString classification);

	//����m_userSet
	void SetUserSet(CuserSet *pUserSet);

	//�û���¼���ɹ�����0
	int Login();

	//����û�
	int AddUser(CString account, CString pwd, CString name, CString classification);

	//��������
	int ChangePwd(CString oriPwd, CString newPwd, CString sureNewPwd);

};

