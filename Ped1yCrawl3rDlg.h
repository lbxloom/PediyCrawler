
// Ped1yCrawl3rDlg.h : ͷ�ļ�
//

#pragma once
#include <iostream>
#include <sstream> 
#include <iomanip>
#include <list>
#include "openssl/aes.h"
#include "openssl/rsa.h"
#include <openssl/hmac.h> 
#include "SkyChaserHttp.h"
#include <openssl/md5.h>
#include "htmlcxx/html/ParserDom.h"
#include "afxwin.h"



#define MAXDATABUFF 1024
#define MD5LENTH 16

// CPed1yCrawl3rDlg �Ի���
class CPed1yCrawl3rDlg : public CDialogEx
{
// ����
public:
	CPed1yCrawl3rDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PED1YCRAWL3R_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

    void GetInfoFromHtml(string html);
    void LoginPediy();
    void GetEliteFromHtml(string strRet);

// ʵ��
protected:
	HICON m_hIcon;
    BOOL m_bLogin;
    CString m_array_elite[256];
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();
    afx_msg void OnBnClickedElite();
    afx_msg void OnBnClickedGetinfo();
    afx_msg void OnBnClickedDiscon();
    CComboBox m_combPage;
    CListBox m_lstShow;
    afx_msg void OnBnClickedOpen();
};
