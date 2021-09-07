ARG VERSION=latest
FROM connectedhomeip/chip-build:${VERSION}

# Setup Ameba
ARG AMEBA_DIR=/opt/ameba
RUN set -x \
    && apt-get update \
    && mkdir ${AMEBA_DIR} \
    && cd ${AMEBA_DIR} \
    && git clone --progress -b matter https://github.com/AdamZhang0124/ambz2_sdk.git \
    && cd ambz2_sdk \
    && git submodule update --init --progress \
#    && AMEBA_BUILD=/opt/ameba/ ./build.sh \
    && : # last line

ENV AMEBA_PATH=${AMEBA_DIR}/ambz2_sdk/project/realtek_amebaz2_v0_example/GCC-RELEASE/
