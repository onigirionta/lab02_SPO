#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main() {

  // info about OS version
  DWORD dwVersion = GetVersion();

  // debag
  // cout << hex <<dwVersion << endl;

  DWORD dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
  DWORD dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
  DWORD dwBuild = (DWORD)(HIWORD(dwVersion));

  printf("Major version of system is %d, revision is %d and build is %d\n", dwMajorVersion, dwMinorVersion, dwBuild);

  // getting system directory
  LPSTR infoBuf;
  GetSystemDirectory(infoBuf, 32767);
  printf("System directory is %s\n", infoBuf);
  return 0;
}