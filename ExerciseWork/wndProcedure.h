/**
 * @file wndProcedure.h
 * @author Jooa Jaakkola (@benevolentimp)
 * @brief Header-file for aforementioned basic Win32-API -protocol.
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <windows.h> // For Win32-API specific keywords in function-prototype
#ifndef WNDPROCEDURE_H

#define WNDPROCEDURE_H
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif