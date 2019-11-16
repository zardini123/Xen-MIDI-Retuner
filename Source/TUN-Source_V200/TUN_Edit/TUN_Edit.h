// TUN_Edit.h : Haupt-Header-Datei f�r die Anwendung TUN_EDIT
//

#if !defined(AFX_TUN_EDIT_H__6C382916_3F17_46F7_853E_E391547B40A9__INCLUDED_)
#define AFX_TUN_EDIT_H__6C382916_3F17_46F7_853E_E391547B40A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

#include "..\TUN_V2_Src\TUN_EmbedHTML.h"

/////////////////////////////////////////////////////////////////////////////
// CTUN_EditApp:
// Siehe TUN_Edit.cpp f�r die Implementierung dieser Klasse
//

class CTUN_EditApp : public CWinApp
{
public:
	CTUN_EditApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CTUN_EditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CTUN_EditApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_TUN_EDIT_H__6C382916_3F17_46F7_853E_E391547B40A9__INCLUDED_)
