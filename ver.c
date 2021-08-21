#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>

int CurrentMajorVersionNumber(void) {
	DWORD val;
	DWORD valSize = sizeof(val);
	RegGetValueA(
		HKEY_LOCAL_MACHINE,
		"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
		"CurrentMajorVersionNumber",
		RRF_RT_REG_DWORD,
		NULL,
		&val,
		&valSize
	);
	return val;
}

int CurrentMinorVersionNumber(void) {
	DWORD val;
	DWORD valSize = sizeof(val);
	RegGetValueA(
		HKEY_LOCAL_MACHINE,
		"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
		"CurrentMinorVersionNumber",
		RRF_RT_REG_DWORD,
		NULL,
		&val,
		&valSize
	);
	return val;
}

int CurrentBuildNumber(void) {
	CHAR buf[8];
	DWORD bufSize = sizeof(buf);
	RegGetValueA(
		HKEY_LOCAL_MACHINE,
		"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
		"CurrentBuildNumber",
		RRF_RT_REG_SZ,
		NULL,
		&buf,
		&bufSize
	);
	return atoi(buf);
}

int UpdateBuildRevision(void) {
	DWORD val;
	DWORD valSize = sizeof(val);
	RegGetValueA(
		HKEY_LOCAL_MACHINE,
		"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
		"UBR",
		RRF_RT_REG_DWORD,
		NULL,
		&val,
		&valSize
	);
	return val;
}
