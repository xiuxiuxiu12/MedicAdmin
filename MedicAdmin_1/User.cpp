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

//����˻�
CString CUser::GetAccount(){
	return m_account;
}

//�������
CString CUser::GetPwd(){
	return m_pwd;

}

//�������
CString CUser::GetName(){
	return m_name;
}

//������
CString CUser::GetClass(){
	return m_classification;
}


//�����˻�
void CUser::SetAccount(CString account){
	m_account = account;
}

//��������
void CUser::SetPwd(CString pwd){
	m_pwd = pwd;
}

//��������
void CUser::SetName(CString name){
	m_name = name;
}


//�������
void CUser::SetClass(CString classification){
	m_classification = classification;
}


//����m_userSet
void CUser::SetUserSet(CuserSet *pUserSet){
	m_userSet = pUserSet;
}

//�û���¼���ɹ�����0
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

//����û�
int CUser::AddUser(CString account, CString pwd, CString name, CString classification){
	if (m_userSet == NULL){
		return -1;
	}
	if (m_userSet->IsOpen() == false){
		m_userSet->Open();
	}
	//���һ���µĿռ�¼
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

//��������
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