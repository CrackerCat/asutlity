
// unittestDlg.h : ͷ�ļ�
//

#pragma once


// CunittestDlg �Ի���
class CunittestDlg : public CDialog
{
// ����
public:
	CunittestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_UNITTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnJson();
	afx_msg void OnBnClickedBtnXml();
	afx_msg void OnBnClickedBtnCurl();
	afx_msg void OnBnClickedBtnChart();
};
