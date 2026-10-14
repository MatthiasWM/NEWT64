# Tests

`ctest` in a CMake build directory runs every `*.newt` script here, and those in
`ext/` when the extensions are built. Each script reports a failed check with a
line starting `FAIL` and prints `ALL OK` at its end. newt64 exits with status 0
even after an uncaught exception, so a test passes only if `ALL OK` appears.
Scripts that write files put them in `$NEWT64_TEST_TMP` (the build directory
under ctest), or in the current directory if it is not set.

Run one script by hand from this directory:

    NEWTLIB=../build newt64 smoke.newt
