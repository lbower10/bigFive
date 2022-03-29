##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab4
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/bower/OneDrive/Documents/c1020a01Lab4
ProjectPath            :=C:/Users/bower/OneDrive/Documents/c1020a01Lab4/Lab4
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab4
OutDir                 :=../build-$(ConfigurationName)/Lab4
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=bower
Date                   :=11/03/2022
CodeLitePath           :=C:/CodeLite
LinkerName             :=C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/ar.exe rcu
CXX      := C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/g++.exe
CC       := C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\CodeLite
Objects0=../build-$(ConfigurationName)/Lab4/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab4/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab4" mkdir "..\build-$(ConfigurationName)\Lab4"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab4" mkdir "..\build-$(ConfigurationName)\Lab4"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab4/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab4" mkdir "..\build-$(ConfigurationName)\Lab4"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab4/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Lab4/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/bower/OneDrive/Documents/c1020a01Lab4/Lab4/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab4/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab4/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab4/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Lab4/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab4/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(ObjectSuffix): big5Assessment.cpp ../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/bower/OneDrive/Documents/c1020a01Lab4/Lab4/big5Assessment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/big5Assessment.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(DependSuffix): big5Assessment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(DependSuffix) -MM big5Assessment.cpp

../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(PreprocessSuffix): big5Assessment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab4/big5Assessment.cpp$(PreprocessSuffix) big5Assessment.cpp


-include ../build-$(ConfigurationName)/Lab4//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


