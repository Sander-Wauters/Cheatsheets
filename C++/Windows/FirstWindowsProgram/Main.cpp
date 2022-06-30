#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include <new> // std::nothrow

struct StateInfo{}; // Structure to hold state information

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR lpCmdLine, _In_ int nCmdShow)
{
	// Register window class
	const wchar_t CLASS_NAME[] = L"MainWindow";

	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	// Set StateInfo structure
	StateInfo* pState = new (std::nothrow) StateInfo; // std::nothrow returns a NULL pointer instead of exeption on failure

	if (pState == NULL)
		return 0;

	pState = {};

	// Create the window
	const wchar_t WINDOW_NAME[] = L"WindowTest";

	HWND hwnd = CreateWindowEx(
		0,						// Optional window styles
		CLASS_NAME,				// Window class
		WINDOW_NAME,			// Window text
		WS_OVERLAPPEDWINDOW,	// Window style
		CW_USEDEFAULT,			// Position X
		CW_USEDEFAULT,			// Position Y
		CW_USEDEFAULT,			// Width
		CW_USEDEFAULT,			// Height
		NULL,					// Handle to parent
		NULL,					// Menu
		hInstance,				// Instance handle
		pState					// Additional application data
	);

	if (hwnd == NULL) // Check if CreateWindowEx FAILED
		return 0;

	ShowWindow(hwnd, nCmdShow);

	// Run the message loop
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg); // Handles keyboard input
		DispatchMessage(&msg);  // Calls the window procedure
	}

	return 0;
}

inline StateInfo* GetAppState(HWND hwnd) // Get StateInfo back from window instace
{
	LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
	StateInfo* pState = reinterpret_cast<StateInfo*>(ptr);
	return pState;
}

LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	StateInfo* pState; // Set data structure
	if (uMsg == WM_CREATE) // WM_CREATE message is sent out before the window is visible. Good place for initialization
	{
		CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam); // CREATESTRUCT.lpCreateParams is the void pointer specified in CreateWindowEx
		pState = reinterpret_cast<StateInfo*>(pCreate->lpCreateParams); // Get pointer to own data structure by casting CREATESTRUCT.lpCreateParams
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pState); // Store the StateInfo pointer in the instance data for the window
	}
	else
		pState = GetAppState(hwnd); // Get StateInfo back from window instace

	// Handle window messages
	switch (uMsg)
	{
	case WM_CLOSE: // Prompt user to confirm closing the window
		if (MessageBox(hwnd, L"Quit?", L"WindowTest", MB_OKCANCEL) == IDOK)
			DestroyWindow(hwnd);
		return 0;

	case WM_DESTROY: // Destroys window
		PostQuitMessage(0); // Puts WM_QUIT on the message queue, causing GetMessage to return 0
		return 0;

	case WM_PAINT: // "Paints" the client area
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		// Painting occurs between BeginPaint and EndPaint

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
	return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam); // Preforms default action for unhandled messages
}
