#if !defined(AFX_KEYWORDDLG_H__EF34DB18_439F_495C_A485_503218EE82C7__INCLUDED_)
#define AFX_KEYWORDDLG_H__EF34DB18_439F_495C_A485_503218EE82C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KeywordDlg.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CKeywordDlg 

class CKeywordDlg : public CDialog
{
// Konstruktion
public:
	CKeywordDlg(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CKeywordDlg)
	enum { IDD = IDD_KEYWORD_DIALOG };
	CString	m_cstrKeyword;
	//}}AFX_DATA


// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CKeywordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CKeywordDlg)
		// HINWEIS: Der Klassen-Assistent f�gt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // AFX_KEYWORDDLG_H__EF34DB18_439F_495C_A485_503218EE82C7__INCLUDED_
