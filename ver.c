#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>

DWORD CurrentMajorVersionNumber(VOID) {
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

DWORD CurrentMinorVersionNumber(VOID) {
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

DWORD CurrentBuildNumber(VOID) {
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

DWORD UpdateBuildRevision(VOID) {
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
