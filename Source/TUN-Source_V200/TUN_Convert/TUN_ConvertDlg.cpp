// TUNConvertDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "TUN_Convert.h"
#include "TUN_ConvertDlg.h"

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
// CTUNConvertDlg Dialogfeld

CTUNConvertDlg::CTUNConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTUNConvertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTUNConvertDlg)
		// HINWEIS: Der Klassenassistent fügt hier Member-Initialisierung ein
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTUNConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTUNConvertDlg)
	DDX_Control(pDX, IDC_LIST_Files, m_ctrl_list_Files);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTUNConvertDlg, CDialog)
	//{{AFX_MSG_MAP(CTUNConvertDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_V000, OnButtonV000)
	ON_BN_CLICKED(IDC_BUTTON_V100, OnButtonV100)
	ON_BN_CLICKED(IDC_BUTTON_V200, OnButtonV200)
	ON_BN_CLICKED(IDC_BUTTON_HTML, OnButtonHtml)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTUNConvertDlg Nachrichten-Handler

BOOL CTUNConvertDlg::OnInitDialog()
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

void CTUNConvertDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTUNConvertDlg::OnPaint() 
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
HCURSOR CTUNConvertDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CTUNConvertDlg::OnOK() 
{
	// Add files
    CFileDialog     dlg(TRUE, NULL, NULL,
                        OFN_ALLOWMULTISELECT | OFN_EXPLORER |
                        OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
                        "Supported tuning files (*.scl;*.tun;*.tun.*)|*.scl;*.tun;*.tun.*|"
						"AnaMark tuning files (*.tun)|(*.tun)|"
						"AnaMark embedded tuning files (*.tun.*)|*.tun.*|"
						"Scala files (*.scl)|(*.scl)|"
						"All files (*.*)|*.*||");

    char            * szBuffer = new char[100000];
    if ( szBuffer == NULL )
    {
        AfxMessageBox("Out of memory!", MB_OK | MB_ICONSTOP);
        return;
    }
    lstrcpy(szBuffer, "");
    dlg.m_ofn.lpstrFile = szBuffer;
    dlg.m_ofn.nMaxFile = 100000;

    if ( dlg.DoModal() != IDOK )
    {
        delete [] szBuffer;
        return;
    }

	// Add selected files to list box control
	std::string	strScalaKBM;
    bool		bIsMultiSelect = false;
    char		* szBuffPtr = szBuffer;

    while ( (*(szBuffPtr = szBuffPtr + lstrlen(szBuffPtr) + 1) != '\0') ||
			(!bIsMultiSelect) )
    {
		// Make Filename
		std::string	strFilePath = szBuffer; // FilePath (SingleSelect) or Path (Multiselect)
		if ( *szBuffPtr != '\0' )
		{	// MultiSelect
	        bIsMultiSelect = true;
	        strFilePath += "\\";
		    strFilePath += szBuffPtr; // FilePath
		}

		// Get file type
		switch ( DetectFileType(strFilePath) )
		{
		case FT_KBM:
			break; // Ignore KBM-files here
		case FT_SCL:
			if ( strScalaKBM.empty() )
			{
				// Ask for scala keyboard mapping
				CFileDialog     dlg(TRUE, NULL, NULL,
									OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
									"Scala keyboard mapping (*.kbm)|*.kbm|All files (*.*)|*.*||");
				if ( dlg.DoModal() )
					strScalaKBM = (LPCTSTR)dlg.GetPathName();

				strScalaKBM = "\t" + strScalaKBM;
			}
			AddListEntry(strFilePath);
			AddListEntry(strScalaKBM);
			break;
		case FT_TUN:
			AddListEntry(strFilePath);
			break;
		default:
			assert(false);
		}

		// Leave loop here in case of SingleSelect
		if ( !bIsMultiSelect )
			break;
    }

	// Free memory
    delete [] szBuffer;
}



void CTUNConvertDlg::OnButtonV000() 
{
	ExportFiles(0, 0, false);
}



void CTUNConvertDlg::OnButtonV100() 
{
	ExportFiles(0, 100, false);
}



void CTUNConvertDlg::OnButtonV200() 
{
	ExportFiles(100, 200, false);
}



void CTUNConvertDlg::OnButtonHtml() 
{
	ExportFiles(100, 200, true);
}



void CTUNConvertDlg::OnCancel() 
{
	// In case you want to write a list of the supported tokens for
	// embedding a TUN dataset into HTML:
//	TUN::WriteListOfSupportedTokens(std::string("c:\\ListOfTokens.txt"));
	
	CDialog::OnCancel();
}



CTUNConvertDlg::eFileType CTUNConvertDlg::DetectFileType(std::string strFilePath)
{
	std::string				strFileTitle = strFilePath.substr(("\\" + strFilePath).find_last_of("/\\"));
	std::string::size_type	posExt = strFileTitle.rfind('.');;
	std::string				strExt = ( posExt == std::string::npos ? "" : strFileTitle.substr(posExt+1) );
	for ( std::string::size_type i = 0 ; i < strExt.size() ; ++i )
		strExt.at(i) = static_cast<char>(tolower(strExt.at(i)));

	if ( strExt == "scl" )
		return FT_SCL;
	if ( strExt == "kbm" )
		return FT_KBM;
	return FT_TUN;
}



void CTUNConvertDlg::AddListEntry(std::string strFilePath)
{
	CDC			* pCDC = m_ctrl_list_Files.GetDC();
	int			nHorizontalExtent = m_ctrl_list_Files.GetHorizontalExtent();
	int			nCurrentStringWidth;

	// Add file to list
	m_ctrl_list_Files.AddString(strFilePath.c_str());
	// Get string extent
	nCurrentStringWidth = (pCDC->GetTextExtent(strFilePath.c_str(), strFilePath.size())).cx + 20;
	if ( nCurrentStringWidth > nHorizontalExtent )
		// Increase horizontal scroll width of list box
		m_ctrl_list_Files.SetHorizontalExtent(nCurrentStringWidth);
}



bool CTUNConvertDlg::AskForOverwriteOK()
{
	int	nAnswer = AfxMessageBox("ATTENTION: Conversion works IN-PLACE, which means that the selected files are overwritten. There is also NO CHECK to protect existing files for being overwritten in the case the file extension changes.\r\n\r\nTHE SAFEST WAY IS TO WORK ON COPIES OF YOUR FILES RESIDING IN AN OWN FOLDER!\r\n\r\nContinue?", MB_YESNO | MB_DEFBUTTON2);
	return (nAnswer == IDYES);
}



bool CTUNConvertDlg::ShowError(CString cstrFile, const TUN::CErr & Err)
{
	AfxMessageBox(((LPCTSTR)("An error occured when processing file\r\n\r\n"
							 + cstrFile + "\r\n\r\n")
				   + Err.GetLastError()
				  ).c_str(),
				  MB_OK | MB_ICONSTOP);
	return false;
}



bool CTUNConvertDlg::ExportFiles(long lVersionFrom, long lVersionTo, bool bIsHTML)
{
	if ( !AskForOverwriteOK() )
		return false;


	// HTML template file, if necessary
	bool		bHasHTMLTemplateFile = false;
	std::string	strHTMLTemplate;
	if ( bIsHTML )
	{
		// Ask for Template file
		CFileDialog	dlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
						"HTML template file (*.html)|*.html|All Files (*.*)|*.*||", this);

		if ( dlg.DoModal() != IDOK )
			return false;

		strHTMLTemplate = (LPCTSTR)dlg.GetPathName();
	}

	TUN::CEmbedHTML	embed(strHTMLTemplate, bHasHTMLTemplateFile);


	// Process file list entries
    while( m_ctrl_list_Files.GetCount() != 0 )
	{
		CString	cstrInFile;
		CString	cstrOutFile;
		m_ctrl_list_Files.GetText(0, cstrInFile);
		m_ctrl_list_Files.DeleteString(0);
		cstrOutFile = cstrInFile;

		// ensure extension
		if ( cstrOutFile.Right(5) == ".html" )
			cstrOutFile = cstrOutFile.Left(cstrOutFile.GetLength() - 5);
		if ( cstrOutFile.Right(4) == ".scl" )
			cstrOutFile = cstrOutFile.Left(cstrOutFile.GetLength() - 4);
		if ( cstrOutFile.Right(4) != ".tun" )
			cstrOutFile += ".tun";
		if ( bIsHTML )
		{
			if ( cstrOutFile.Right(5) != ".html" )
				cstrOutFile += ".html";
		}

		// read data
		TUN::CSingleScale	ss;
		if ( DetectFileType((LPCTSTR)cstrInFile) == FT_SCL )
		{
			// Scala file -> next file list entry defines KBM file
			CString	cstrKBMFile;
			m_ctrl_list_Files.GetText(0, cstrKBMFile);
			m_ctrl_list_Files.DeleteString(0);
			assert ( cstrKBMFile.Left(1) == "\t" );
			cstrKBMFile = cstrKBMFile.Mid(1);
			// Read scala file data
			TUN::CSCL_Import scl;
			if ( cstrKBMFile != "" )
			{
				if ( !scl.ReadKBM((LPCTSTR)cstrKBMFile) )
					return ShowError(cstrKBMFile, scl.Err());
			}
			if ( !scl.ReadSCL((LPCTSTR)cstrInFile) )
				return ShowError(cstrInFile, scl.Err());
			scl.SetSingleScale(ss);
		}
		else
		{
			// AnaMark tuning file format
			if ( !ss.Read((LPCTSTR)cstrInFile) )
				return ShowError(cstrInFile, ss.Err());
		}

		// write data
		if ( bIsHTML )
		{
			if ( !embed.WriteFile(LPCTSTR(cstrInFile), LPCTSTR(cstrOutFile), 100, 200) )
				return ShowError(cstrOutFile, embed.Err());
		}
		else
		{
			if ( !ss.Write(LPCTSTR(cstrOutFile), lVersionFrom, lVersionTo) )
				return ShowError(cstrOutFile, ss.Err());
		}
	}

	AfxMessageBox("Done.");
	return true;
}

