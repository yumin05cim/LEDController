# LEDController CMake config file
#
# This file sets the following variables:
# LEDController_FOUND - Always TRUE.
# LEDController_INCLUDE_DIRS - Directories containing the LEDController include files.
# LEDController_IDL_DIRS - Directories containing the LEDController IDL files.
# LEDController_LIBRARIES - Libraries needed to use LEDController.
# LEDController_DEFINITIONS - Compiler flags for LEDController.
# LEDController_VERSION - The version of LEDController found.
# LEDController_VERSION_MAJOR - The major version of LEDController found.
# LEDController_VERSION_MINOR - The minor version of LEDController found.
# LEDController_VERSION_REVISION - The revision version of LEDController found.
# LEDController_VERSION_CANDIDATE - The candidate version of LEDController found.

message(STATUS "Found LEDController-1.0.0")
set(LEDController_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(LEDController_INCLUDE_DIRS
#    "C:/Program Files (x86)/LEDController/include/ledcontroller-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(LEDController_IDL_DIRS
#    "C:/Program Files (x86)/LEDController/include/ledcontroller-1/idl")
set(LEDController_INCLUDE_DIRS
    "C:/Program Files (x86)/LEDController/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(LEDController_IDL_DIRS
    "C:/Program Files (x86)/LEDController/include//idl")


if(WIN32)
    set(LEDController_LIBRARIES
        "C:/Program Files (x86)/LEDController/components/lib/ledcontroller.lib"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(LEDController_LIBRARIES
        "C:/Program Files (x86)/LEDController/components/lib/ledcontroller.dll"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(LEDController_DEFINITIONS ${<dependency>_DEFINITIONS})

set(LEDController_VERSION 1.0.0)
set(LEDController_VERSION_MAJOR 1)
set(LEDController_VERSION_MINOR 0)
set(LEDController_VERSION_REVISION 0)
set(LEDController_VERSION_CANDIDATE )

