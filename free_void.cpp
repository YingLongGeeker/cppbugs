/*
 * YingLongGeeker is pleased to support the open source community by making this software available.
 * Copyright (C) 2021 YingLongGeeker. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and 
 * limitations under the License.
*/

#include <iostream>

struct Data {
    int value;
};

void ShowData(void* data, size_t cnt) {

    for (size_t idx = 0; idx < cnt; ++idx) {

        Data* ptrTmp = reinterpret_cast<Data*>(data) + idx;
        std::cout << "data.value:" << ptrTmp->value << std::endl;
    }

    free(data); // NOTE: mem leak. should use delete [](Data*)data;
}

int main(int argc, char* argv[]) {

    size_t cnt = 10;
    Data* ptrData = new Data[cnt];
    for (size_t idx = 0; idx < cnt; ++idx) {
        ptrData[idx].value = idx;
    }

    ShowData(ptrData, cnt);

    return 0;
}

// BUILD: g++ -o free_void free_void.cpp