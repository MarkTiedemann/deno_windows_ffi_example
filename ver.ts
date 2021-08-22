const dll = Deno.dlopen("ver.dll", {
	CurrentMajorVersionNumber: { parameters: [], result: "u32" },
	CurrentMinorVersionNumber: { parameters: [], result: "u32" },
	CurrentBuildNumber: { parameters: [], result: "u32" },
	UpdateBuildRevision: { parameters: [], result: "u32" },
});
const { CurrentMajorVersionNumber, CurrentMinorVersionNumber, CurrentBuildNumber, UpdateBuildRevision } = dll.symbols;
console.log(`\nMicrosoft Windows [Version ${CurrentMajorVersionNumber()}.${CurrentMinorVersionNumber()}.${CurrentBuildNumber()}.${UpdateBuildRevision()}]`);
