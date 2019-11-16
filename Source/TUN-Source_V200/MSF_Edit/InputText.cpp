// InputText.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "MSF_Edit.h"
#include "InputText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CInputText 


CInputText::CInputText(CWnd* pParent /*=NULL*/)
	: CDialog(CInputText::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputText)
	m_cstrInput = _T("");
	m_cstrDescription = _T("");
	//}}AFX_DATA_INIT
}


void CInputText::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputText)
	DDX_Text(pDX, IDC_EDIT_INPUT, m_cstrInput);
	DDX_Text(pDX, IDC_STATIC_Description, m_cstrDescription);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputText, CDialog)
	//{{AFX_MSG_MAP(CInputText)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CInputText 
