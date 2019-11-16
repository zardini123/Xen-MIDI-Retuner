// TUN_EditDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "TUN_Edit.h"
#include "TUN_EditDlg.h"
#include "KeywordDlg.h"
#include "CompositionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTUN_EditDlg Dialogfeld

CTUN_EditDlg::CTUN_EditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTUN_EditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTUN_EditDlg)
	m_cstrInfoFilename = _T("");
	m_cstrInfoID = _T("");
	m_cstrInfoName = _T("");
	m_cstrInfoAuthor = _T("");
	m_cstrInfoLocation = _T("");
	m_cstrInfoContact = _T("");
	m_cstrInfoDate = _T("");
	m_cstrInfoDescription = _T("");
	m_cstrInfoHistory = _T("");
	m_cstrInfoGeography = _T("");
	m_cstrInfoInstrument = _T("");
	m_cstrInfoComments = _T("");
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTUN_EditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTUN_EditDlg)
	DDX_Control(pDX, IDC_LIST_Compositions, m_ctrl_listbox_Compositions);
	DDX_Control(pDX, IDC_LIST_Keywords, m_ctrl_listbox_Keywords);
	DDX_Text(pDX, IDC_EDIT_Info_Filename, m_cstrInfoFilename);
	DDX_Text(pDX, IDC_EDIT_Info_ID, m_cstrInfoID);
	DDX_Text(pDX, IDC_EDIT_Info_Name, m_cstrInfoName);
	DDX_Text(pDX, IDC_EDIT_Info_Author, m_cstrInfoAuthor);
	DDX_Text(pDX, IDC_EDIT_Info_Location, m_cstrInfoLocation);
	DDX_Text(pDX, IDC_EDIT_Info_Contact, m_cstrInfoContact);
	DDX_Text(pDX, IDC_EDIT_Info_Date, m_cstrInfoDate);
	DDX_Text(pDX, IDC_EDIT_Info_Description, m_cstrInfoDescription);
	DDX_Text(pDX, IDC_EDIT_Info_History, m_cstrInfoHistory);
	DDX_Text(pDX, IDC_EDIT_Info_Geography, m_cstrInfoGeography);
	DDX_Text(pDX, IDC_EDIT_Info_Instrument, m_cstrInfoInstrument);
	DDX_Text(pDX, IDC_EDIT_Info_Comments, m_cstrInfoComments);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTUN_EditDlg, CDialog)
	//{{AFX_MSG_MAP(CTUN_EditDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Open, OnBUTTONOpen)
	ON_BN_CLICKED(IDC_BUTTON_SaveHTML, OnBUTTONSaveHTML)
	ON_BN_CLICKED(IDC_BUTTON_SaveTUN, OnBUTTONSaveTUN)
	ON_WM_VKEYTOITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTUN_EditDlg Nachrichten-Handler

BOOL CTUN_EditDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{	
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	// ZU ERLEDIGEN: Hier zusätzliche Initialisierung einfügen
	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CTUN_EditDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void CTUN_EditDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CTUN_EditDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



bool CTUN_EditDlg::SetDataToSingleScale()
{
	// Retrieve data from dialog
	UpdateData(TRUE);

	// Set editor
	m_ss.m_strEditor = EditorName();
	m_ss.m_strEditorSpecs = ""; // There is no editor specific data, thus there are no specs necessary!

	// Check ID for spaces and first character
	if ( m_cstrInfoID.FindOneOf("\t\n\v\f\r ") >= 0 )
	{
		AfxMessageBox("The ID must not contain space characters!");
		return false;
	}
	if ( (m_cstrInfoID.GetAt(0) == '_') ||
		 ((m_cstrInfoID.GetAt(0) >= 'a') && (m_cstrInfoID.GetAt(0) <= 'z')) ||
		 ((m_cstrInfoID.GetAt(0) >= 'A') && (m_cstrInfoID.GetAt(0) <= 'Z')) )
		 ;
	else
	{
		AfxMessageBox("The ID must begin with a character (a-z) or an underscore ('_')!");
		return false;
	}

	// Set the single-field values
	m_ss.m_strName = (LPCTSTR)m_cstrInfoName;
	m_ss.m_strID = (LPCTSTR)m_cstrInfoID;
	m_ss.m_strFilename = (LPCTSTR)m_cstrInfoFilename;
	m_ss.m_strAuthor = (LPCTSTR)m_cstrInfoAuthor;
	m_ss.m_strLocation = (LPCTSTR)m_cstrInfoLocation;
	m_ss.m_strContact = (LPCTSTR)m_cstrInfoContact;
	if ( !m_ss.SetDate((LPCTSTR)m_cstrInfoDate) )
	{
		AfxMessageBox(m_ss.Err().GetLastError().c_str());
		return false;
	}
	m_ss.m_strDescription = (LPCTSTR)m_cstrInfoDescription;
	m_ss.m_strHistory = (LPCTSTR)m_cstrInfoHistory;
	m_ss.m_strGeography = (LPCTSTR)m_cstrInfoGeography;
	m_ss.m_strInstrument = (LPCTSTR)m_cstrInfoInstrument;
	m_ss.m_strComments = (LPCTSTR)m_cstrInfoComments;

	// Fill in the keywords
	m_ss.m_lstrKeywords.clear();
	for ( long l = 0 ; l < m_ctrl_listbox_Keywords.GetCount() ; ++l )
	{
		CString	cstr;
		m_ctrl_listbox_Keywords.GetText(l, cstr);
		m_ss.m_lstrKeywords.push_back(std::string((LPCTSTR)cstr));
	}

	// Fill in the compositions
	m_ss.m_lstrCompositions.clear();
	for ( l = 0 ; l < m_ctrl_listbox_Compositions.GetCount() ; ++l )
	{
		CString	cstr;
		m_ctrl_listbox_Compositions.GetText(l, cstr);
		m_ss.m_lstrCompositions.push_back(std::string((LPCTSTR)cstr));
	}

	// Everything O.K.
	return true;
}



void CTUN_EditDlg::OnBUTTONOpen() 
{
	// Ask for file name
	CFileDialog	dlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
					"Supported tuning files (*.tun;*.tun.*)|*.tun;*.tun.*|AnaMark tuning files (*.tun)|(*.tun)|AnaMark embedded tuning files (*.tun.*)|*.tun.*|All files (*.*)|*.*||", this);

	if ( dlg.DoModal() != IDOK )
		return;

	// Read the file
	m_cstrOpenFile = dlg.GetPathName();
	if ( !m_ss.Read((LPCTSTR)m_cstrOpenFile) )
	{
		AfxMessageBox(("An error occured when processing file\r\n\r\n" + m_cstrOpenFile + "\r\n\r\n") + m_ss.Err().GetLastError().c_str());
		return;
	}

	// Check for editor
	if ( (m_ss.m_strEditor != "") && (m_ss.m_strEditor != EditorName()) )
		AfxMessageBox("WARNING: The file was saved using another editor than TUN-Edit!\r\n\r\nThere might be editor specific settings which will be lost when the file ist saved by TUN-Edit!");

	// Fill in the single-field values
	m_cstrInfoName = m_ss.m_strName.c_str();
	m_cstrInfoID = m_ss.m_strID.c_str();
	m_cstrInfoFilename = m_ss.m_strFilename.c_str();
	m_cstrInfoAuthor = m_ss.m_strAuthor.c_str();
	m_cstrInfoLocation = m_ss.m_strLocation.c_str();
	m_cstrInfoContact = m_ss.m_strContact.c_str();
	m_cstrInfoDate = m_ss.GetDate().c_str();
	m_cstrInfoDescription = m_ss.m_strDescription.c_str();
	m_cstrInfoHistory = m_ss.m_strHistory.c_str();
	m_cstrInfoGeography = m_ss.m_strGeography.c_str();
	m_cstrInfoInstrument = m_ss.m_strInstrument.c_str();
	m_cstrInfoComments = m_ss.m_strComments.c_str();

	// Fill in the keywords
	std::list<std::string>::const_iterator	it;
	m_ctrl_listbox_Keywords.ResetContent();
	for ( it = m_ss.m_lstrKeywords.begin() ; it != m_ss.m_lstrKeywords.end() ; ++it )
		m_ctrl_listbox_Keywords.AddString(it->c_str());

	// Fill in the compositions
	m_ctrl_listbox_Compositions.ResetContent();
	for ( it = m_ss.m_lstrCompositions.begin() ; it != m_ss.m_lstrCompositions.end() ; ++it )
		m_ctrl_listbox_Compositions.AddString(it->c_str());

	// Show the changes
	UpdateData(FALSE);
}



void CTUN_EditDlg::OnBUTTONSaveHTML() 
{
	// Transfer data from dialog to CSingleScale
	if ( !SetDataToSingleScale() )
		return;

	// Ask for file name
	CFileDialog	dlg(FALSE, ".tun.html", NULL, OFN_EXPLORER | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
					"AnaMark embedded tuning files - HTML (*.tun.html)|.tun.html|All files (*.*)|*.*||", this);

	if ( dlg.DoModal() != IDOK )
		return;

	// Ask for Template file
	CFileDialog	dlgTemplate(TRUE, NULL, NULL, OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
							"HTML template file (*.html)|*.html|All Files (*.*)|*.*||", this);

	if ( dlgTemplate.DoModal() != IDOK )
		return;

	// Save embedded HTML:
	TUN::CEmbedHTML	embed(std::string(LPCTSTR(dlgTemplate.GetPathName())));

	if ( !embed.WriteFile(m_ss, LPCTSTR(dlg.GetPathName()), 100, 200) )
	{
		AfxMessageBox(("An error occured while writing the file:\r\n" + embed.Err().GetLastError()).c_str());
		return;
	}
}



void CTUN_EditDlg::OnBUTTONSaveTUN() 
{
	// Transfer data from dialog to CSingleScale
	if ( !SetDataToSingleScale() )
		return;

	// Ask for file name
	CFileDialog	dlg(FALSE, ".tun", NULL, OFN_EXPLORER | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
					"AnaMark tuning files (*.tun)|*.tun|All files (*.*)|*.*||", this);

	if ( dlg.DoModal() != IDOK )
		return;

	// Save data
	if ( !m_ss.Write((LPCTSTR)dlg.GetPathName()) )
		AfxMessageBox(("An error occured while writing the file:\r\n" + m_ss.Err().GetLastError()).c_str());
}



void CTUN_EditDlg::OnCancel() 
{
	if ( m_cstrOpenFile != "" )
	{
		int	nResponse = AfxMessageBox("Do you really want to exit?", MB_YESNO | MB_DEFBUTTON2);
		if ( nResponse != IDYES )
			return;
	}

	CDialog::OnCancel();
}



// Handle list box keyboard input
int CTUN_EditDlg::OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex) 
{
	switch ( nKey )
	{
	// Delete the currently selected item
	case VK_DELETE:
		pListBox->DeleteString(nIndex);
		pListBox->SetCurSel(nIndex);
		return -2;

	// Insert a new item
	case VK_INSERT:
		if ( pListBox == &m_ctrl_listbox_Keywords )
		{
			CKeywordDlg	dlg;
			if ( dlg.DoModal() != IDOK )
				return -2;
			if ( dlg.m_cstrKeyword != "" )
				pListBox->InsertString(nIndex, dlg.m_cstrKeyword);
		}
		else
		{
			CCompositionDlg	dlg;
			if ( dlg.DoModal() != IDOK )
				return -2;
			if ( dlg.GetComposition() != "" )
				pListBox->InsertString(nIndex, dlg.GetComposition());
		}
		pListBox->SetCurSel(nIndex);
		return -2;

	// Edit the currently selected item
	case VK_F2:
		if ( pListBox == &m_ctrl_listbox_Keywords )
		{
			CKeywordDlg	dlg;
			pListBox->GetText(nIndex, dlg.m_cstrKeyword);
			if ( dlg.DoModal() != IDOK )
				return -2;
			pListBox->DeleteString(nIndex);
			if ( dlg.m_cstrKeyword != "" )
				pListBox->InsertString(nIndex, dlg.m_cstrKeyword);
		}
		else
		{
			CCompositionDlg	dlg;
			CString	cstr;
			pListBox->GetText(nIndex, cstr);
			dlg.SetComposition(cstr);
			if ( dlg.DoModal() != IDOK )
				return -2;
			pListBox->DeleteString(nIndex);
			if ( dlg.GetComposition() != "" )
				pListBox->InsertString(nIndex, dlg.GetComposition());
		}
		pListBox->SetCurSel(nIndex);
		return -2;
	}

	return CDialog::OnVKeyToItem(nKey, pListBox, nIndex);
}
