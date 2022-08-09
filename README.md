
# Smart IoT Electric Charging Solution
> 자동으로 충전 및 차량 관리가 가능한 스마트 전기차 충전소 솔루션 프로젝트 입니다.

[![NPM Version][npm-image]][npm-url]
[![Build Status][travis-image]][travis-url]
[![Downloads Stats][npm-downloads]][npm-url]

프로젝트 소개 글 작성 예정...

![](../header.png)

|이름|내용|
|---|--------|
|강시형|ROS 통신 구축 Pi Camera OpenCV 기반 번호판 인식 및 Realsense 활용 충전구 탐색 구현, Dynamixel 활용 Manipulator 구현|
|오규상|OpenCV 기반 충전구탐색 구현.   Dynamixel 활용 Manipulator 구현|
|김재현|APM(Apache, php, MariaDB) 및 Socket Server 기반 Qt UI 구현.   Arduino Parking System 구현|
|김건우|APM(Apache, php, MariaDB) 및 Socket Server 기반 Qt UI 구현.   Arduino Parking System 구현|

## 설치 방법

OS X & 리눅스:

```sh
npm install my-crazy-module --save
```

윈도우:

```sh
edit autoexec.bat
```

## 사용 예제

스크린 샷과 코드 예제를 업로드 예정

_더 많은 예제와 사용법은 [Wiki][wiki]를 참고하세요._

## 개발 환경 설정

개발 의존성 설치 방법과 자동 테스트 슈트 실행 방법을 운영체제 별로 작성

```sh
make install
npm test
```

## 업데이트 내역


* 22.06.02
    * 원형 탐색 기반 객체 인식 및 충전구 탐색 알고리즘 
* 22.06.21
    * 차량 3면 탐색 방식 객체 탐색 동작 구현 테스트
* 22.06.17
    * APM 기반 서버 구축 완료 및 Socket 통신 구현. Qt연동 준비
* 22.06.14
    * 색 추적 방식 객체 인식 알고리즘 구현 테스트
* 22.06.05
    * OpenCR 및 Dynamixel 활용 Manipulator 방식 충전기 개발 시작
* 22.06.04
    * OpenCV 기반 충전구 인식 알고리즘 개발 시작
* 22.06.01
    * ROS 환경 구축 시작
* 22.06.01
    * 메인 서버(Raspberry Pi 4 + APM(Apache, php, MariaDB) 개발 및 구축 시작
* 22.05.29
    * 사용자부분 (Qt기반) 개발 시작
* 22.05.29
    * 충전기 Manipulator Hardware 조립
* 22.05.28 ~ 22.06.04 _END
    * 개발환경 구축 완료
* 22.05.26 ~ 22.05.29
    * 개별 업무 분담 및 재료구매 신청 완료
* 22.05.23
    * 아이디어 선정 및 구체화 완료
* 22.05.16
    * 아이디어 주제 탐구

## Workflow
![image](https://user-images.githubusercontent.com/102007930/182278516-c0bf7e28-d8fc-4a0a-8a03-8cc8fa126d42.png)
![image](https://user-images.githubusercontent.com/102007930/182278520-a149a9b3-3583-438b-a753-e7fb2beda625.png)




## 기술 스택

| <center>분류</center> |<center>기술 스택</center>|
| :-------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| *Languages*|<img src="https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=C&logoColor=white"/> <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white"/> <img src="https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=Python&logoColor=white"/>|
| *MCU & MPU*|<img src="https://img.shields.io/badge/Raspberry Pi-A22846?style=flat-square&logo=Raspberry Pi&logoColor=white"/> <img src="https://img.shields.io/badge/Jetson Nano-76B900?style=flat-square&logo=NVIDIA&logoColor=white"/> <img src="https://img.shields.io/badge/Arduino-00979D?style=flat-square&logo=Arduino&logoColor=white">|
| *Server / DB*|<img src="https://img.shields.io/badge/Apache-D22128?style=flat-square&logo=Apache&logoColor=white"/> <img src="https://img.shields.io/badge/PHP-777BB4?style=flat-square&logo=PHP&logoColor=white"/> <img src="https://img.shields.io/badge/MySQL-4479A1?style=flat-square&logo=MySQL&logoColor=white"/> |
| *OS*|<img src="https://img.shields.io/badge/Windows 10-0078D6?style=flat-square&logo=Windows&logoColor=white"/> <img src="https://img.shields.io/badge/Ubuntu-E95420?style=flat-square&logo=Ubuntu&logoColor=white"/> |
| *Platform / Library*|<img src="https://img.shields.io/badge/ROS-22314E?style=flat-square&logo=ROS&logoColor=white"/> <img src="https://img.shields.io/badge/OpenCV-5C3EE8?style=flat-square&logo=OpenCV&logoColor=white"/> |
| *VersionControl*|<img src="https://img.shields.io/badge/Git-F05032?style=flat-square&logo=Git&logoColor=white"/> <img src="https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=GitHub&logoColor=white"/> |
| *ETC*|<img src="https://img.shields.io/badge/Google Docs-4285F4?style=flat-square&logo=Google&logoColor=white"/> <img src="https://img.shields.io/badge/Notion-000000?style=flat-square&logo=Notion&logoColor=white"/>|

<!-- Markdown link & img dfn's -->
[npm-image]: https://img.shields.io/npm/v/datadog-metrics.svg?style=flat-square
[npm-url]: https://npmjs.org/package/datadog-metrics
[npm-downloads]: https://img.shields.io/npm/dm/datadog-metrics.svg?style=flat-square
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://github.com/yourname/yourproject/wiki 
