#include "stdafx.h"
#include "User.h"


CUser::CUser()
{
	m_account = TEXT("");
	m_name = TEXT("");
	m_pwd = TEXT("");
	m_classification = TEXT("");
}


CUser::~CUser()
{
}

//获得账户
CString CUser::GetAccount(){
	return m_account;
}

//获得密码
CString CUser::GetPwd(){
	return m_pwd;

}

//获得姓名
CString CUser::GetName(){
	return m_name;
}

//获得类别
CString CUser::GetClass(){
	return m_classification;
}


//设置账户
void CUser::SetAccount(CString account){
	m_account = account;
}

//设置密码
void CUser::SetPwd(CString pwd){
	m_pwd = pwd;
}

//设置姓名
void CUser::SetName(CString name){
	m_name = name;
}


//设置类别
void CUser::SetClass(CString classification){
	m_classification = classification;
}


//设置m_userSet
void CUser::SetUserSet(CuserSet *pUserSet){
	m_userSet = pUserSet;
}

//用户登录，成功返回0
int CUser::Login(){
	if (m_userSet->IsOpen() == false){
		m_userSet->Open();
	}

	m_userSet->m_strFilter.Format(TEXT("account = '%s'"), this->GetAccount());
	m_userSet->Requery();
	if (m_userSet->m_password == this->GetPwd()){
		m_name = m_userSet->m_name;
		m_classification = m_userSet->m_classification;
		return 0;
	}
	else
	{
		return -1;
	}
}

//添加用户
int CUser::AddUser(CString account, CString pwd, CString name, CString classification){
	if (m_userSet == NULL){
		return -1;
	}
	if (m_userSet->IsOpen() == false){
		m_userSet->Open();
	}
	//添加一个新的空记录
	m_userSet->AddNew();
	m_userSet->m_account = account;
	m_userSet->m_password = pwd;
	m_userSet->m_name = name;
	m_userSet->m_classification = classification;
	
	if (m_userSet->CanUpdate()){
		m_userSet->Update();
	}
	return 0;
	
}

//更改密码
int CUser::ChangePwd(CString oriPwd, CString newPwd, CString sureNewPwd){
	if (m_userSet->IsOpen() == false){
		m_userSet->Open();
	}
	if (newPwd != sureNewPwd){
		return -1;
	}
	if (oriPwd != this->GetPwd()){
		return -2;
	}

	m_userSet->m_strFilter.Format(TEXT("account = '%s' and password = '%s'"), this->GetAccount(), this->GetPwd());
	m_userSet->Requery();
	m_userSet->Edit();
	m_userSet->m_password = newPwd;
	m_userSet->Update();
	this->SetPwd(newPwd);
	return 0;
}