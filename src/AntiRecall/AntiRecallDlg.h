/* 
 * Copyright (c) [2019] zhenfei.mzf@gmail.com rights reserved.
 * 
 * DTAssist is licensed under the Mulan PSL v1.
 * You can use this software according to the terms and conditions of the Mulan PSL v1.
 * You may obtain a copy of Mulan PSL v1 at:
 *
 *     http://license.coscl.org.cn/MulanPSL
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR
 * FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v1 for more details.
*/

// AntiRecallDlg.h : header file
//

#pragma once

#define WM_UPDATE_MESSAGE (WM_USER + 200)

// CAntiRecallDlg dialog
class CAntiRecallDlg : public CDialog
{
// Construction
public:
	CAntiRecallDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ANTIRECALL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	int GetSoftWareInstallPath();
	int GetFileCurrentVersion(CString path);
	int UpdateMainFramePath();
	BOOL IsAlreadyPatched(); 
	void CheckPatchStatusAndBackup();
	void CheckPatchStatus();
	void CheckBackup();
	void EnumDingTalkProcess();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnUpdateMessage(WPARAM wParam, LPARAM lParam); 
	DECLARE_MESSAGE_MAP()
public:
	bool mRadioDingtalk;
	CString mAppPath;
	CString mCurrentVersion;

	CString mMainFramePath;
	CString mNewMainFramePath;
	CString mPatchStatus;
	afx_msg void OnBnClickedBtnBrowseApp();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnRevert();
	afx_msg void OnStnClickedStaticGithub();

private:
	CRect m_Rect;
	CFont* m_cfNtr;
	CFont m_cfUL;
	LOGFONT m_lfNtr, m_lfUL;
	COLORREF m_color;
	CBrush m_brush;
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
