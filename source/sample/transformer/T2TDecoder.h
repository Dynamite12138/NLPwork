/* NiuTrans.Tensor - an open-source tensor library
 * Copyright (C) 2020, Natural Language Processing Lab, Northeastern University.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Created by: XIAO Tong (xiaotong@mail.neu.edu.cn) 2018-07-31
 * $Modified by: HU Chi (huchinlp@gmail.com) 2020-04
 */

#ifndef __T2TDECODER_H__
#define __T2TDECODER_H__

#include "T2TEncoder.h"
#include "module/T2TUtility.h"

namespace transformer
{

class AttDecoder
{
public:

    /* device id */
    int devID;

    /* layer number */
    int nlayer;

    /* hidden layer size of the FNN layer */
    int hSize;

    /* embedding size */
    int eSize;

    /* vocabulary size */
    int vSize;

    /* dropout probability */
    DTYPE dropoutP;

    /* embedding of word at each position */
    T2TEmbedder embedder;

    /* FNN model of each layer */
    T2TFNN* fnns;

    /* attention model of each layer */
    T2TAttention* selfAtt;

    /* layer normalization for attention */
    T2TLN* selfAttLayerNorms;

    /* layer normalization for fnn */
    T2TLN* fnnLayerNorms;

    /* layer normalization for decoder */
    T2TLN* decoderLayerNorm;

    /* encoder-decoder attention model of each layer */
    T2TAttention* enDeAtt;

    /* layer normalization for encoder-decoder attention */
    T2TLN* enDeAttLayerNorms;

    /* layer cache list */
    Cache* selfAttCache;

    /* layer cache list */
    Cache* enDeAttCache;

    /* the location of layer normalization */
    bool preNorm;

public:
    /* constructor */
    AttDecoder();

    /* de-constructor */
    ~AttDecoder();

    /* initialize the model */
    void InitModel(T2TConfig& config);

    /* make the decoding network */
    XTensor Make(XTensor& inputDec, XTensor& outputEnc, XTensor* mask,
                 XTensor* maskEncDec, int nstep, bool isTraining);
};

}

#endif