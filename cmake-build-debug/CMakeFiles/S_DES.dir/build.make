# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\S_DES.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\S_DES.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\S_DES.dir\flags.make

CMakeFiles\S_DES.dir\main.cpp.obj: CMakeFiles\S_DES.dir\flags.make
CMakeFiles\S_DES.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/S_DES.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\S_DES.dir\main.cpp.obj /FdCMakeFiles\S_DES.dir\ /FS -c "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\main.cpp"
<<

CMakeFiles\S_DES.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S_DES.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\S_DES.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\main.cpp"
<<

CMakeFiles\S_DES.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S_DES.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\S_DES.dir\main.cpp.s /c "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\main.cpp"
<<

# Object files for target S_DES
S_DES_OBJECTS = \
"CMakeFiles\S_DES.dir\main.cpp.obj"

# External object files for target S_DES
S_DES_EXTERNAL_OBJECTS =

S_DES.exe: CMakeFiles\S_DES.dir\main.cpp.obj
S_DES.exe: CMakeFiles\S_DES.dir\build.make
S_DES.exe: CMakeFiles\S_DES.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable S_DES.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\S_DES.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\S_DES.dir\objects1.rsp @<<
 /out:S_DES.exe /implib:S_DES.lib /pdb:"C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\cmake-build-debug\S_DES.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\S_DES.dir\build: S_DES.exe

.PHONY : CMakeFiles\S_DES.dir\build

CMakeFiles\S_DES.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\S_DES.dir\cmake_clean.cmake
.PHONY : CMakeFiles\S_DES.dir\clean

CMakeFiles\S_DES.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES" "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES" "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\cmake-build-debug" "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\cmake-build-debug" "C:\Users\beeta\OneDrive\UNIVERSITY STUFF\CS\Year 2\SEM 4\Information Security\ciphers\S-DES\cmake-build-debug\CMakeFiles\S_DES.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\S_DES.dir\depend

