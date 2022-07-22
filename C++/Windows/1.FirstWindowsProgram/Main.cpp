#ifndef UNICODE
#define UNICODE
#endif

#include "MainWindow.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR lpCmdLine, _In_ int nCmdShow)
{
	// Create the main window
	MainWindow mainWin;
	if (!mainWin.Create(L"WindowTest", WS_OVERLAPPEDWINDOW))
		return 0;

	ShowWindow(mainWin.Window(), nCmdShow);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
