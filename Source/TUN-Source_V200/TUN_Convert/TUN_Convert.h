// TUNConvert.h : Haupt-Header-Datei f�r die Anwendung CONVERTTUN
//

#if !defined(AFX_CONVERTTUN_H__C201AAFD_C9CB_4F74_BF48_982B69359666__INCLUDED_)
#define AFX_CONVERTTUN_H__C201AAFD_C9CB_4F74_BF48_982B69359666__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CTUNConvertApp:
// Siehe TUNConvert.cpp f�r die Implementierung dieser Klasse
//

class CTUNConvertApp : public CWinApp
{
public:
	CTUNConvertApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CTUNConvertApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CTUNConvertApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_CONVERTTUN_H__C201AAFD_C9CB_4F74_BF48_982B69359666__INCLUDED_)
