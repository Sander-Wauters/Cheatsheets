#pragma once
#include <Windows.h>

/*
BaseWindow is an abstract class from which specific window classes are derived.
For example:

class MainWindow : public BaseWindow<MainWindow>
{
public:
	PCWSTR  ClassName() const { return L"Sample Window Class"; };
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

The BaseWindow::HandleMessage is used to implement the window procedure.
For example:

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(m_hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
		EndPaint(m_hwnd, &ps);
	}
	return 0;

	default:
		return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
	}
	return TRUE;
}
*/

template <class DERIVED_TYPE>
class BaseWindow
{
public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		DERIVED_TYPE* pThis = NULL; // Declare pointer to the derived class

		if (uMsg == WM_NCCREATE) // Gets called when window is created
		{
			CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam; // Extract the paramaters passed to CreateWindowEx()
			pThis = (DERIVED_TYPE*)pCreate->lpCreateParams; // Set the DERIVED_TYPE pointer to the LPVOID pointer given in CreateWindowEx() 
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis); // Store the DERIVED_TYPE pointer in the window instance data
			pThis->m_hwnd = hwnd;
		}
		else // Gets called after window is created
			pThis = (DERIVED_TYPE*)GetWindowLongPtr(hwnd, GWLP_USERDATA); // Get the pointer stored by SetWindowLongPtr()

		if (pThis)
			return pThis->HandleMessage(uMsg, wParam, lParam); // Used as window procedure
		else
			return DefWindowProc(hwnd, uMsg, wParam, lParam); // Preforms default action for unhandled messages
	};

	BaseWindow() :
		m_hwnd(NULL) {}

	// Create the window
	BOOL Create(
		PCWSTR lpWindowName,		 // Window name
		DWORD dwStyle,				 // Window style
		DWORD dwExStyle = 0,		 // Optional window styles
		int x = CW_USEDEFAULT,		 // Position X
		int y = CW_USEDEFAULT,		 // Position Y
		int nWidth = CW_USEDEFAULT,  // Window width
		int nHeight = CW_USEDEFAULT, // Window height 
		HWND hWndParent = 0,		 // Handle to parent
		HMENU hMenu = 0				 // Handle to menu
	)
	{
		// Register window class
		WNDCLASS wc = { 0 };
		wc.lpfnWndProc = DERIVED_TYPE::WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = ClassName();

		RegisterClass(&wc);

		// Create the window
		m_hwnd = CreateWindowEx(
			dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,
			nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this
		);

		return (m_hwnd ? TRUE : FALSE); // Return true if CreateWindowEx SUCCEEDED
	}

	HWND Window() const { return m_hwnd; } // Return window handle

protected:
	virtual PCWSTR ClassName() const = 0; // Set lpszClassName, see example above
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0; // Window procedure

	HWND m_hwnd;
};