
// Ped1yCrawl3r.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPed1yCrawl3rApp: 
// �йش����ʵ�֣������ Ped1yCrawl3r.cpp
//

class CPed1yCrawl3rApp : public CWinApp
{
public:
	CPed1yCrawl3rApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPed1yCrawl3rApp theApp;