# Copyright 2016 Cheolmin Jo (webos21@gmail.com)
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
#                libc_win_freestanding               #
#----------------------------------------------------#
# File    : Makefile                                 #
# Version : 1.0.0                                    #
# Desc    : Starting makefile.                       #
#----------------------------------------------------#
# History)                                           #
#   - 2019/07/05 : Created by cmjo                   #
######################################################

linux32:
	@$(MAKE) -f buildx.mk TARGET=$@

linux64:
	@$(MAKE) -f buildx.mk TARGET=$@

mingw32:
	@$(MAKE) -f buildx.mk TARGET=$@

mingw64:
	@$(MAKE) -f buildx.mk TARGET=$@

osx32:
	@$(MAKE) -f buildx.mk TARGET=$@

osx64:
	@$(MAKE) -f buildx.mk TARGET=$@

entire: linux32 linux64 mingw32 mingw64 osx32 osx64

clean:
	@$(RM) -rf ./amk/*

usage:
	@echo "####################################################"
	@echo "#              libc_win_freestanding               #"
	@echo "#--------------------------------------------------#"
	@echo "# We only support below command.                   #"
	@echo "#                                                  #"
	@echo "#   - make doc     : make the Documents            #"
	@echo "#                                                  #"
	@echo "#   - make linux32 : make for the linux 32bit      #"
	@echo "#   - make linux64 : make for the linux 64bit      #"
	@echo "#   - make mingw32 : make for the MinGW 32bit      #"
	@echo "#   - make mingw64 : make for the MinGW 64bit      #"
	@echo "#   - make osx32   : make for the Mac OSX 32bit    #"
	@echo "#   - make osx64   : make for the Mac OSX 64bit    #"
	@echo "#   - make clean   : clean the source tree         #"
	@echo "#                                                  #"
	@echo "#   - make entire  : make for the ENTIRE targets   #"
	@echo "#                                                  #"
	@echo "####################################################"
