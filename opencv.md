
# OpenCV 환경 설정 (2018-08-19)

#### OpenCV 3.4.2 Download

- https://github.com/opencv/opencv/releases

- [opencv 3.4.2 releases](https://github.com/opencv/opencv/releases/download/3.4.2/opencv-3.4.2-vc14_vc15.exe)

#### 압축 풀기

- 파일 실행 후 압축 풀면 아래와 같음

```bash
├── build
│   └── *.*
├── sources
│   └── *.*
├── LICENSE.txt
├── LICENSE_FFMPEG.txt
└── README.md.txt
```

- build 폴더의 내용을 C:/opencv-3.4.2 으로 이동

#### Visual Studio 2017 설정

- 솔루션의 속성으로 이동

- 디버깅 설정

 - 구성: 모든구성 / 플랫폼: 활성(x64)
 
 - 구성 속성 > 디버깅 > 환경
 
 `PATH=C:\opencv-3.4.2\x64\vc15\bin;%PATH%`
 
 ![](/images/vs2017_openv_set_01.png)
 
- C/C++ 설정

 - 구성 속성 > C/C++ > 일반 > 추가 포함 디렉터리
 
 `C:\opencv-3.4.2\include`
 
 ![](/images/vs2017_openv_set_02.png)
 
- 링커 설정

 - 구성 속성 > 링커 > 일반 > 추가 라이브러리 디렉터리
 
 `C:\opencv-3.4.2\x64\vc15\lib`
 
 ![](/images/vs2017_openv_set_03.png)
 
- Debug Mode
 
 - 구성: 활성(Debug) / 플랫폼: 활성(x64)
  
 - 구성 속성 > 링커 > 입력 > 추가 종속성
 
 Release 다운로드 시 : `opencv_world342d.lib;`
 
 Build 결과물 일 시 : `opencv_world342d.lib;opencv_img_hash342d.lib;`
 
 ![](/images/vs2017_openv_set_04.png)
 
- Release Mode
 
 - 구성: 활성(Release) / 플랫폼: 활성(x64)
  
 - 구성 속성 > 링커 > 입력 > 추가 종속성
 
 Release 다운로드 시 : `opencv_world342.lib;`
 
 Build 결과물 일 시 : `opencv_world342.lib;opencv_img_hash342.lib;`
 
 ![](/images/vs2017_openv_set_05.png)
 

#### OpenCV Build 3.4.2 with contrib, eigen (VS 2017)

- [Cmake Download](https://cmake.org/download/)

- [opencv 3.4.2 source](https://github.com/opencv/opencv/archive/3.4.2.zip)

- [OpenCV Contrib](https://github.com/opencv/opencv_contrib/releases)

- [opencv contrib 3.4.2 releases](https://github.com/opencv/opencv_contrib/archive/3.4.2.zip)

- [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)

- 다운로드 받은 파일들을 필요한 곳에 압축을 푼다

```bash
D:\
└── opencv-3.4.2
    ├── opencv_contrib-3.4.2
    └── eigen
```

- Cmake 설정 (Visual Studio 15 2017 설치 되어 있는 경우)

  1. Where is the source code : D:/opencv-3.4.2
  
  2. Where to build the binaries : D:/opencv-3.4.2/Build
  
  3. Specify the generator for this project > Visual Studio 15 2017 > Finish > __Configure__
  
  ![](/images/opencv_build_01.png)
   
  4. OPENCV_EXTRA_MODULES_PATH > D:/opencv-3.4.2/opencv_contrib-3.4.2/modules > __Configure__
  
  5. EIGEN_INCLUDE_PATH > D:/opencv-3.4.2/eigen > __Configure__
  
  6. BUILD_opencv_world > check
  
  7. Generate
  
  8. Open Project
  
  9. Debug, Release 선택 > INSTALL 빌드
  
  10. 정상적인 Generate 모습
  
```
Selecting Windows SDK version 10.0.17134.0 to target Windows 6.1.7601.
libjpeg-turbo: VERSION = 1.5.3, BUILD = opencv-3.4.2-libjpeg-turbo
Looking for Mfapi.h
Looking for Mfapi.h - found
found Intel IPP (ICV version): 2017.0.3 [2017.0.3]
at: D:/opencv-3.4.2/Build/3rdparty/ippicv/ippicv_win
found Intel IPP IW sources: 2017.0.3
at: D:/opencv-3.4.2/Build/3rdparty/ippicv/ippiw_win
Could not find OpenBLAS include. Turning OpenBLAS_FOUND off
Could not find OpenBLAS lib. Turning OpenBLAS_FOUND off
Could NOT find BLAS (missing: BLAS_LIBRARIES) 
LAPACK requires BLAS
A library with LAPACK API not found. Please specify library location.
Could NOT find Matlab (missing: MATLAB_MEX_SCRIPT MATLAB_INCLUDE_DIRS MATLAB_ROOT_DIR MATLAB_LIBRARIES MATLAB_LIBRARY_DIRS MATLAB_MEXEXT MATLAB_ARCH MATLAB_BIN) 
VTK is not found. Please set -DVTK_DIR in CMake to VTK build directory, or to VTK install subdirectory with VTKConfig.cmake file
Caffe:   NO
Protobuf:   NO
Glog:   NO
freetype2:   NO
harfbuzz:    NO
Module opencv_ovis disabled because OGRE3D was not found
No preference for use of exported gflags CMake configuration set, and no hints for include/library directories provided. Defaulting to preferring an installed/exported gflags CMake configuration if available.
Failed to find installed gflags CMake configuration, searching for gflags build directories exported with CMake.
Failed to find gflags - Failed to find an installed/exported CMake configuration for gflags, will perform search for installed gflags components.
Failed to find gflags - Could not find gflags include directory, set GFLAGS_INCLUDE_DIR to directory containing gflags/gflags.h
Failed to find glog - Could not find glog include directory, set GLOG_INCLUDE_DIR to directory containing glog/logging.h
Module opencv_sfm disabled because the following dependencies are not found: Glog/Gflags
Processing WORLD modules...
    module opencv_core...
    module opencv_flann...
    module opencv_hdf...
    module opencv_imgproc...
    module opencv_ml...
    module opencv_objdetect...
    module opencv_phase_unwrapping...
    module opencv_photo...
    module opencv_plot...
    module opencv_reg...
    module opencv_surface_matching...
    module opencv_video...
    module opencv_xphoto...
    module opencv_dnn...
    module opencv_face...
    module opencv_fuzzy...
    module opencv_hfs...
    module opencv_imgcodecs...
    module opencv_shape...
    module opencv_videoio...
    module opencv_xobjdetect...
    module opencv_highgui...
    module opencv_superres...
    module opencv_bioinspired...
    module opencv_dnn_objdetect...
    module opencv_dpm...
    module opencv_features2d...
    module opencv_line_descriptor...
    module opencv_saliency...
    module opencv_text...
Tesseract:   NO
    module opencv_calib3d...
    module opencv_ccalib...
    module opencv_datasets...
    module opencv_rgbd...
    module opencv_stereo...
    module opencv_structured_light...
    module opencv_tracking...
    module opencv_videostab...
    module opencv_xfeatures2d...
    module opencv_ximgproc...
    module opencv_aruco...
    module opencv_bgsegm...
    module opencv_optflow...
    module opencv_stitching...
Processing WORLD modules... DONE
Excluding from source files list: modules/core/src/convert.avx2.cpp
Excluding from source files list: modules/imgproc/src/filter.avx2.cpp
Excluding from source files list: modules/imgproc/src/imgwarp.avx2.cpp
Excluding from source files list: modules/imgproc/src/resize.avx2.cpp
Excluding from source files list: modules/imgproc/src/undistort.avx2.cpp
Excluding from source files list: <BUILD>/modules/world/layers/layers_common.avx2.cpp
Excluding from source files list: <BUILD>/modules/world/layers/layers_common.avx512_skx.cpp
Excluding from source files list: modules/features2d/src/fast.avx2.cpp

General configuration for OpenCV 3.4.2 =====================================
  Version control:               unknown

  Extra modules:
    Location (extra):            D:/opencv-3.4.2/opencv_contrib-3.4.2/modules
    Version control (extra):     unknown

  Platform:
    Timestamp:                   2018-08-18T16:57:35Z
    Host:                        Windows 6.1.7601 AMD64
    CMake:                       3.12.1
    CMake generator:             Visual Studio 15 2017
    CMake build tool:            C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/MSBuild/15.0/Bin/MSBuild.exe
    MSVC:                        1914

  CPU/HW features:
    Baseline:                    SSE SSE2
      requested:                 SSE2
    Dispatched code generation:  SSE4_1 SSE4_2 FP16 AVX
      requested:                 SSE4_1 SSE4_2 AVX FP16
      SSE4_1 (3 files):          + SSE3 SSSE3 SSE4_1
      SSE4_2 (1 files):          + SSE3 SSSE3 SSE4_1 POPCNT SSE4_2
      FP16 (2 files):            + SSE3 SSSE3 SSE4_1 POPCNT SSE4_2 FP16 AVX
      AVX (5 files):             + SSE3 SSSE3 SSE4_1 POPCNT SSE4_2 AVX

  C/C++:
    Built as dynamic libs?:      YES
    C++11:                       YES
    C++ Compiler:                C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.14.26428/bin/Hostx86/x86/cl.exe  (ver 19.14.26433.0)
    C++ flags (Release):         /DWIN32 /D_WINDOWS /W4 /GR  /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D _SCL_SECURE_NO_WARNINGS /Gy /bigobj /Oi /fp:fast   /arch:SSE /arch:SSE2 /EHa /wd4127 /wd4251 /wd4324 /wd4275 /wd4512 /wd4589 /MP4   /MD /O2 /Ob2 /DNDEBUG 
    C++ flags (Debug):           /DWIN32 /D_WINDOWS /W4 /GR  /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D _SCL_SECURE_NO_WARNINGS /Gy /bigobj /Oi /fp:fast   /arch:SSE /arch:SSE2 /EHa /wd4127 /wd4251 /wd4324 /wd4275 /wd4512 /wd4589 /MP4   /MDd /Zi /Ob0 /Od /RTC1 
    C Compiler:                  C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.14.26428/bin/Hostx86/x86/cl.exe
    C flags (Release):           /DWIN32 /D_WINDOWS /W3  /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D _SCL_SECURE_NO_WARNINGS /Gy /bigobj /Oi /fp:fast   /arch:SSE /arch:SSE2   /MP4    /MD /O2 /Ob2 /DNDEBUG 
    C flags (Debug):             /DWIN32 /D_WINDOWS /W3  /D _CRT_SECURE_NO_DEPRECATE /D _CRT_NONSTDC_NO_DEPRECATE /D _SCL_SECURE_NO_WARNINGS /Gy /bigobj /Oi /fp:fast   /arch:SSE /arch:SSE2   /MP4  /MDd /Zi /Ob0 /Od /RTC1 
    Linker flags (Release):      /machine:X86  /INCREMENTAL:NO 
    Linker flags (Debug):        /machine:X86  /debug /INCREMENTAL 
    ccache:                      NO
    Precompiled headers:         NO
    Extra dependencies:
    3rdparty dependencies:

  OpenCV modules:
    To be built:                 aruco bgsegm bioinspired calib3d ccalib core datasets dnn dnn_objdetect dpm face features2d flann fuzzy hdf hfs highgui img_hash imgcodecs imgproc java_bindings_generator line_descriptor ml objdetect optflow phase_unwrapping photo plot python_bindings_generator reg rgbd saliency shape stereo stitching structured_light superres surface_matching text tracking ts video videoio videostab world xfeatures2d ximgproc xobjdetect xphoto
    Disabled:                    js
    Disabled by dependency:      -
    Unavailable:                 cnn_3dobj cudaarithm cudabgsegm cudacodec cudafeatures2d cudafilters cudaimgproc cudalegacy cudaobjdetect cudaoptflow cudastereo cudawarping cudev cvv freetype java matlab ovis python2 python3 sfm viz
    Applications:                tests perf_tests apps
    Documentation:               NO
    Non-free algorithms:         NO

  Windows RT support:            NO

  GUI: 
    Win32 UI:                    YES
    VTK support:                 NO

  Media I/O: 
    ZLib:                        build (ver 1.2.11)
    JPEG:                        build-libjpeg-turbo (ver 1.5.3-62)
    WEBP:                        build (ver encoder: 0x020e)
    PNG:                         build (ver 1.6.34)
    TIFF:                        build (ver 42 - 4.0.9)
    JPEG 2000:                   build (ver 1.900.1)
    OpenEXR:                     build (ver 1.7.1)
    HDR:                         YES
    SUNRASTER:                   YES
    PXM:                         YES

  Video I/O:
    Video for Windows:           YES
    DC1394:                      NO
    FFMPEG:                      YES (prebuilt binaries)
      avcodec:                   YES (ver 57.107.100)
      avformat:                  YES (ver 57.83.100)
      avutil:                    YES (ver 55.78.100)
      swscale:                   YES (ver 4.8.100)
      avresample:                YES (ver 3.7.0)
    GStreamer:                   NO
    DirectShow:                  YES
    Media Foundation:            YES

  Parallel framework:            Concurrency

  Trace:                         YES (with Intel ITT)

  Other third-party libraries:
    Intel IPP:                   2017.0.3 [2017.0.3]
           at:                   D:/opencv-3.4.2/Build/3rdparty/ippicv/ippicv_win
    Intel IPP IW:                sources (2017.0.3)
              at:                D:/opencv-3.4.2/Build/3rdparty/ippicv/ippiw_win
    Lapack:                      NO
    Eigen:                       YES (ver 3.3.5)
    Custom HAL:                  NO
    Protobuf:                    build (3.5.1)

  OpenCL:                        YES (no extra features)
    Include path:                D:/opencv-3.4.2/3rdparty/include/opencl/1.2
    Link libraries:              Dynamic load

  Python (for build):            C:/Anaconda3/python.exe

  Java:                          
    ant:                         NO
    JNI:                         C:/Program Files/Java/jdk-10.0.1/include C:/Program Files/Java/jdk-10.0.1/include/win32 C:/Program Files/Java/jdk-10.0.1/include
    Java wrappers:               NO
    Java tests:                  NO

  Matlab:                        NO

  Install to:                    D:/opencv-3.4.2/Build/install
-----------------------------------------------------------------

Configuring done
```