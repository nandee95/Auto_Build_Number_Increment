<h1>Description:</h1>
This script generates a header file contains the recent build build number as a macro. This is a platform and compiler independent solution The code also contains basic error checking and provides feedback at the build console.

**Files will be uploaded later**

<h1>Supported languages</h1>
<table>
	<thead>
		<tr>
			<td colspan=2><b>Language</b></td>
			<td><b>Header extension</b></td>
			<td><b>Default header filename</b></td>
		</tr>
	</thead>
	<tr><td>C</td><td>C</td><td>h</td><td>build_number.h</td></tr>
	<tr><td>C++</td><td>CXX</td><td>hpp</td><td>build_number.hpp</td></tr>
</table>
/Pull requests for extending the language support are welcome/

<h1>Basic usage:</h1>
<i>Using the default values...
Note that the following is a minimal C/C++ example. You can find more complete examples in the examples directory.</i>
<h2>1. Setting up CMake</h2>
Copy build_number.cmake to your source directory and add this code to your CMakeLists.txt
(don't forget to specify the target)
<pre>add_custom_command(
	TARGET project_name_goes_here
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND}
		-DSOURCE_DIR:PATH="${CMAKE_SOURCE_DIR}"
		-DFILES_DIR:PATH="${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}"
		-P "${CMAKE_SOURCE_DIR}/build_number.cmake"
)</pre>
Add build_number.h to your target. And create a blank build_number.h in your source directory otherwise CMake wont configure.
<h2>2. Adding build number to the project</h2>
Include the generated header in your source:
<pre>#include "build_number.h"</pre>
Use the BUILD_NUMBER macro in your code.
<h1>Altering default values</h1>
<h2>Possible inputs</h2>
<b>Values:</b>
<table>
	<thead>
		<tr>
		<td><b>Name</b></td><td><b>Type</b></td><td><b>Required</b></td><td><b>Default value</b></td><td><b>Description</b></td>
		</tr>
	</thead>
	<tr><td>HEADER_DIR</td><td>PATH</td><td><b>Yes</b></td><td>-</td><td>Specifies a path for the header.</td></tr>
	<tr><td>HEADER_FILENAME</td><td>STRING</td><td>No</td><td>buildnumber</td><td>Alters the default filename for the header.<br>The extension depends on the detected language. No extension needed here.</td></tr>
	<tr><td>HEADER_MACRO</td><td>STRING</td><td>No</td><td>BUILD_NUMBER</td><td>Alters the default macro's name in the header.</td></tr>
	<tr><td>CACHE_DIR</td><td>PATH</td><td><b>Yes</b></td><td>-</td><td>Specifies the path for the cache file.</td></tr>
	<tr><td>CACHE_FILENAME</td><td>STRING</td><td>No</td><td>CMakeBuildNumber.txt</td><td>Alters the default filename for the cache file.</td></tr>
</table>

<h2>Altering values</h2>
<b>Warning:</b> -P always have to be on the last place!

You can define them by adding more parameters to the command. For more information check the documentation of <a href="https://cmake.org/cmake/help/v3.2/command/add_custom_command.html">add_custom_command</a>.
The following is an example where all of the possible parameters are defined/altered:
<pre>add_custom_command(
	TARGET project_name_goes_here
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND}
		-DHEADER_DIR:PATH="${CMAKE_SOURCE_DIR}/Build"
		-DCACHE_DIR:PATH="${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/Caches"
		-DHEADER_FILENAME:STRING="BuildNo"
		-DCACHE_FILENAME:STRING="BuildNo.cache"
		-DHEADER_MACRO:STRING="BUILDNO"
		-P "${CMAKE_SOURCE_DIR}/build_number.cmake"
)</pre>

<h1>License</h1>
<i>MIT license</i>
