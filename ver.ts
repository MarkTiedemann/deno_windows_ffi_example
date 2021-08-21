const dll = Deno.dlopen("ver.dll", {
	CurrentMajorVersionNumber: { parameters: [], result: "i32" },
	CurrentMinorVersionNumber: { parameters: [], result: "i32" },
	CurrentBuildNumber: { parameters: [], result: "i32" },
	UpdateBuildRevision: { parameters: [], result: "i32" },
});
const { CurrentMajorVersionNumber, CurrentMinorVersionNumber, CurrentBuildNumber, UpdateBuildRevision } = dll.symbols;
console.log(`\nMicrosoft Windows [Version ${CurrentMajorVersionNumber()}.${CurrentMinorVersionNumber()}.${CurrentBuildNumber()}.${UpdateBuildRevision()}]`);
