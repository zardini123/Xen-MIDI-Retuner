// MSF_EditDlg.h : Header-Datei
//

#if !defined(AFX_MSF_EDITDLG_H__130342B1_BF5C_461A_9EC6_4CA4A225889E__INCLUDED_)
#define AFX_MSF_EDITDLG_H__130342B1_BF5C_461A_9EC6_4CA4A225889E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000





/////////////////////////////////////////////////////////////////////////////
// CMSF_EditDlg Dialogfeld

class CMSF_EditDlg : public CDialog
{
// Konstruktion
public:
	CMSF_EditDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CMSF_EditDlg)
	enum { IDD = IDD_MSF_EDIT_DIALOG };
	CListBox	m_ctrl_listbox_Scales;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMSF_EditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CMSF_EditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONOpenMSF();
	afx_msg void OnBUTTONAddScale();
	afx_msg void OnBUTTONExportScale();
	afx_msg void OnBUTTONSaveMSF();
	virtual void OnCancel();
	afx_msg void OnBUTTONEditScale();
	afx_msg int OnVKeyToItem(UINT nKey, CListBox* pListBox, UINT nIndex);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void				RefreshList();
	TUN::CSingleScale *	FindSelectedScale();

	// Variables
	TUN::CMultiScaleFile	m_MSF;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_MSF_EDITDLG_H__130342B1_BF5C_461A_9EC6_4CA4A225889E__INCLUDED_)
