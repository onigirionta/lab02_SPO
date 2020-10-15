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
  TCHAR sysInfBuf[BUFF_SIZE];
  GetSystemDirectory(sysInfBuf, BUFF_SIZE);
  printf("System directory: %s\n", sysInfBuf);

  // getting computer name
  TCHAR compNameBuf[BUFF_SIZE];
  bufSize = BUFF_SIZE;
  GetComputerName(compNameBuf, &bufSize);
  printf("Computer name: %s\n", compNameBuf);

  // getting user name
  TCHAR userNameBuf[BUFF_SIZE];
  bufSize = BUFF_SIZE;
  BOOL res = GetUserName(userNameBuf, &bufSize);
  printf("User name: %s\n", userNameBuf);

  printf("\nVOLUMES\n");
  // first volume
  TCHAR firstVolumeName[BUFF_SIZE];
  bufSize = BUFF_SIZE;
  PTCHAR Names = (PTCHAR) new BYTE [BUFF_SIZE * sizeof(TCHAR)];
  HANDLE prevHandle = FindFirstVolume(firstVolumeName, bufSize);
  bufSize = BUFF_SIZE;
  ULARGE_INTEGER lpFreeBytesAvailableToCaller = {.QuadPart=0};
  ULARGE_INTEGER lpTotalNumberOfBytes = {.QuadPart=0};
  ULARGE_INTEGER lpTotalNumberOfFreeBytes = {.QuadPart=0};
  GetVolumePathNamesForVolumeName(
            firstVolumeName, Names, bufSize, &bufSize
            );
  GetDiskFreeSpaceEx(
            firstVolumeName, &lpFreeBytesAvailableToCaller, &lpTotalNumberOfBytes, &lpTotalNumberOfFreeBytes
    );
  printf("First volume: %s\n", firstVolumeName);
  printf("Volume path names: %s\n", Names);
  printf("Total volume bytes: %u\n", lpTotalNumberOfBytes.QuadPart);
  printf("Bytes available for user: %u\n", lpFreeBytesAvailableToCaller.QuadPart);

  // next volumes
  PTCHAR nextNames = (PTCHAR) new BYTE [BUFF_SIZE * sizeof(TCHAR)];
  BOOL control_bool = true;
  TCHAR nextVolumeName[BUFF_SIZE];
  do {
    control_bool = FindNextVolume(prevHandle, nextVolumeName, BUFF_SIZE);
    bufSize = BUFF_SIZE;
    lpFreeBytesAvailableToCaller = {.QuadPart=0};
    lpTotalNumberOfBytes = {.QuadPart=0};
    lpTotalNumberOfFreeBytes = {.QuadPart=0};
    GetVolumePathNamesForVolumeName(
            firstVolumeName, Names, bufSize, &bufSize
            );
    GetDiskFreeSpaceEx(
            firstVolumeName, &lpFreeBytesAvailableToCaller, &lpTotalNumberOfBytes, &lpTotalNumberOfFreeBytes
      );
    if (control_bool) {
      printf("Next volume: %s\n", nextVolumeName);
      printf("Volume path names: %s\n", Names);
      printf("Total volume bytes: %u\n", lpTotalNumberOfBytes.QuadPart);
      printf("Bytes available for user: %u\n", lpFreeBytesAvailableToCaller.QuadPart);
    }
  } while (control_bool);

  return 0;
}