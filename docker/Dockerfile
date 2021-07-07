FROM wollac/ledger-bolos AS build-app-legacy

ENV DEVICE=nanos

# switch to non-interactive
RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    libusb-dev libusb-1.0-0-dev libudev-dev cmake  qemu-user-static python3-pyqt5 \
    python3-construct python3-jsonschema python3-mnemonic python3-pyelftools \
    gcc-arm-linux-gnueabihf libc6-dev-armhf-cross gdb-multiarch pkg-config \
    libssl-dev protobuf-compiler lld-7  && \
    rm -rf /var/lib/apt/lists/*

COPY . /root/git/app-iota-legacy/

WORKDIR /usr/bin
RUN ln -s clang-7 clang

# build blue loader
WORKDIR /root/git/app-iota-legacy/dev/blue-loader-python
RUN pwd
RUN ls
RUN python3.8 setup.py install

# build speculos simulator
WORKDIR /root/git/app-iota-legacy/dev/speculos
RUN cmake -Bbuild -H. && make -C build/ 

WORKDIR /root/git/ledger-iota-app

RUN echo    "#!/bin/bash\n" \
    "export DEVICE=nanos\n" \
    "export BOLOS_SDK=/root/git/app-iota-legacy/dev/sdk/nanos-secure-sdk\n" \
    "unset BOLOS_ENV\n" \
    "export CLANGPATH=/usr/bin/\n" \
    "export GCCPATH=/usr/bin/\n" \
    "echo nanos > device.txt\n" > env_nanos.sh

RUN sed 's|nanos|nanox|g' env_nanos.sh > env_nanox.sh


EXPOSE 9999
