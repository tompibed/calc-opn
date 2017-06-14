// KalkulatorDlg.h : header file
//
 
#pragma once
#include "afxwin.h"
#include "Onp.h"

using namespace std;

/** 
* Klasa g³ównego okna dialogowego, dziedziczy po klasie CDialog.
*/

// CKalkulatorDlg dialog
class CKalkulatorDlg : public CDialog
{
// Construction
public:
	CKalkulatorDlg(CWnd* pParent = NULL);	// standard constructor


// Dialog Data
	enum { IDD = IDD_KALKULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	void dopiszTekst(char *tekst);
	void przesunKursor();
	BOOL PreTranslateMessage(MSG* pMsg);



// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton b_ln;
	CButton b_pn;
	CButton b_PI;
	CButton b_e;
	CButton b_C;
	CButton b_CE;
	CButton b_1;
	CButton b_2;
	CButton b_3;
	CButton b_4;
	CButton b_5;
	CButton b_6;
	CButton b_7;
	CButton b_8;
	CButton b_9;
	CButton b_pm;
	CButton b_0;
	CButton b_kropka;
	CButton b_plus;
	CButton b_minus;
	CButton b_razy;
	CButton b_dziel;
	CButton b_potega;
	CButton b_pierwiastek;
	CButton b_exp;
	CButton b_logn;
	CButton b_sin;
	CButton b_cos;
	CButton b_tan;
	CButton b_ctg;
	CButton b_oblicz;
	CEdit edit_onp;
	CEdit edit_wynik;
	CEdit edit_infix;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnBnClickedButton6();
};
