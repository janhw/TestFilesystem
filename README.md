TestFilesystem
==============

test Filesystem code


此工具能很容易的测试文件系统的性能，以多进程并发的方式读和写文件，支持大文件和小文件读写，结果以命令行的方式输出，方便总结结果。目前版本支持linux和windows版本。

1.windows系统上：

	需要安装QtCreator软件，用于编译此工具。
	
2.在linux系统上：

	同样需要安装QtCreator软件，用于编译此工具，QT工具需要在GCC4.7版本之上运行，所以需要升级GCC（本人使用的是centos6.5、6.4版本，Gcc升级为4.8.1）。
	
	以下是GCC升级的步骤：
	
	Installing Qt 5.1.1 on CentOS 6.4（官网安装方式）目前测试使用的GCC 4.8.1版本
	
	1.Install Development Tools
		sudo yum groupinstall "Development Tools"
		
	2.Install glibc-devel.i686 (the 32-bit version is required to build GCC)
		sudo yum install glibc-devel.i686
		
	3.Download and install GCC [gcc.gnu.org] 4.8.1 or latest version. Instructions copied from here [gcc.gnu.org]
		    tar xvjf gcc-4.8.1.tar.bz2
		    cd gcc-4.8.1
		    ./contrib/download_prerequisites
		    cd ..
		    mkdir objdir
		    cd objdir
		    $PWD/../gcc-4.8.1/configure --prefix=$HOME/gcc-4.8.1
		    make
		    sudo make install
		    
	4.Copy new GCC libraries to /usr/lib64
		    sudo mv /usr/lib64/libstdc++.so.6 /usr/lib64/libstdc++.so.6.backup
		    sudo cp -P /root/gcc-4.8.1/lib64/libstdc++.so.6 /usr/lib64
		    sudo cp /root/gcc-4.8.1/lib64/libstdc++.so.6.0.18 /usr/lib64/
		    sudo ldconfig -v

	5. Download and install Qt [qt-project.org] 5.1.1 or latest version (这样就可以使用qt了)
    		sudo ./qt-linux-opensource-5.1.1-x86_64-offline.run
	
	在升级完就可以编译此工具了。

3.多进程写的pro是write_file_process.pro

4.多进程读的pro是read_file_process.pro

