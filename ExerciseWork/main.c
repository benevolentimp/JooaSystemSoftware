/**
 * @file main.c
 * @author Jooa Jaakkola (@benevolentimp)
 * @brief Main-file from which every implementation should be called from.
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <windows.h>
#include "wndProcedure.h"

const char g_szClassName[] = "myWindowClass";

/* SPECIAL MAIN-FUNCTION FOR WIN32_API-LIBRARY:
hInstance => Handle to programs executable module; .exe in memory.
hPrevIntance => Always NULL for Win32-programs.
LPSTR || char* lpCmdLine => CL-arguments as a single string; not including program-name.
nCmdShow => An integer value that can be passed to e.g. ShowWindow()-method 
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char *lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    // Register "Window-class" & define local variables etc.
    // Essentially define each field of a 'WNDCLASSEX'-object
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) // Check if stuff above succeeded
    {
        MessageBox(NULL, "Window registration failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Creating the window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Hello, World!",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 420, 420,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) // Check if stuff above succeeded
    {
        MessageBox(NULL, "Window creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Message-loop
    while (GetMessage(&Msg, NULL, 0 ,0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}