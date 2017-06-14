// KalkulatorDlg.cpp : implementation file
//

#include "stdafx.h" 
#include "Kalkulator.h"
#include "KalkulatorDlg.h"
#include "Onp.h"

using namespace std;

/* deklaracja zmiennych globalnych */
CString wyrazenie;///< przechowuje aktualne wyra¿enie arytmetyczne do obliczenia
CString wyrazenie_onp;///< przechowuje aktualne wyra¿enie w ONP
CString wynik;///< przechowuje ³añcuch zawieraj¹cy wynik obliczeñ wyra¿enia
double d_wynik;///< przechowuje numeryczny wynik obliczenia wyra¿e

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CKalkulatorDlg dialog




CKalkulatorDlg::CKalkulatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKalkulatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKalkulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON3, b_ln);
	DDX_Control(pDX, IDC_BUTTON4, b_pn);
	DDX_Control(pDX, IDC_BUTTON5, b_PI);
	DDX_Control(pDX, IDC_BUTTON6, b_e);
	DDX_Control(pDX, IDC_BUTTON2, b_C);
	DDX_Control(pDX, IDC_BUTTON1, b_CE);
	DDX_Control(pDX, IDC_BUTTON7, b_1);
	DDX_Control(pDX, IDC_BUTTON8, b_2);
	DDX_Control(pDX, IDC_BUTTON9, b_3);
	DDX_Control(pDX, IDC_BUTTON10, b_4);
	DDX_Control(pDX, IDC_BUTTON11, b_5);
	DDX_Control(pDX, IDC_BUTTON12, b_6);
	DDX_Control(pDX, IDC_BUTTON13, b_7);
	DDX_Control(pDX, IDC_BUTTON14, b_8);
	DDX_Control(pDX, IDC_BUTTON15, b_9);
	DDX_Control(pDX, IDC_BUTTON16, b_pm);
	DDX_Control(pDX, IDC_BUTTON17, b_0);
	DDX_Control(pDX, IDC_BUTTON18, b_kropka);
	DDX_Control(pDX, IDC_BUTTON19, b_plus);
	DDX_Control(pDX, IDC_BUTTON20, b_minus);
	DDX_Control(pDX, IDC_BUTTON21, b_razy);
	DDX_Control(pDX, IDC_BUTTON22, b_dziel);
	DDX_Control(pDX, IDC_BUTTON23, b_potega);
	DDX_Control(pDX, IDC_BUTTON24, b_pierwiastek);
	DDX_Control(pDX, IDC_BUTTON25, b_exp);
	DDX_Control(pDX, IDC_BUTTON26, b_logn);
	DDX_Control(pDX, IDC_BUTTON27, b_sin);
	DDX_Control(pDX, IDC_BUTTON28, b_cos);
	DDX_Control(pDX, IDC_BUTTON29, b_tan);
	DDX_Control(pDX, IDC_BUTTON30, b_ctg);
	DDX_Control(pDX, IDC_BUTTON31, b_oblicz);
	DDX_Control(pDX, IDC_EDIT1, edit_onp);
	DDX_Control(pDX, IDC_EDIT2, edit_wynik);
	DDX_Control(pDX, IDC_EDIT3, edit_infix);
}

BEGIN_MESSAGE_MAP(CKalkulatorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON7, &CKalkulatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CKalkulatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CKalkulatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CKalkulatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CKalkulatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CKalkulatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CKalkulatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CKalkulatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CKalkulatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CKalkulatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CKalkulatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CKalkulatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CKalkulatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CKalkulatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CKalkulatorDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CKalkulatorDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CKalkulatorDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CKalkulatorDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CKalkulatorDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CKalkulatorDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CKalkulatorDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CKalkulatorDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CKalkulatorDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON16, &CKalkulatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON1, &CKalkulatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CKalkulatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CKalkulatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CKalkulatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CKalkulatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON31, &CKalkulatorDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON6, &CKalkulatorDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CKalkulatorDlg message handlers

BOOL CKalkulatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	edit_infix.SetFocus();
	//Make sure this is here so you can use XP Styles
	InitCommonControls(); // potrzebne do wygl¹du a'la xp


	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CKalkulatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

BOOL CKalkulatorDlg::PreTranslateMessage(MSG* pMsg)

{
	int x = pMsg->wParam;
	if(pMsg->message == WM_KEYDOWN) // jezeli wcisnieto klawisz
	{
		edit_infix.SetFocus(); // ustaw aktywny wyswietlacz
		if(x == VK_RETURN) // jezeli byl to ENTER
		{
			OnBnClickedButton31(); // zasymuluj wcisniecie =
			pMsg->wParam = 0; // wyzeruj komunikat aby nie mial dalszych skutkow
		}
		if(x == VK_DELETE) // jezeli byl to DELETE
		{
			OnBnClickedButton1(); // zasymuluj wcisniecie =
			pMsg->wParam = 0; // wyzeruj komunikat aby nie mial dalszych skutkow
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKalkulatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKalkulatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/** 
* Do³¹cza podany tekst do wyra¿enia i wyœwietla go w odpowiedniej kontrolce.
* @param *tekst ³añcuch do do³¹czenia
*/
void CKalkulatorDlg::dopiszTekst(char *tekst)
{
	CString bufor;
	edit_infix.GetWindowTextA(bufor); 
	wyrazenie.Empty(); 
	wyrazenie.Append(bufor); 
	wyrazenie.Append(tekst); 
	edit_infix.SetWindowTextA(wyrazenie); 
	this->przesunKursor();
}

/** 
* Przenosi kuror na koniec kontrolki wyra¿enia.
*/
void CKalkulatorDlg::przesunKursor()
{
	CString bufor;
	edit_infix.GetWindowTextA(bufor);
	edit_infix.SetSel(bufor.GetLength(),bufor.GetLength(),0); // ustawienie pozycji kursora na koniec
	edit_infix.SetFocus();
}
/**
* Obs³uga przycisku "1"
*/
void CKalkulatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("1");
}
/**
* Obs³uga przycisku "2"
*/
void CKalkulatorDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("2");
}
/**
* Obs³uga przycisku "3"
*/
void CKalkulatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("3");
}
/**
* Obs³uga przycisku "4"
*/
void CKalkulatorDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("4");
}
/**
* Obs³uga przycisku "5"
*/
void CKalkulatorDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("5");
}
/**
* Obs³uga przycisku "6"
*/
void CKalkulatorDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("6");
}
/**
* Obs³uga przycisku "7"
*/
void CKalkulatorDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("7");
}
/**
* Obs³uga przycisku "8"
*/
void CKalkulatorDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("8");
}
/**
* Obs³uga przycisku "9"
*/
void CKalkulatorDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("9");
}
/**
* Obs³uga przycisku "0"
*/
void CKalkulatorDlg::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("0");
}
/**
* Obs³uga przycisku "."
*/
void CKalkulatorDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst(".");
}
/**
* Obs³uga przycisku "+"
*/
void CKalkulatorDlg::OnBnClickedButton19()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("+");
}
/**
* Obs³uga przycisku "-"
*/
void CKalkulatorDlg::OnBnClickedButton20()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("-");
}
/**
* Obs³uga przycisku "*"
*/
void CKalkulatorDlg::OnBnClickedButton21()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("*");
}
/**
* Obs³uga przycisku "/"
*/
void CKalkulatorDlg::OnBnClickedButton22()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("/");
}
/**
* Obs³uga przycisku "^"
*/
void CKalkulatorDlg::OnBnClickedButton23()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("^");
}
/**
* Obs³uga przycisku "sqrt"
*/
void CKalkulatorDlg::OnBnClickedButton24()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("sqrt(");
}
/**
* Obs³uga przycisku "exp"
*/
void CKalkulatorDlg::OnBnClickedButton25()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("exp(");
}
/**
* Obs³uga przycisku "ln"
*/
void CKalkulatorDlg::OnBnClickedButton26()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("ln(");
}
/**
* Obs³uga przycisku "sin"
*/
void CKalkulatorDlg::OnBnClickedButton27()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("sin(");
}
/**
* Obs³uga przycisku "cos"
*/
void CKalkulatorDlg::OnBnClickedButton28()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("cos(");
}
/**
* Obs³uga przycisku "tan"
*/
void CKalkulatorDlg::OnBnClickedButton29()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("tan(");
}
/**
* Obs³uga przycisku "ctg"
*/
void CKalkulatorDlg::OnBnClickedButton30()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("ctg(");
}
/**
* Obs³uga przycisku "log"
*/
void CKalkulatorDlg::OnBnClickedButton16()
{
	this->dopiszTekst("log(");
}
/**
* Obs³uga przycisku "CE"
*/
void CKalkulatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	wyrazenie.Empty(); // czyscimy wyrazenie
	wyrazenie_onp.Empty(); // czyscimy wyrazenie ONP
	wynik.Empty();
	edit_onp.SetWindowTextA("");
	edit_infix.SetWindowTextA("");
	edit_wynik.SetWindowTextA("");
}
/**
* Obs³uga przycisku "("
*/
void CKalkulatorDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("(");
}
/**
* Obs³uga przycisku ")"
*/
void CKalkulatorDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst(")");
}
/**
* Obs³uga przycisku "C"
*/
void CKalkulatorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	wyrazenie = wyrazenie.Mid(0,wyrazenie.GetLength()-1);
	edit_infix.SetWindowTextA(wyrazenie);
	this->przesunKursor();
}
/**
* Obs³uga przycisku "PI"
*/
void CKalkulatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("3.14159265");
	
}
/**
* Obs³uga przycisku "="
*/
void CKalkulatorDlg::OnBnClickedButton31()
{
	// TODO: Add your control notification handler code here
	CString bufor;
	edit_infix.GetWindowTextA(bufor);
	wyrazenie = bufor;
	string wyrazenie_s;
	string s;
	vector <string> v1;

	char buf[256];
	wyrazenie_s = wyrazenie;
	COnp onp(wyrazenie_s);
	onp.stworzWyrazenieOnp();
	v1 = onp.pobierzWyrazenieONP();
	for(int i = 0; i < v1.size(); i++)
		s += v1[i] += " ";
	edit_onp.SetWindowTextA(s.c_str());
	d_wynik = onp.obliczWyrazenie();

	sprintf(buf,"%.5f",d_wynik);
	edit_wynik.SetWindowTextA(buf);

}
/**
* Obs³uga przycisku "e"
*/
void CKalkulatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	this->dopiszTekst("2.71828183");
	
}
