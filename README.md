# RTXNGIN
## About
RTXNGIN, pronounced `RTX engine` or `Raytracing engine` is a small game engine I'm developing, which I plan on making for the purpose of bringing raytracing to low-end computers.
## Building
In order to build, you'll need CMake, and OpenCL SDK. You can obtain the OpenCL SDK from [here](https://github.com/KhronosGroup/OpenCL-SDK).
After you have the requirements, you can run CMake with the following parameters:
```
-DOpenCL_INCLUDE_DIR=<OPENCL_SDK_INCLUDE_PATH> -DOpenCL_LIBRARY=<OPENCL_SDK_LIBRARY>
```
In my case (I'm on Windows 11), I set them to:

```-DOpenCL_INCLUDE_DIR=C:/Program Files/OpenCL-SDK-v2023.12.14-Win-x64/include -DOpenCL_LIBRARY="C:/Program Files/OpenCL-SDK-v2023.12.14-Win-x64/lib/OpenCL.lib"
```