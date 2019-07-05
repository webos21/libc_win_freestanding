# Copyright 2013 Cheolmin Jo (webos21@gmail.com)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

######################################################
#                        OSX64                       #
#----------------------------------------------------#
# File    : build_osx64.mk                           #
# Version : 1.0.0                                    #
# Desc    : properties file for MacOSX 64bit build.  #
#----------------------------------------------------#
# History)                                           #
#   - 2019/07/05 : Created by cmjo                   #
######################################################


########################
# Programs
########################
include ${basedir}/buildx/antmk/shcmd.mk


########################
# Build Configuration
########################
build_cfg_target   = osx64
build_cfg_mac      = 1
build_cfg_posix    = 1
build_cfg_arch     = x86


########################
# Directories
########################
build_tool_dir     = 


########################
# Program Definition
########################
build_tool_as      = ${build_tool_dir}as
build_tool_cc      = ${build_tool_dir}gcc
build_tool_cxx     = ${build_tool_dir}g++
build_tool_linker  = ${build_tool_dir}g++
build_tool_ar      = ${build_tool_dir}ar
build_tool_ranlib  = ${build_tool_dir}ranlib


########################
# Compile Flags
########################
#build_run_a        = 1
build_run_so       = 1
build_run_test     = 1

build_opt_a_pre    = lib
build_opt_a_ext    = a
build_opt_so_pre   = lib
build_opt_so_ext   = dylib
build_opt_exe_ext  =

build_opt_c        = -g -O3 \
                        -Wall -Wextra -Wdeclaration-after-statement \
                        -nostdinc -ffreestanding \
                        -fno-stack-check -fno-stack-protector -mno-stack-arg-probe
build_opt_cxx      = -g -O3 \
                        -Wall -Wextra \
                        -nostdinc -ffreestanding \
                        -fno-stack-check -fno-stack-protector -mno-stack-arg-probe
build_opt_fPIC     = -fPIC
build_opt_ld       = -g \
                        -Wl,--no-undefined -nostdlib
build_opt_ld_so    = -dynamiclib -Wl,-install_name,
build_opt_ld_rpath = -Wl,-rpath-link,
build_opt_ld_noud  =
build_opt_ld_mgwcc =
build_opt_ld_mgwcx =
