// CompositionDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "TUN_Edit.h"
#include "CompositionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CCompositionDlg 


CCompositionDlg::CCompositionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCompositionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCompositionDlg)
	m_cstrAlbum = _T("");
	m_cstrMisc = _T("");
	m_cstrMusician = _T("");
	m_cstrTitle = _T("");
	m_cstrYear = _T("");
	//}}AFX_DATA_INIT
}


void CCompositionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCompositionDlg)
	DDX_Text(pDX, IDC_EDIT_Album, m_cstrAlbum);
	DDX_Text(pDX, IDC_EDIT_Misc, m_cstrMisc);
	DDX_Text(pDX, IDC_EDIT_Musician, m_cstrMusician);
	DDX_Text(pDX, IDC_EDIT_Title, m_cstrTitle);
	DDX_Text(pDX, IDC_EDIT_Year, m_cstrYear);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCompositionDlg, CDialog)
	//{{AFX_MSG_MAP(CCompositionDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CCompositionDlg 

void CCompositionDlg::SetComposition(CString cstrComposition)
{
	if ( cstrComposition != "" )
	{
		m_cstrMusician = cstrComposition.SpanExcluding("|");
		cstrComposition = cstrComposition.Mid(m_cstrMusician.GetLength() + 1);
	}
	if ( cstrComposition != "" )
	{
		m_cstrAlbum = cstrComposition.SpanExcluding("|");
		cstrComposition = cstrComposition.Mid(m_cstrAlbum.GetLength() + 1);
	}
	if ( cstrComposition != "" )
	{
		m_cstrTitle = cstrComposition.SpanExcluding("|");
		cstrComposition = cstrComposition.Mid(m_cstrTitle.GetLength() + 1);
	}
	if ( cstrComposition != "" )
	{
		m_cstrYear = cstrComposition.SpanExcluding("|");
		cstrComposition = cstrComposition.Mid(m_cstrYear.GetLength() + 1);
	}
	if ( cstrComposition != "" )
		m_cstrMisc = cstrComposition.SpanExcluding("|");

	// Trim strings
	m_cstrMusician.TrimLeft();
	m_cstrAlbum.TrimLeft();
	m_cstrTitle.TrimLeft();
	m_cstrYear.TrimLeft();
	m_cstrMisc.TrimLeft();
	m_cstrMusician.TrimRight();
	m_cstrAlbum.TrimRight();
	m_cstrTitle.TrimRight();
	m_cstrYear.TrimRight();
	m_cstrMisc.TrimRight();
}



CString CCompositionDlg::GetComposition() const
{
	if ( (m_cstrMusician == "" ) &&
		 (m_cstrAlbum == "" ) &&
		 (m_cstrTitle == "" ) &&
		 (m_cstrYear == "" ) &&
		 (m_cstrMisc == "" ) )
		return "";
	else
		return m_cstrMusician + "|" + m_cstrAlbum + "|" + m_cstrTitle + "|" + m_cstrYear + "|" + m_cstrMisc;
}



void CCompositionDlg::OnOK() 
{
	// Retrieve Data
	UpdateData(TRUE);

	// Trim strings
	m_cstrMusician.TrimLeft();
	m_cstrAlbum.TrimLeft();
	m_cstrTitle.TrimLeft();
	m_cstrYear.TrimLeft();
	m_cstrMisc.TrimLeft();
	m_cstrMusician.TrimRight();
	m_cstrAlbum.TrimRight();
	m_cstrTitle.TrimRight();
	m_cstrYear.TrimRight();
	m_cstrMisc.TrimRight();

	// Find fields which contain "|"
	CString	cstrBuggyFields;

	if ( m_cstrMusician.Find("|") >= 0 )
		cstrBuggyFields += "\r\n\tMusician or Band";
	if ( m_cstrAlbum.Find("|") >= 0 )
		cstrBuggyFields += "\r\n\tAlbum";
	if ( m_cstrTitle.Find("|") >= 0 )
		cstrBuggyFields += "\r\n\tTitle";
	if ( m_cstrYear.Find("|") >= 0 )
		cstrBuggyFields += "\r\n\tYear";
	if ( m_cstrMisc.Find("|") >= 0 )
		cstrBuggyFields += "\r\n\tMisc";

	if ( cstrBuggyFields != "" )
	{
		AfxMessageBox("Error: The following fields contain the character '|' which is not allowed:\r\n" + cstrBuggyFields);
		return;
	}

	CDialog::OnOK();
}
