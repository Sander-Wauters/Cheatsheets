#pragma once
#pragma comment(lib, "comctl32.lib")
#include "BaseWindow.h"
#include <CommCtrl.h>


class MainWindow : public BaseWindow<MainWindow>
{
public:
	PCWSTR  ClassName() const { return L"MainWindowClass"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	BOOL CreateStatusBar(
		PCWSTR lpWindowName,		 // Window name
		DWORD dwStyle,				 // Window style
		HWND hWndParent = 0,		 // Handle to parent
		HMENU hMenu = 0				 // Handle to menu
	);

private:
	HWND m_hwndStatusBar;
};
