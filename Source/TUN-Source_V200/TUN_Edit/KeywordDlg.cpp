// KeywordDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "TUN_Edit.h"
#include "KeywordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CKeywordDlg 


CKeywordDlg::CKeywordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeywordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKeywordDlg)
	m_cstrKeyword = _T("");
	//}}AFX_DATA_INIT
}


void CKeywordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKeywordDlg)
	DDX_Text(pDX, IDC_EDIT_Keyword, m_cstrKeyword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKeywordDlg, CDialog)
	//{{AFX_MSG_MAP(CKeywordDlg)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CKeywordDlg 
