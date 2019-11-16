// MSF_EditDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "MSF_Edit.h"
#include "MSF_EditDlg.h"
#include "InputText.h"

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
// CMSF_EditDlg Dialogfeld

CMSF_EditDlg::CMSF_EditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMSF_EditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMSF_EditDlg)
		// HINWEIS: Der Klassenassistent fügt hier Member-Initialisierung ein
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMSF_EditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMSF_EditDlg)
	DDX_Control(pDX, IDC_LIST_Scales, m_ctrl_listbox_Scales);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMSF_EditDlg, CDialog)
	//{{AFX_MSG_MAP(CMSF_EditDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OpenMSF, OnBUTTONOpenMSF)
	ON_BN_CLICKED(IDC_BUTTON_AddScale, OnBUTTONAddScale)
	ON_BN_CLICKED(IDC_BUTTON_ExportScale, OnBUTTONExportScale)
	ON_BN_CLICKED(IDC_BUTTON_SaveMSF, OnBUTTONSaveMSF)
	ON_BN_CLICKED(IDC_BUTTON_EditScale, OnBUTTONEditScale)
	ON_WM_VKEYTOITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSF_EditDlg Nachrichten-Handler

BOOL CMSF_EditDlg::OnInitDialog()
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

void CMSF_EditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMSF_EditDlg::OnPaint() 
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
HCURSOR CMSF_EditDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CMSF_EditDlg::OnBUTTONOpenMSF() 
{
	// Ask for file name
	CFileDialog	dlgOpen(TRUE, NULL, NULL, OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
					"AnaMark multiple scale files (*.msf)|*.msf|All files (*.*)|*.*||", this);

	if ( dlgOpen.DoModal() != IDOK )
		return;

	if ( m_ctrl_listbox_Scales.GetCount() > 0 )
	{
		int	nAnswer = AfxMessageBox("The list already contains scale data. Data from MSF file is appended to the list. Do you wish to clear the list before opening the file?", MB_YESNOCANCEL | MB_DEFBUTTON3);
		switch ( nAnswer )
		{
		case IDYES:
			m_MSF.m_lssScales.clear();
		case IDNO:
			break;
		default:
			return;
		}
	}

	// Read the file
	CString	cstrFile = dlgOpen.GetPathName();
	if ( !m_MSF.Add((LPCTSTR)cstrFile) )
	{
		AfxMessageBox(("An error occured when processing file\r\n\r\n" + cstrFile + "\r\n\r\n") + m_MSF.Err().GetLastError().c_str());
		return;
	}

	RefreshList();
}



void CMSF_EditDlg::OnBUTTONAddScale() 
{
	// Ask for file name
	CFileDialog	dlgOpen(TRUE, NULL, NULL, OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
						"Supported tuning files (*.tun;*.tun.*)|*.tun;*.tun.*|AnaMark tuning files (*.tun)|(*.tun)|AnaMark embedded tuning files (*.tun.*)|*.tun.*|All files (*.*)|*.*||", this);

	if ( dlgOpen.DoModal() != IDOK )
		return;

	// Read the file
	CString	cstrFile = dlgOpen.GetPathName();
	TUN::CSingleScale	ss;
	if ( !ss.Read((LPCTSTR)cstrFile) )
	{
		AfxMessageBox(("An error occured when processing file\r\n\r\n" + cstrFile + "\r\n\r\n") + ss.Err().GetLastError().c_str());
		return;
	}
	if ( ss.m_strName.empty() )
		ss.m_strName = (LPCTSTR)cstrFile;

	// Add file to end of MSF
	m_MSF.m_lssScales.push_back(ss);

	RefreshList();

	// Select added file
	m_ctrl_listbox_Scales.SetCurSel(m_ctrl_listbox_Scales.GetCount()-1);
	OnBUTTONEditScale();
}



void CMSF_EditDlg::OnBUTTONEditScale() 
{
	TUN::CSingleScale	* pssCurr = FindSelectedScale();
	if ( pssCurr == NULL )
		return;

	CInputText	dlgName;
	dlgName.m_cstrDescription = "Scale name:";
	dlgName.m_cstrInput = pssCurr->m_strName.c_str();
	if ( dlgName.DoModal() )
	{
		pssCurr->m_strName = dlgName.m_cstrInput;
		if ( pssCurr->m_strName.empty() )
			pssCurr->m_strName = "UNNAMED";
	}

	std::string	strMIDIChannelsAssignment = pssCurr->GetMIDIChannelsAssignment();
	while ( true )
	{
		CInputText	dlgAssignment;
		dlgAssignment.m_cstrDescription = "MIDI channels assignment\r\n(Format: '#' for a single channel or '#-#' for a range. Separate multiple assignments by a ','. The '#' denotes a MIDI channel number. An empty strings means 'All channels'.)";
		dlgAssignment.m_cstrInput = strMIDIChannelsAssignment.c_str();
		if ( !dlgAssignment.DoModal() )
			break;
		strMIDIChannelsAssignment = dlgAssignment.m_cstrInput;
		TUN::CSingleScale	ssTemp;
		if ( !ssTemp.SetMIDIChannelsAssignment(strMIDIChannelsAssignment) )
			AfxMessageBox("Syntax error in MIDI channels assignment.");
		else
		{
			pssCurr->SetMIDIChannelsAssignment(strMIDIChannelsAssignment);
			break;
		}
	}

	RefreshList();
}



void CMSF_EditDlg::OnBUTTONExportScale() 
{
	TUN::CSingleScale	* pssCurr = FindSelectedScale();
	if ( pssCurr == NULL )
		return;

	// Ask for file name
	CFileDialog	dlg(FALSE, ".tun", NULL, OFN_EXPLORER | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
					"AnaMark tuning files (*.tun)|*.tun|All files (*.*)|*.*||", this);

	if ( dlg.DoModal() != IDOK )
		return;

	// Save data
	if ( !pssCurr->Write((LPCTSTR)dlg.GetPathName()) )
		AfxMessageBox(("An error occured while writing the file:\r\n" + pssCurr->Err().GetLastError()).c_str());
}



void CMSF_EditDlg::OnBUTTONSaveMSF() 
{
	// Ask for file name
	CFileDialog	dlg(FALSE, ".msf", NULL, OFN_EXPLORER | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
					"AnaMark multiple scale files (*.msf)|*.msf|All files (*.*)|*.*||", this);

	if ( dlg.DoModal() != IDOK )
		return;

	// Save data
	if ( !m_MSF.Write((LPCTSTR)dlg.GetPathName()) )
		AfxMessageBox(("An error occured while writing the file:\r\n" + m_MSF.Err().GetLastError()).c_str());
}



void CMSF_EditDlg::OnCancel() 
{
	CDialog::OnCancel();
}



void CMSF_EditDlg::RefreshList()
{
	int	nIndex = m_ctrl_listbox_Scales.GetCurSel();

	m_ctrl_listbox_Scales.ResetContent();

	std::list<TUN::CSingleScale>::const_iterator	it;
	for ( it = m_MSF.m_lssScales.begin() ; it != m_MSF.m_lssScales.end() ; ++it )
	{
		std::string	strMIDIChannels = it->GetMIDIChannelsAssignment();
		// If no MIDI Channel is specified, the scale is applied to ALL MIDI channels
		if ( strMIDIChannels == "" )
			strMIDIChannels = "ALL";

		m_ctrl_listbox_Scales.AddString((strMIDIChannels + "\t" + it->m_strName).c_str());
	}

	if ( nIndex >= m_ctrl_listbox_Scales.GetCount() )
		nIndex = m_ctrl_listbox_Scales.GetCount() - 1;
	if ( nIndex < 0 )
		nIndex = 0;
	m_ctrl_listbox_Scales.SetCurSel(nIndex);
}



TUN::CSingleScale * CMSF_EditDlg::FindSelectedScale()
{
	int	nIndex = m_ctrl_listbox_Scales.GetCurSel();
	if ( (nIndex < 0) || (nIndex == LB_ERR) )
		return NULL;

	std::list<TUN::CSingleScale>::iterator	it = m_MSF.m_lssScales.begin();
	while ( nIndex-- > 0 )
		++it;

	return &(*it);

}




int CMSF_EditDlg::OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex) 
{
	if ( pListBox == &m_ctrl_listbox_Scales )
	{
		TUN::CSingleScale	* pssCurr = FindSelectedScale();
		if ( pssCurr == NULL )
			return -1; // CListBox performs default action

		std::list<TUN::CSingleScale>::iterator	it = m_MSF.m_lssScales.begin();
		std::list<TUN::CSingleScale>::iterator	itPrev = it;
		while ( &(*it) != pssCurr )
			itPrev = it++;

		switch ( nKey )
		{
		case VK_UP:
			if ( GetKeyState(VK_CONTROL) < 0 )
			{
				if ( it != m_MSF.m_lssScales.begin() )
				{
					std::swap(*it, *itPrev);
					m_ctrl_listbox_Scales.SetCurSel(m_ctrl_listbox_Scales.GetCurSel()-1);
					RefreshList();
				}
				return -2; // All action done here; No action of CListBox required
			}
			break;
		case VK_DOWN:
			if ( GetKeyState(VK_CONTROL) < 0 )
			{
				std::list<TUN::CSingleScale>::iterator	itNext = it;
				if ( ++itNext != m_MSF.m_lssScales.end() )
				{
					std::swap(*it, *itNext);
					m_ctrl_listbox_Scales.SetCurSel(m_ctrl_listbox_Scales.GetCurSel()+1);
					RefreshList();
				}
				return -2; // All action done here; No action of CListBox required
			}
			break;
		case VK_DELETE:
			if ( GetKeyState(VK_CONTROL) < 0 )
			{
				m_MSF.m_lssScales.erase(it);
				RefreshList();
				return -2; // All action done here; No action of CListBox required
			}
			break;
		}
	}

	return CDialog::OnVKeyToItem(nKey, pListBox, nIndex);
}
