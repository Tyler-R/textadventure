# Dungeon Crawler

## Library Dependencies

#### Install boost

```shell
$ bash sudoBoostInstall.sh
```

#### Install curses
---

```shell
$ sudo apt-get install libncurses5-dev
```

## Build
---
```bash
$ git clone https://github.com/Tyler-R/Dungeon-Crawler
$ cd Dungeon-Crawler
$ mkdir build_Dungeon-Crawler
$ cd build_Dungeon-Crawler
$ cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ../Dungeon-Crawler
```