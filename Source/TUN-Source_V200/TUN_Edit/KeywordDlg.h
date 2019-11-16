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


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CKeywordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CKeywordDlg)
		// HINWEIS: Der Klassen-Assistent fügt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_KEYWORDDLG_H__EF34DB18_439F_495C_A485_503218EE82C7__INCLUDED_
