#!/usr/bin/env bash

#
#    Copyright (c) 2020 Project CHIP Authors
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#

set -x
env

app="$1"
#sdkconfig_name="$2"
root=examples/$app/Ameba/


if [ -z "$app" ]; then
    echo "No mandatory app argument supplied!"
    exit 1
fi

source ../../scripts/bootstrap.sh
source ../../scripts/activate.sh
export CHIP_PATH="~/chip"
cd ${AMEBA_PATH}
make clean
source ToolPath.sh
make lib_all
make is

cp "$AMEBA_PATH"/application_is/Debug/bin/flash_is.bin ~/chip/examples/all-clusters-app/ambd/build/chip/gen/flash_is.bin
