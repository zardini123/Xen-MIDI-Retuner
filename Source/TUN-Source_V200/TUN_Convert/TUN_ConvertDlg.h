// TUNConvertDlg.h : Header-Datei
//

#if !defined(AFX_CONVERTTUNDLG_H__B61580FC_2CFF_480D_9E2F_771EC18468ED__INCLUDED_)
#define AFX_CONVERTTUNDLG_H__B61580FC_2CFF_480D_9E2F_771EC18468ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000





#include <string>

#include "..\TUN_V2_Src\TUN_EmbedHTML.h"
#include "..\TUN_V2_Src\SCL_Import.h"





/////////////////////////////////////////////////////////////////////////////
// CTUNConvertDlg Dialogfeld

class CTUNConvertDlg : public CDialog
{
// Konstruktion
public:
	CTUNConvertDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CTUNConvertDlg)
	enum { IDD = IDD_TUN_CONVERT_DIALOG };
	CListBox	m_ctrl_list_Files;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CTUNConvertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CTUNConvertDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButtonV000();
	afx_msg void OnButtonV100();
	afx_msg void OnButtonV200();
	afx_msg void OnButtonHtml();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


	// Detect file type by extension
	enum eFileType
	{
		FT_TUN,
		FT_SCL,
		FT_KBM
	};
	eFileType	DetectFileType(std::string strFilePath);

	void		AddListEntry(std::string strFilePath);

	bool		AskForOverwriteOK();

	bool		ShowError(CString cstrFile, const TUN::CErr & Err);

	bool		ExportFiles(long lVersionFrom, long lVersionTo, bool bIsHTML);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_CONVERTTUNDLG_H__B61580FC_2CFF_480D_9E2F_771EC18468ED__INCLUDED_)
