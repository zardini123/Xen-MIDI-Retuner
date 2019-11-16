#if !defined(AFX_COMPOSITIONDLG_H__FD501951_9C57_4883_90E9_B33FE845558D__INCLUDED_)
#define AFX_COMPOSITIONDLG_H__FD501951_9C57_4883_90E9_B33FE845558D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CompositionDlg.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CCompositionDlg 

class CCompositionDlg : public CDialog
{
// Konstruktion
public:
	CCompositionDlg(CWnd* pParent = NULL);   // Standardkonstruktor

	void	SetComposition(CString cstrComposition);
	CString	GetComposition() const;

// Dialogfelddaten
	//{{AFX_DATA(CCompositionDlg)
	enum { IDD = IDD_COMPOSITION_DIALOG };
	CString	m_cstrAlbum;
	CString	m_cstrMisc;
	CString	m_cstrMusician;
	CString	m_cstrTitle;
	CString	m_cstrYear;
	//}}AFX_DATA


// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CCompositionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CCompositionDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // AFX_COMPOSITIONDLG_H__FD501951_9C57_4883_90E9_B33FE845558D__INCLUDED_
