CMAKE_MINIMUM_REQUIRED( VERSION 2.8 ) #设定版本
PROJECT(MC) #设定工程名
SET(CMAKE_CXX_COMPILER "g++") #设定编译器

#设定可执行二进制文件的目录
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#并且把该目录设为连接目录
LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib)

#设定头文件目录
INCLUDE_DIRECTORIES( ${PROJECT_SOURCE_DIR}/include)

#增加子文件夹，也就是进入源代码文件夹继续构建
ADD_SUBDIRECTORY( ${PROJECT_SOURCE_DIR}/src)

#生成应用程序 ,如:hello (在windows下会自动生成hello.exe)
ADD_EXECUTABLE(hello cpp文件)