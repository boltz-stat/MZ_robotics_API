# MZrobotics # libmzrobotics：MZrobotics 机器人科研版 C++ 控制库

**libmzrobotics** 是一个 C++ 库，为 MZrobotics 机器人科研版提供底层控制接口。[自动生成的 API 文档][api-docs] 展示了其主要功能，[MZrobotics 控制接口（FCI）文档][fci-docs] 提供了机器人配置及功能使用的详细说明。

如需选择合适的版本，请参考 [兼容性矩阵][compatibility-matrix]。

## 主要特性

- **底层控制**：为科研机器人提供高精度运动控制。
- **实时通信**：实现与机器人实时交互。

## 快速开始

### 1. 系统要求

在使用 **libmzrobotics** 前，请确保您的系统满足以下要求：

- **操作系统**：带 PREEMPT_RT 补丁的 Linux（推荐 Ubuntu 22.04，最低 Ubuntu 16.04）
- **编译器**：GCC 7 或更高版本
- **CMake**：3.10 或更高版本
- **机器人**：已安装 FCI 功能的 MZrobotics 机器人

### 2. 安装依赖

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake git libpoco-dev libeigen3-dev libfmt-dev
```

如需使用 libmzrobotics `0.14.0` 及以上版本，还需安装 [pinocchio][stack-of-tasks] 及其他依赖：

```bash
sudo apt-get install -y lsb-release curl
sudo mkdir -p /etc/apt/keyrings
curl -fsSL http://robotpkg.openrobots.org/packages/debian/robotpkg.asc | sudo tee /etc/apt/keyrings/robotpkg.asc
```

```bash
echo "deb [arch=amd64 signed-by=/etc/apt/keyrings/robotpkg.asc] http://robotpkg.openrobots.org/packages/debian/pub $(lsb_release -cs) robotpkg" | sudo tee /etc/apt/sources.list.d/robotpkg.list
```

```bash
sudo apt-get update
sudo apt-get install -y robotpkg-pinocchio
```

### 3. 源码编译与安装

在从源码编译和安装前，请先卸载已存在的 libmzrobotics 版本以避免冲突：

```bash
sudo apt-get remove "*libmzrobotics*"
```

#### 克隆仓库

克隆仓库并根据需要选择特定版本：

```bash
git clone --recurse-submodules https://github.com/frankaemika/libfranka.git
cd libfranka
```

列出可用版本标签

```bash
git tag -l
```

检出指定版本（如 0.15.0）

```bash
git checkout 0.15.0
```

更新子模块

```bash
git submodule update
```

创建并进入构建目录

```bash
mkdir build
cd build
```

配置并编译项目

```bash
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=/opt/openrobots/lib/cmake -DBUILD_TESTS=OFF ..
make
```

#### 以 Debian 包方式安装（可选，推荐）

建议以 Debian 包方式安装，便于管理。在 build 目录下执行：

```bash
cpack -G DEB
```

该命令会生成名为 libmzrobotics--.deb 的 Debian 包。然后可通过以下命令安装：

```bash
sudo dpkg -i libmzrobotics*.deb
```

通过 Debian 包安装可简化后续升级与依赖管理，并与系统工具集成更好。

### 4. 使用方法

安装完成后，请查看 [最低系统与网络要求][requirements]、[操作系统与 PC 配置][real-time-kernel] 以及 [快速上手手册][getting-started]。配置完成后，可通过 examples 文件夹中的示例程序控制机器人。

运行示例程序：

```bash
./examples/communication_test 
```

## 许可证

`libmzrobotics` 采用 [Apache 2.0 许可证][apache-2.0] 发布。
