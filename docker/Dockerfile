FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
&&  apt-get install -y build-essential cmake git pkg-config libgtk-3-dev libavcodec-dev libavformat-dev libswscale-dev \
    libv4l-dev libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev gfortran openexr libatlas-base-dev \
    python3-dev python3-numpy libtbb2 libtbb-dev libdc1394-22-dev libopenexr-dev libgstreamer-plugins-base1.0-dev \
    libgstreamer1.0-dev

RUN mkdir ~/opencv_build && cd ~/opencv_build \
&&  git clone https://github.com/opencv/opencv.git \
&&  cd ~/opencv_build/opencv \
&&  mkdir -p build && cd build \
&&  cmake -D CMAKE_BUILD_TYPE=RELEASE \
          -D CMAKE_INSTALL_PREFIX=/usr/local \
          -D OPENCV_GENERATE_PKGCONFIG=ON .. \
&&  make -j`nproc` \
&&  make install

RUN apt-get install -y python3-pip && pip3 install typing_extensions pyyaml \
&&  mkdir ~/pytorch_build && cd ~/pytorch_build \
&&  git clone -b v1.10.0 --recurse-submodule https://github.com/pytorch/pytorch.git \
&&  mkdir pytorch-build && cd pytorch-build \
&&  cmake -DBUILD_SHARED_LIBS:BOOL=ON \
          -DCMAKE_BUILD_TYPE:STRING=Release \
          -DPYTHON_EXECUTABLE:PATH=`which python3` \
          -DCMAKE_INSTALL_PREFIX:PATH=/usr/local ../pytorch \
&&  cmake --build . --target install

RUN apt-get install -y openssh-server
RUN mkdir /var/run/sshd

RUN echo 'root:root' |chpasswd

RUN sed -ri 's/^#?PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config

RUN mkdir /root/.ssh

RUN apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 22

CMD    ["/usr/sbin/sshd", "-D"]
