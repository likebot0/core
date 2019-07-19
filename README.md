# core.h

## Features

### Data type
* Array
* Hash map
* Prefix tree (a.k.a Trie)
* Tagged union (a.k.a. Sum type)

### Abstraction layer
* Event loop / Event model
* File system
* Graphics (DirectX, Quartz, X, Wayland)
* Network

### API Wrapper
* IEEE Std 1003.1-2017
* Windows
  * Win32
  * Win64
* Linux
  * epoll
* *BSD
  * kevent/kqueue

## Requirements
* C++2a

## Install
`include/core` and `include/core.h` move to headers directory

## Build example
```sh
package_name=$(basename $PWD)

docker run\
    -it --rm\
    -v /usr/local/include/core:/usr/local/include/core\
    -v /usr/local/include/core.h:/usr/local/include/core.h\
    -v $PWD:/opt/$package_name\
    -v /tmp:/tmp\
    gcc-snapshot\
    -std=c++2a -O3 -Wall /opt/$package_name/src/main.cpp -o /tmp/$package_name
```

## Usage
```c++
#include <core.h>

int main() {
    return 0;
}
```
