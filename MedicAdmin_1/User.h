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
	//获得账户
	CString GetAccount();

	//获得密码
	CString GetPwd();

	//获得姓名
	CString GetName();

	//获得类别
	CString GetClass();

	//设置账户
	void SetAccount(CString account);

	//设置密码
	void SetPwd(CString pwd);

	//设置姓名
	void SetName(CString name);

	//设置类别
	void SetClass(CString classification);

	//设置m_userSet
	void SetUserSet(CuserSet *pUserSet);

	//用户登录，成功返回0
	int Login();

	//添加用户
	int AddUser(CString account, CString pwd, CString name, CString classification);

	//更改密码
	int ChangePwd(CString oriPwd, CString newPwd, CString sureNewPwd);

};

