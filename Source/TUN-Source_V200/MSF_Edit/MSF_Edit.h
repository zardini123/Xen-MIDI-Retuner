// MSF_Edit.h : Haupt-Header-Datei f�r die Anwendung MSF_EDIT
//

#if !defined(AFX_MSF_EDIT_H__E03BE5D1_30F5_4BD4_AB22_479D4807DA53__INCLUDED_)
#define AFX_MSF_EDIT_H__E03BE5D1_30F5_4BD4_AB22_479D4807DA53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

#include "..\TUN_V2_Src\TUN_MultiScaleFile.h"

/////////////////////////////////////////////////////////////////////////////
// CMSF_EditApp:
// Siehe MSF_Edit.cpp f�r die Implementierung dieser Klasse
//

class CMSF_EditApp : public CWinApp
{
public:
	CMSF_EditApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMSF_EditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CMSF_EditApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_MSF_EDIT_H__E03BE5D1_30F5_4BD4_AB22_479D4807DA53__INCLUDED_)
