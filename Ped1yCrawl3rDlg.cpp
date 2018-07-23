
// Ped1yCrawl3rDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ped1yCrawl3r.h"
#include "Ped1yCrawl3rDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment( lib, "htmlcxx/Debug/htmlcxx.lib" )

using namespace std;
using namespace htmlcxx;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPed1yCrawl3rDlg �Ի���



CPed1yCrawl3rDlg::CPed1yCrawl3rDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPed1yCrawl3rDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPed1yCrawl3rDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, COMB_PAGE, m_combPage);
    DDX_Control(pDX, LST_SHOW, m_lstShow);
}

BEGIN_MESSAGE_MAP(CPed1yCrawl3rDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BTN_START, &CPed1yCrawl3rDlg::OnBnClickedStart)
    ON_BN_CLICKED(BTN_ELITE, &CPed1yCrawl3rDlg::OnBnClickedElite)
    ON_BN_CLICKED(BTN_GETINFO, &CPed1yCrawl3rDlg::OnBnClickedGetinfo)
    ON_BN_CLICKED(BTN_DISCON, &CPed1yCrawl3rDlg::OnBnClickedDiscon)
    ON_BN_CLICKED(BTN_OPEN, &CPed1yCrawl3rDlg::OnBnClickedOpen)
END_MESSAGE_MAP()


// CPed1yCrawl3rDlg ��Ϣ�������

BOOL CPed1yCrawl3rDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
    m_bLogin = FALSE;
    GetDlgItem(BTN_GETINFO)->EnableWindow(FALSE);
    GetDlgItem(BTN_DISCON)->EnableWindow(FALSE);
    GetDlgItem(BTN_ELITE)->EnableWindow(FALSE);
    GetDlgItem(BTN_OPEN)->EnableWindow(FALSE);
    
    m_combPage.InsertString(-1, _T("1"));
    m_combPage.InsertString(-1, _T("2"));
    m_combPage.InsertString(-1, _T("3"));
    m_combPage.InsertString(-1, _T("4"));
    m_combPage.InsertString(-1, _T("5"));
    m_combPage.InsertString(-1, _T("6"));
    m_combPage.InsertString(-1, _T("7"));
    m_combPage.InsertString(-1, _T("8"));
    m_combPage.InsertString(-1, _T("9"));
    m_combPage.InsertString(-1, _T("10"));
    m_combPage.SetCurSel(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPed1yCrawl3rDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPed1yCrawl3rDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPed1yCrawl3rDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

string Rsa(const char* p)
{
	string e = "b982c1fe000e1758e341e530dc51dfb10b3ede8ce14764a95c643c7ea45d62ec6b2f8b5be3c89a10851b514a7f79d31e3df15524c7bad4c60d7f49c0557eb47140e67cc450727b7a630337dbdb6f910ae600a5256927738edcab04b8a1317edcfda0506fdde8f13e561ce72abb62204ef179539d037449ae11e2a84f3b723631";
	RSA* pRSA = RSA_new();
	BIGNUM *pN = BN_new();
	BIGNUM *pE = BN_new();

	string strEncrypt;

	unsigned char szDest[128] = { 0 };

	char szPlainText[512] = { 0 };
	wsprintfA(szPlainText, "%s", p);

	//���ַ���ת�ɴ�����ʮ�����ƣ�
	BN_hex2bn(&pE, e.c_str());
	BN_hex2bn(&pN, "10001");

	pRSA->n = pE;
	pRSA->e = pN;
	pRSA->d = NULL;

	int flen = RSA_size(pRSA); // RSA��Կ����

	//��Կ����
	//���һ�������ǲ��뷽ʽ���ĵ���һ�����֣�ͷ�ļ��������ֶࣩ
	RSA_public_encrypt(strlen(szPlainText), (unsigned char*)szPlainText, (unsigned char*)szDest, pRSA, RSA_PKCS1_PADDING);

	strEncrypt = CSkyChaserHttp::sc_base64Encode((const char *)szDest, flen);

	//�ͷ���Դ
	//BN_free(pN);
	//BN_free(pE);
	RSA_free(pRSA);

	return strEncrypt.c_str();
}

void GetOutPutString(string str, CString& strUni)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, strUni.GetBufferSetLength(len), len);
    strUni.ReleaseBuffer();
}

void CPed1yCrawl3rDlg::GetInfoFromHtml(string html)
{
    HTML::ParserDom parser;
    tree<HTML::Node> dom = parser.parseTree(html);
    tree<HTML::Node>::iterator it = dom.begin();
    tree<HTML::Node>::iterator end = dom.end();
    list<CString> listtxt;

    for (; it != end; ++it)
    {
        if ((!it->isTag()) && (!it->isComment()))
        {
            CString strUni;
            GetOutPutString(it->text(), strUni);
            OutputDebugString(strUni);
            if (strUni.Find(_T("�û���")) != -1)
            {
                CString str;
                tree<HTML::Node>::iterator itTmp = it;
                itTmp += 3;
                if (itTmp != NULL)
                {
                    GetOutPutString(itTmp->text(), str);             
                    SetDlgItemText(STC_USERNAME, str);
                }
            }
            if (strUni.Find(_T("��֤״̬")) != -1)
            {
                CString str;
                tree<HTML::Node>::iterator itTmp = it;
                itTmp += 5;
                if (itTmp != NULL)
                {
                    GetOutPutString(itTmp->text(), str);
                    SetDlgItemText(STC_AUTH, str);
                }
            }
            if (strUni.Find(_T("�û���")) != -1)
            {
                CString str;
                tree<HTML::Node>::iterator itTmp = it;
                itTmp += 3;
                if (itTmp != NULL)
                {
                    GetOutPutString(itTmp->text(), str);
                    SetDlgItemText(STC_GROUP, str);
                }
            }
            if (strUni.Find(_T("�û�ʱ��")) != -1)
            {
                CString str;
                tree<HTML::Node>::iterator itTmp = it;
                itTmp += 3;
                if (itTmp != NULL)
                {
                    GetOutPutString(itTmp->text(), str);
                    SetDlgItemText(STC_TIMEZONE, str);
                }
            }
            if (strUni.Find(_T("ע��ʱ��")) != -1)
            {
                CString str;
                tree<HTML::Node>::iterator itTmp = it;
                itTmp += 3;
                if (itTmp != NULL)
                {
                    GetOutPutString(itTmp->text(), str);
                    SetDlgItemText(STC_REGISTIME, str);
                }
            }
            if (strUni.Find(_T("����¼")) != -1)
            {
                CString str;
                tree<HTML::Node>::iterator itTmp = it;
                itTmp += 3;
                if (itTmp != NULL)
                {
                    GetOutPutString(itTmp->text(), str);
                    SetDlgItemText(STC_LASTLOGIN, str);
                }
            }
        }
    }
}

void CPed1yCrawl3rDlg::LoginPediy()
{
	unsigned char MD5result[MD5LENTH] = { 0 };
    char szUsername[256] = { 0 };
    char szPassword[256] = { 0 };
    GetDlgItemTextA(GetSafeHwnd(), EDT_USERNAME, szUsername, 255);
    GetDlgItemTextA(GetSafeHwnd(), EDT_PASSWORD, szPassword, 255);
    if (CStringA(szUsername) == "" || CStringA(szPassword) == "")
    {
        AfxMessageBox(_T("�˺ź����벻��Ϊ��"));
        return;
    }

    string strAccount = szUsername;
    string strPwd = szPassword;

	MD5((const unsigned char*)strPwd.c_str(), strPwd.length(), MD5result);

	string strEncodePwd;
	CStringA str;

	for (int i = 0; i < MD5LENTH; i++)
	{
		str.Format("%02x", MD5result[i]);
		strEncodePwd += str.GetBuffer(0);
	}


	CSkyChaserHttp http;
    string strRet;
	string strUrl = "passport.kanxue.com/user-login.htm";

	CStringA strData;
	strData.Format("account=%s&password=%s", strAccount.c_str(), strEncodePwd.c_str());

	//http.sc_setProxy("127.0.0.1:8080");

	http.sc_appendHeader("Connection: close");
    CStringA strLen;
    strLen.Format("Content-Length: %d", strData.GetLength());
    http.sc_appendHeader(strLen);
	http.sc_appendHeader("Accept: text/plain, */*; q=0.01");
	http.sc_appendHeader("Origin: https://passport.kanxue.com");
	http.sc_appendHeader("X-Requested-With: XMLHttpRequest");
	http.sc_appendHeader("User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36");
	http.sc_appendHeader("Content-Type: application/x-www-form-urlencoded; charset=UTF-8");
	http.sc_appendHeader("Referer: https://passport.kanxue.com/user-login.htm");
	http.sc_appendHeader("Accept-Encoding: gzip, deflate");
    http.sc_appendHeader("Accept-Language: zh-CN,zh;q=0.9");
    http.sc_saveCookieFile("loginCookie.txt");
	
    CURLcode urlCodeRet = http.sc_post(strUrl.c_str(), strData.GetBuffer(), strRet);
    if (urlCodeRet == CURLE_OK)
    {
        m_bLogin = TRUE;
        GetDlgItem(BTN_START)->EnableWindow(FALSE);
        GetDlgItem(BTN_GETINFO)->EnableWindow(TRUE);
        GetDlgItem(BTN_DISCON)->EnableWindow(TRUE);
        GetDlgItem(EDT_USERNAME)->EnableWindow(FALSE);
        GetDlgItem(EDT_PASSWORD)->EnableWindow(FALSE);
        GetDlgItem(BTN_ELITE)->EnableWindow(TRUE);
        GetDlgItem(BTN_OPEN)->EnableWindow(TRUE);
    }
}

void CPed1yCrawl3rDlg::OnBnClickedStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	LoginPediy();
}

void CPed1yCrawl3rDlg::GetEliteFromHtml(string strRet)
{
    HTML::ParserDom parser;
    tree<HTML::Node> dom = parser.parseTree(strRet);
    tree<HTML::Node>::iterator it = dom.begin();
    tree<HTML::Node>::iterator end = dom.end();
    list<CString> listtxt;

    for (; it != end; ++it)
    {
        if (_stricmp(it->tagName().c_str(), "A") == 0)
        {
            it->parseAttributes();
            if (it->attribute("href").first)
            {
                string url;
                string fileName;
                CString strUrl;
                CString strfileName;
        
                url = it->attribute("href").second;
                if (it.node != NULL && it.node->first_child != NULL)
                {
                    fileName = it.node->first_child->data;//��ȡxxx.html
                    GetOutPutString(url, strUrl);
                    GetOutPutString(fileName, strfileName);
                    if (strUrl.Find(_T("thread-")) != -1)
                    {
                        if (strfileName != _T("") && strfileName.Find(_T("\t")) == -1 && 
                            strfileName.Find(_T("\r")) == -1 && strfileName.Find(_T("\n")) == -1)
                        {
                            int nIndex = m_lstShow.InsertString(-1, strfileName);
                            CString str; 
                            str = _T("https://bbs.pediy.com/") + strUrl;
                            m_array_elite[nIndex] = str;
                            m_lstShow.SetItemDataPtr(nIndex, &m_array_elite[nIndex]);
                        }
                    }
                }      
            }
        }
    }
}

void CPed1yCrawl3rDlg::OnBnClickedElite()
{
    //��ȡ������
    if (m_bLogin)
    {
        m_lstShow.ResetContent();

        CSkyChaserHttp getElite;
        string strRet;

        char szPage[8] = { 0 };
        CStringA getEliteUrl;
        CStringA strPage;
        GetDlgItemTextA(GetSafeHwnd(), COMB_PAGE, szPage, 8);
        strPage = szPage;

        getEliteUrl = "bbs.pediy.com/new-digest-" + strPage + ".htm";
        //getElite.sc_setProxy("127.0.0.1:8080");

        getElite.sc_appendHeader("User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:61.0) Gecko/20100101 Firefox/61.0");
        getElite.sc_appendHeader("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8*");
        getElite.sc_appendHeader("Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2");
        getElite.sc_appendHeader("Accept-Encoding: gzip, deflate");
        getElite.sc_appendHeader("Referer: https://bbs.pediy.com/new-digest-1.htm");
        getElite.sc_appendHeader("Upgrade-Insecure-Requests: 1");
        getElite.sc_appendHeader("Connection: close");


        getElite.sc_setCookieFile("loginCookie.txt");
        CURLcode urlCodeRet = getElite.sc_get(getEliteUrl.GetBuffer(), strRet);
        if (urlCodeRet == CURLE_OK)
        {
            GetEliteFromHtml(strRet);
        }
    }   
}


void CPed1yCrawl3rDlg::OnBnClickedGetinfo()
{
    // TODO: Add your control notification handler code here
    if (m_bLogin)
    {
        //���token

        /*char szTokenBuf[2048] = { 0 };
        sscanf(m_strRet.c_str(), "{\n    \"code\": 0,\n    \"message\": \"%s\"\n}", szTokenBuf);*/

        CSkyChaserHttp get;
        string strRet;
        CStringA getUrl;
        getUrl = "passport.kanxue.com/my.htm";
        //get.sc_setProxy("127.0.0.1:8080");

        get.sc_appendHeader("User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:61.0) Gecko/20100101 Firefox/61.0");
        get.sc_appendHeader("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8*");
        get.sc_appendHeader("Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2");
        get.sc_appendHeader("Accept-Encoding: gzip, deflate");
        get.sc_appendHeader("Referer: https://bbs.pediy.com/");
        get.sc_appendHeader("Upgrade-Insecure-Requests: 1");
        get.sc_appendHeader("Cache-Control: max-age=0");


        get.sc_setCookieFile("loginCookie.txt");
        CURLcode urlCodeRet = get.sc_get(getUrl.GetBuffer(), strRet);
        if (urlCodeRet == CURLE_OK)
        {
            GetInfoFromHtml(strRet);
            GetDlgItem(BTN_GETINFO)->EnableWindow(FALSE);
        }             
    }
}


void CPed1yCrawl3rDlg::OnBnClickedDiscon()
{
    // TODO: Add your control notification handler code here
    m_bLogin = FALSE;
    
    GetDlgItem(BTN_START)->EnableWindow(TRUE);
    GetDlgItem(BTN_GETINFO)->EnableWindow(FALSE);
    GetDlgItem(BTN_DISCON)->EnableWindow(FALSE);
    GetDlgItem(BTN_ELITE)->EnableWindow(FALSE);
    GetDlgItem(EDT_USERNAME)->EnableWindow(TRUE);
    GetDlgItem(EDT_PASSWORD)->EnableWindow(TRUE);
    GetDlgItem(BTN_OPEN)->EnableWindow(FALSE);
    SetDlgItemText(STC_USERNAME, _T(""));
    SetDlgItemText(STC_AUTH, _T(""));
    SetDlgItemText(STC_TIMEZONE, _T(""));
    SetDlgItemText(STC_GROUP, _T(""));
    SetDlgItemText(STC_REGISTIME, _T(""));
    SetDlgItemText(STC_LASTLOGIN, _T(""));
    m_lstShow.ResetContent();
}

void CPed1yCrawl3rDlg::OnBnClickedOpen()
{
    int nIndex = m_lstShow.GetCurSel();
    if (LB_ERR == nIndex)
    {
        AfxMessageBox(_T("��ѡ��һ������"));
        return;
    }
    CString* pStr = (CString*)m_lstShow.GetItemDataPtr(nIndex);
    ShellExecute(NULL, _T("open"), *pStr, NULL, NULL, SW_SHOWNORMAL);
}
