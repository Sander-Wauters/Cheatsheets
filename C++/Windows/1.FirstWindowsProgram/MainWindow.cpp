#include "MainWindow.h"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	return 0;

	case WM_CREATE:
	{
		// Create the status bar
		if (!CreateStatusBar((PCWSTR)NULL, SBARS_SIZEGRIP | WS_CHILD | WS_VISIBLE, m_hwnd))
			PostQuitMessage(1);
	}
	return 0;

	case WM_SIZE:
	{
		// Resize the status bar
		SendMessage(m_hwndStatusBar, WM_SIZE, 0, 0);
	}
	return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(m_hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		TextOut(hdc, 0, 0, L"Test", 4);
		TextOut(hdc, 0, 25, L"Test", 4);
		EndPaint(m_hwnd, &ps);
	}
	return 0;

	default:
		return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
	}
	return TRUE;
}

BOOL MainWindow::CreateStatusBar(PCWSTR lpWindowName, DWORD dwStyle, HWND hWndParent, HMENU hMenu)
{
	// Ensure that the common control DLL is loaded.
	tagINITCOMMONCONTROLSEX initCtrls;
	initCtrls.dwSize = sizeof(initCtrls);
	initCtrls.dwICC = ICC_BAR_CLASSES;
	InitCommonControlsEx(&initCtrls);

	// Create the status bar
	m_hwndStatusBar = CreateWindowEx(
		0, STATUSCLASSNAME, lpWindowName, dwStyle,
		0, 0, 0, 0, hWndParent, hMenu, GetModuleHandle(NULL), 0
	);

	return (m_hwndStatusBar ? TRUE : FALSE);
}
