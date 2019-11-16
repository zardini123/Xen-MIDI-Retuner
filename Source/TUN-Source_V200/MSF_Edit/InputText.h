#if !defined(AFX_INPUTTEXT_H__9F6B50C0_A793_4526_AB4B_E874E4B1699D__INCLUDED_)
#define AFX_INPUTTEXT_H__9F6B50C0_A793_4526_AB4B_E874E4B1699D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputText.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CInputText 

class CInputText : public CDialog
{
// Konstruktion
public:
	CInputText(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CInputText)
	enum { IDD = IDD_INPUT_TEXT_DLG };
	CString	m_cstrInput;
	CString	m_cstrDescription;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CInputText)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CInputText)
		// HINWEIS: Der Klassen-Assistent fügt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_INPUTTEXT_H__9F6B50C0_A793_4526_AB4B_E874E4B1699D__INCLUDED_
