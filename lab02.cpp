#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main() {

  DWORD bufSize = 2048;

  // info about OS version
  DWORD dwVersion = GetVersion();

  // debag
  // cout << hex <<dwVersion << endl;

  DWORD dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
  DWORD dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
  DWORD dwBuild = (DWORD)(HIWORD(dwVersion));

  printf("Major version: %d\nRevision: %d\nBuild: %d\n", dwMajorVersion, dwMinorVersion, dwBuild);

  // getting system directory
  LPSTR sysInfBuf;
  GetSystemDirectory(sysInfBuf, bufSize);
  printf("System directory: %s\n", sysInfBuf);

  // getting computer name
  LPSTR compNameBuf;
  GetComputerName(compNameBuf, &bufSize);
  printf("Computer name: %s\n", compNameBuf);

  // getting user name
  LPSTR userNameBuf;
  GetUserName(userNameBuf, &bufSize);
  printf("User name: %s\n", userNameBuf);
  return 0;
}