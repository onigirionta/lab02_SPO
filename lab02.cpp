#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

#define BUFF_SIZE 1024

int main() {

  DWORD bufSize = BUFF_SIZE;

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
  GetSystemDirectory(sysInfBuf, BUFF_SIZE);
  printf("System directory: %s\n", sysInfBuf);

  // getting computer name
  TCHAR compNameBuf[BUFF_SIZE];
  bufSize = BUFF_SIZE;
  GetComputerName(compNameBuf, &bufSize);
  printf("Computer name: %s\n", compNameBuf);

  // getting user name
  // returns null o_o
  TCHAR userNameBuf[BUFF_SIZE];
  bufSize = BUFF_SIZE;
  BOOL res = GetUserName(userNameBuf, &bufSize);
  if (!res) {
    DWORD dwError = GetLastError();
    printf("Error: %d\n", dwError);
  }
  printf("User name: %s\n", userNameBuf);

  // first volume
  // returns null o_o
  TCHAR firstVolumeName[BUFF_SIZE];
  bufSize = BUFF_SIZE;
  HANDLE vhandle = FindFirstVolume(firstVolumeName, bufSize);
  printf("First volume: %s\n", firstVolumeName);

  return 0;
}