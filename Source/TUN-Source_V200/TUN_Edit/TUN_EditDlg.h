// TUN_EditDlg.h : Header-Datei
//

#if !defined(AFX_TUN_EDITDLG_H__F838657F_2A14_4297_B87F_ECD404C53C89__INCLUDED_)
#define AFX_TUN_EDITDLG_H__F838657F_2A14_4297_B87F_ECD404C53C89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTUN_EditDlg Dialogfeld

class CTUN_EditDlg : public CDialog
{
// Konstruktion
public:
	CTUN_EditDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

	const char *	EditorName() const { return "MH_TUN_Edit";}
	bool			SetDataToSingleScale();

// Dialogfelddaten
	//{{AFX_DATA(CTUN_EditDlg)
	enum { IDD = IDD_TUN_EDIT_DIALOG };
	CListBox	m_ctrl_listbox_Compositions;
	CListBox	m_ctrl_listbox_Keywords;
	CString	m_cstrInfoName;
	CString	m_cstrInfoID;
	CString	m_cstrInfoFilename;
	CString	m_cstrInfoAuthor;
	CString	m_cstrInfoLocation;
	CString	m_cstrInfoContact;
	CString	m_cstrInfoDate;
	CString	m_cstrInfoDescription;
	CString	m_cstrInfoHistory;
	CString	m_cstrInfoGeography;
	CString	m_cstrInfoInstrument;
	CString	m_cstrInfoComments;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CTUN_EditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CTUN_EditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONOpen();
	afx_msg void OnBUTTONSaveHTML();
	afx_msg void OnBUTTONSaveTUN();
	virtual void OnCancel();
	afx_msg int OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString				m_cstrOpenFile;
	TUN::CSingleScale	m_ss;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_TUN_EDITDLG_H__F838657F_2A14_4297_B87F_ECD404C53C89__INCLUDED_)
