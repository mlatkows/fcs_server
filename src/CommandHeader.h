/*
This project, FPGA Crypto Service Server, is licensed as below

***************************************************************************

Copyright 2020-2021 Intel Corporation. All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

***************************************************************************
*/

#ifndef COMMANDHEADER_H
#define COMMANDHEADER_H

#include <stddef.h>

class CommandHeader
{
    public:
        void parse(unsigned char buffer[sizeof(uint32_t)]);
        void encode(unsigned char buffer[sizeof(uint32_t)]);
        static size_t getRequiredSize()
        {
            return sizeof(uint32_t);
        }

        uint8_t client;
        uint8_t id;
        uint8_t res1;
        uint16_t length;
        uint8_t res2;
        uint16_t code;

    private:
        void fromUint32(uint32_t input);
        uint32_t readBits(uint32_t &source, uint8_t numberOfBits);
        void writeBits(
            uint32_t &destination,
            uint32_t source,
            uint8_t numberOfBits);
        uint32_t toUint32();
};

#endif /* COMMANDHEADER_H */