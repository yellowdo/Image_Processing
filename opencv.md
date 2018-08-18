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
 

#### OpenCV Build

- [Cmake Download](https://cmake.org/download/)

- [opencv 3.4.2 source](https://github.com/opencv/opencv/archive/3.4.2.zip)

- [OpenCV Contrib](https://github.com/opencv/opencv_contrib/releases)

- [opencv contrib 3.4.2 releases](https://github.com/opencv/opencv_contrib/archive/3.4.2.zip)



