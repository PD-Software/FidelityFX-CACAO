#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer SSAOConstantsBuffer
// {
//
//   struct CACAOConstants
//   {
//       
//       float2 DepthUnpackConsts;      // Offset:    0
//       float2 CameraTanHalfFOV;       // Offset:    8
//       float2 NDCToViewMul;           // Offset:   16
//       float2 NDCToViewAdd;           // Offset:   24
//       float2 DepthBufferUVToViewMul; // Offset:   32
//       float2 DepthBufferUVToViewAdd; // Offset:   40
//       float EffectRadius;            // Offset:   48
//       float EffectShadowStrength;    // Offset:   52
//       float EffectShadowPow;         // Offset:   56
//       float EffectShadowClamp;       // Offset:   60
//       float EffectFadeOutMul;        // Offset:   64
//       float EffectFadeOutAdd;        // Offset:   68
//       float EffectHorizonAngleThreshold;// Offset:   72
//       float EffectSamplingRadiusNearLimitRec;// Offset:   76
//       float DepthPrecisionOffsetMod; // Offset:   80
//       float NegRecEffectRadius;      // Offset:   84
//       float LoadCounterAvgDiv;       // Offset:   88
//       float AdaptiveSampleCountLimit;// Offset:   92
//       float InvSharpness;            // Offset:   96
//       int PassIndex;                 // Offset:  100
//       float BilateralSigmaSquared;   // Offset:  104
//       float BilateralSimilarityDistanceSigma;// Offset:  108
//       float4 PatternRotScaleMatrices[5];// Offset:  112
//       float NormalsUnpackMul;        // Offset:  192
//       float NormalsUnpackAdd;        // Offset:  196
//       float DetailAOStrength;        // Offset:  200
//       float Dummy0;                  // Offset:  204
//       float2 SSAOBufferDimensions;   // Offset:  208
//       float2 SSAOBufferInverseDimensions;// Offset:  216
//       float2 DepthBufferDimensions;  // Offset:  224
//       float2 DepthBufferInverseDimensions;// Offset:  232
//       int2 DepthBufferOffset;        // Offset:  240
//       float2 PerPassFullResUVOffset; // Offset:  248
//       float2 OutputBufferDimensions; // Offset:  256
//       float2 OutputBufferInverseDimensions;// Offset:  264
//       float2 ImportanceMapDimensions;// Offset:  272
//       float2 ImportanceMapInverseDimensions;// Offset:  280
//       float2 DeinterleavedDepthBufferDimensions;// Offset:  288
//       float2 DeinterleavedDepthBufferInverseDimensions;// Offset:  296
//       float2 DeinterleavedDepthBufferOffset;// Offset:  304
//       float2 DeinterleavedDepthBufferNormalisedOffset;// Offset:  312
//       float4x4 NormalsWorldToViewspaceMatrix;// Offset:  320
//
//   } g_CACAOConsts;                   // Offset:    0 Size:   384
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// g_PointClampSampler               sampler      NA          NA             s0      1 
// g_ImportanceFinalSSAO             texture  float2     2darray             t0      1 
// g_ImportanceOut                       UAV   float          2d             u0      1 
// SSAOConstantsBuffer               cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[14], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2darray (float,float,float,float) t0
dcl_uav_typed_texture2d (float,float,float,float) u0
dcl_input vThreadID.xy
dcl_temps 4
dcl_thread_group 8, 8, 1
ishl r0.xy, vThreadID.xyxx, l(1, 1, 0, 0)
utof r0.xy, r0.xyxx
add r0.xy, r0.xyxx, l(0.500000, 0.500000, 0.000000, 0.000000)
mul r0.xy, r0.xyxx, cb0[13].zwzz
mov r0.zw, l(0,0,0,1.000000)
gather4_indexable(texture2darray)(float,float,float,float) r1.xyzw, r0.xyzx, t0.xyzw, s0.x
gather4_indexable(texture2darray)(float,float,float,float) r2.xyzw, r0.xywx, t0.xyzw, s0.x
mad_sat r2.xyzw, -cb0[3].yyyy, r2.xyzw, l(1.000000, 1.000000, 1.000000, 1.000000)
log r2.xyzw, r2.xyzw
mul r2.xyzw, r2.xyzw, cb0[3].zzzz
exp r2.xyzw, r2.xyzw
mad_sat r1.xyzw, -cb0[3].yyyy, r1.xyzw, l(1.000000, 1.000000, 1.000000, 1.000000)
log r1.xyzw, r1.xyzw
mul r1.xyzw, r1.xyzw, cb0[3].zzzz
exp r1.xyzw, r1.xyzw
min r3.xy, r1.ywyy, r1.xzxx
max r1.xy, r1.ywyy, r1.xzxx
max r1.x, r1.y, r1.x
min r1.y, r3.y, r3.x
min r1.y, r1.y, l(1.000000)
min r1.zw, r2.yyyw, r2.xxxz
max r2.xy, r2.ywyy, r2.xzxx
max r2.x, r2.y, r2.x
max r1.x, r1.x, r2.x
min r1.z, r1.w, r1.z
min r1.y, r1.z, r1.y
mov r0.zw, l(0,0,2.000000,3.000000)
gather4_indexable(texture2darray)(float,float,float,float) r2.xyzw, r0.xyzx, t0.xyzw, s0.x
gather4_indexable(texture2darray)(float,float,float,float) r0.xyzw, r0.xywx, t0.xyzw, s0.x
mad_sat r0.xyzw, -cb0[3].yyyy, r0.xyzw, l(1.000000, 1.000000, 1.000000, 1.000000)
log r0.xyzw, r0.xyzw
mul r0.xyzw, r0.xyzw, cb0[3].zzzz
exp r0.xyzw, r0.xyzw
mad_sat r2.xyzw, -cb0[3].yyyy, r2.xyzw, l(1.000000, 1.000000, 1.000000, 1.000000)
log r2.xyzw, r2.xyzw
mul r2.xyzw, r2.xyzw, cb0[3].zzzz
exp r2.xyzw, r2.xyzw
min r1.zw, r2.yyyw, r2.xxxz
max r2.xy, r2.ywyy, r2.xzxx
max r2.x, r2.y, r2.x
max r1.x, r1.x, r2.x
min r1.z, r1.w, r1.z
min r1.y, r1.z, r1.y
min r1.zw, r0.yyyw, r0.xxxz
max r0.xy, r0.ywyy, r0.xzxx
max r0.x, r0.y, r0.x
max r0.x, r0.x, r1.x
min r0.y, r1.w, r1.z
min r0.y, r0.y, r1.y
add r0.x, -r0.y, r0.x
add_sat r0.x, r0.x, r0.x
log r0.x, r0.x
mul r0.x, r0.x, l(0.800000)
exp r0.x, r0.x
store_uav_typed u0.xyzw, vThreadID.xyyy, r0.xxxx
ret 
// Approximately 56 instruction slots used
#endif

const BYTE CSGenerateImportanceMapDXIL[] =
{
     68,  88,  66,  67,  36,  88, 
     65, 163, 153,   2,   4, 215, 
    220, 152,  24, 195,  74,  65, 
    248, 209,   1,   0,   0,   0, 
     92,  16,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    160,   8,   0,   0, 176,   8, 
      0,   0, 192,   8,   0,   0, 
    192,  15,   0,   0,  82,  68, 
     69,  70, 100,   8,   0,   0, 
      1,   0,   0,   0,  12,   1, 
      0,   0,   4,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  67,   0,   1,   0,   0, 
     60,   8,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    188,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 208,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   5,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      5,   0,   0,   0, 230,   0, 
      0,   0,   4,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    246,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 103,  95,  80, 111, 
    105, 110, 116,  67, 108,  97, 
    109, 112,  83,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
     73, 109, 112, 111, 114, 116, 
     97, 110,  99, 101,  70, 105, 
    110,  97, 108,  83,  83,  65, 
     79,   0, 103,  95,  73, 109, 
    112, 111, 114, 116,  97, 110, 
     99, 101,  79, 117, 116,   0, 
     83,  83,  65,  79,  67, 111, 
    110, 115, 116,  97, 110, 116, 
    115,  66, 117, 102, 102, 101, 
    114,   0, 171, 171, 246,   0, 
      0,   0,   1,   0,   0,   0, 
     36,   1,   0,   0, 128,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  76,   1, 
      0,   0,   0,   0,   0,   0, 
    128,   1,   0,   0,   2,   0, 
      0,   0,  24,   8,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 103,  95,  67,  65, 
     67,  65,  79,  67, 111, 110, 
    115, 116, 115,   0,  67,  65, 
     67,  65,  79,  67, 111, 110, 
    115, 116,  97, 110, 116, 115, 
      0,  68, 101, 112, 116, 104, 
     85, 110, 112,  97,  99, 107, 
     67, 111, 110, 115, 116, 115, 
      0, 102, 108, 111,  97, 116, 
     50,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    123,   1,   0,   0,  67,  97, 
    109, 101, 114,  97,  84,  97, 
    110,  72,  97, 108, 102,  70, 
     79,  86,   0,  78,  68,  67, 
     84, 111,  86, 105, 101, 119, 
     77, 117, 108,   0,  78,  68, 
     67,  84, 111,  86, 105, 101, 
    119,  65, 100, 100,   0,  68, 
    101, 112, 116, 104,  66, 117, 
    102, 102, 101, 114,  85,  86, 
     84, 111,  86, 105, 101, 119, 
     77, 117, 108,   0,  68, 101, 
    112, 116, 104,  66, 117, 102, 
    102, 101, 114,  85,  86,  84, 
    111,  86, 105, 101, 119,  65, 
    100, 100,   0,  69, 102, 102, 
    101,  99, 116,  82,  97, 100, 
    105, 117, 115,   0, 102, 108, 
    111,  97, 116,   0,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     14,   2,   0,   0,  69, 102, 
    102, 101,  99, 116,  83, 104, 
     97, 100, 111, 119,  83, 116, 
    114, 101, 110, 103, 116, 104, 
      0,  69, 102, 102, 101,  99, 
    116,  83, 104,  97, 100, 111, 
    119,  80, 111, 119,   0,  69, 
    102, 102, 101,  99, 116,  83, 
    104,  97, 100, 111, 119,  67, 
    108,  97, 109, 112,   0,  69, 
    102, 102, 101,  99, 116,  70, 
     97, 100, 101,  79, 117, 116, 
     77, 117, 108,   0,  69, 102, 
    102, 101,  99, 116,  70,  97, 
    100, 101,  79, 117, 116,  65, 
    100, 100,   0,  69, 102, 102, 
    101,  99, 116,  72, 111, 114, 
    105, 122, 111, 110,  65, 110, 
    103, 108, 101,  84, 104, 114, 
    101, 115, 104, 111, 108, 100, 
      0,  69, 102, 102, 101,  99, 
    116,  83,  97, 109, 112, 108, 
    105, 110, 103,  82,  97, 100, 
    105, 117, 115,  78, 101,  97, 
    114,  76, 105, 109, 105, 116, 
     82, 101,  99,   0,  68, 101, 
    112, 116, 104,  80, 114, 101, 
     99, 105, 115, 105, 111, 110, 
     79, 102, 102, 115, 101, 116, 
     77, 111, 100,   0,  78, 101, 
    103,  82, 101,  99,  69, 102, 
    102, 101,  99, 116,  82,  97, 
    100, 105, 117, 115,   0,  76, 
    111,  97, 100,  67, 111, 117, 
    110, 116, 101, 114,  65, 118, 
    103,  68, 105, 118,   0,  65, 
    100,  97, 112, 116, 105, 118, 
    101,  83,  97, 109, 112, 108, 
    101,  67, 111, 117, 110, 116, 
     76, 105, 109, 105, 116,   0, 
     73, 110, 118,  83, 104,  97, 
    114, 112, 110, 101, 115, 115, 
      0,  80,  97, 115, 115,  73, 
    110, 100, 101, 120,   0, 105, 
    110, 116,   0, 171,   0,   0, 
      2,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     59,   3,   0,   0,  66, 105, 
    108,  97, 116, 101, 114,  97, 
    108,  83, 105, 103, 109,  97, 
     83, 113, 117,  97, 114, 101, 
    100,   0,  66, 105, 108,  97, 
    116, 101, 114,  97, 108,  83, 
    105, 109, 105, 108,  97, 114, 
    105, 116, 121,  68, 105, 115, 
    116,  97, 110,  99, 101,  83, 
    105, 103, 109,  97,   0,  80, 
     97, 116, 116, 101, 114, 110, 
     82, 111, 116,  83,  99,  97, 
    108, 101,  77,  97, 116, 114, 
    105,  99, 101, 115,   0, 102, 
    108, 111,  97, 116,  52,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 179,   3, 
      0,   0,  78, 111, 114, 109, 
     97, 108, 115,  85, 110, 112, 
     97,  99, 107,  77, 117, 108, 
      0,  78, 111, 114, 109,  97, 
    108, 115,  85, 110, 112,  97, 
     99, 107,  65, 100, 100,   0, 
     68, 101, 116,  97, 105, 108, 
     65,  79,  83, 116, 114, 101, 
    110, 103, 116, 104,   0,  68, 
    117, 109, 109, 121,  48,   0, 
     83,  83,  65,  79,  66, 117, 
    102, 102, 101, 114,  68, 105, 
    109, 101, 110, 115, 105, 111, 
    110, 115,   0,  83,  83,  65, 
     79,  66, 117, 102, 102, 101, 
    114,  73, 110, 118, 101, 114, 
    115, 101,  68, 105, 109, 101, 
    110, 115, 105, 111, 110, 115, 
      0,  68, 101, 112, 116, 104, 
     66, 117, 102, 102, 101, 114, 
     68, 105, 109, 101, 110, 115, 
    105, 111, 110, 115,   0,  68, 
    101, 112, 116, 104,  66, 117, 
    102, 102, 101, 114,  73, 110, 
    118, 101, 114, 115, 101,  68, 
    105, 109, 101, 110, 115, 105, 
    111, 110, 115,   0,  68, 101, 
    112, 116, 104,  66, 117, 102, 
    102, 101, 114,  79, 102, 102, 
    115, 101, 116,   0, 105, 110, 
    116,  50,   0, 171, 171, 171, 
      1,   0,   2,   0,   1,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 144,   4,   0,   0, 
     80, 101, 114,  80,  97, 115, 
    115,  70, 117, 108, 108,  82, 
    101, 115,  85,  86,  79, 102, 
    102, 115, 101, 116,   0,  79, 
    117, 116, 112, 117, 116,  66, 
    117, 102, 102, 101, 114,  68, 
    105, 109, 101, 110, 115, 105, 
    111, 110, 115,   0,  79, 117, 
    116, 112, 117, 116,  66, 117, 
    102, 102, 101, 114,  73, 110, 
    118, 101, 114, 115, 101,  68, 
    105, 109, 101, 110, 115, 105, 
    111, 110, 115,   0,  73, 109, 
    112, 111, 114, 116,  97, 110, 
     99, 101,  77,  97, 112,  68, 
    105, 109, 101, 110, 115, 105, 
    111, 110, 115,   0,  73, 109, 
    112, 111, 114, 116,  97, 110, 
     99, 101,  77,  97, 112,  73, 
    110, 118, 101, 114, 115, 101, 
     68, 105, 109, 101, 110, 115, 
    105, 111, 110, 115,   0,  68, 
    101, 105, 110, 116, 101, 114, 
    108, 101,  97, 118, 101, 100, 
     68, 101, 112, 116, 104,  66, 
    117, 102, 102, 101, 114,  68, 
    105, 109, 101, 110, 115, 105, 
    111, 110, 115,   0,  68, 101, 
    105, 110, 116, 101, 114, 108, 
    101,  97, 118, 101, 100,  68, 
    101, 112, 116, 104,  66, 117, 
    102, 102, 101, 114,  73, 110, 
    118, 101, 114, 115, 101,  68, 
    105, 109, 101, 110, 115, 105, 
    111, 110, 115,   0,  68, 101, 
    105, 110, 116, 101, 114, 108, 
    101,  97, 118, 101, 100,  68, 
    101, 112, 116, 104,  66, 117, 
    102, 102, 101, 114,  79, 102, 
    102, 115, 101, 116,   0,  68, 
    101, 105, 110, 116, 101, 114, 
    108, 101,  97, 118, 101, 100, 
     68, 101, 112, 116, 104,  66, 
    117, 102, 102, 101, 114,  78, 
    111, 114, 109,  97, 108, 105, 
    115, 101, 100,  79, 102, 102, 
    115, 101, 116,   0,  78, 111, 
    114, 109,  97, 108, 115,  87, 
    111, 114, 108, 100,  84, 111, 
     86, 105, 101, 119, 115, 112, 
     97,  99, 101,  77,  97, 116, 
    114, 105, 120,   0, 102, 108, 
    111,  97, 116,  52, 120,  52, 
      0, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 242,   5, 
      0,   0, 105,   1,   0,   0, 
    132,   1,   0,   0,   0,   0, 
      0,   0, 168,   1,   0,   0, 
    132,   1,   0,   0,   8,   0, 
      0,   0, 185,   1,   0,   0, 
    132,   1,   0,   0,  16,   0, 
      0,   0, 198,   1,   0,   0, 
    132,   1,   0,   0,  24,   0, 
      0,   0, 211,   1,   0,   0, 
    132,   1,   0,   0,  32,   0, 
      0,   0, 234,   1,   0,   0, 
    132,   1,   0,   0,  40,   0, 
      0,   0,   1,   2,   0,   0, 
     20,   2,   0,   0,  48,   0, 
      0,   0,  56,   2,   0,   0, 
     20,   2,   0,   0,  52,   0, 
      0,   0,  77,   2,   0,   0, 
     20,   2,   0,   0,  56,   0, 
      0,   0,  93,   2,   0,   0, 
     20,   2,   0,   0,  60,   0, 
      0,   0, 111,   2,   0,   0, 
     20,   2,   0,   0,  64,   0, 
      0,   0, 128,   2,   0,   0, 
     20,   2,   0,   0,  68,   0, 
      0,   0, 145,   2,   0,   0, 
     20,   2,   0,   0,  72,   0, 
      0,   0, 173,   2,   0,   0, 
     20,   2,   0,   0,  76,   0, 
      0,   0, 206,   2,   0,   0, 
     20,   2,   0,   0,  80,   0, 
      0,   0, 230,   2,   0,   0, 
     20,   2,   0,   0,  84,   0, 
      0,   0, 249,   2,   0,   0, 
     20,   2,   0,   0,  88,   0, 
      0,   0,  11,   3,   0,   0, 
     20,   2,   0,   0,  92,   0, 
      0,   0,  36,   3,   0,   0, 
     20,   2,   0,   0,  96,   0, 
      0,   0,  49,   3,   0,   0, 
     64,   3,   0,   0, 100,   0, 
      0,   0, 100,   3,   0,   0, 
     20,   2,   0,   0, 104,   0, 
      0,   0, 122,   3,   0,   0, 
     20,   2,   0,   0, 108,   0, 
      0,   0, 155,   3,   0,   0, 
    188,   3,   0,   0, 112,   0, 
      0,   0, 224,   3,   0,   0, 
     20,   2,   0,   0, 192,   0, 
      0,   0, 241,   3,   0,   0, 
     20,   2,   0,   0, 196,   0, 
      0,   0,   2,   4,   0,   0, 
     20,   2,   0,   0, 200,   0, 
      0,   0,  19,   4,   0,   0, 
     20,   2,   0,   0, 204,   0, 
      0,   0,  26,   4,   0,   0, 
    132,   1,   0,   0, 208,   0, 
      0,   0,  47,   4,   0,   0, 
    132,   1,   0,   0, 216,   0, 
      0,   0,  75,   4,   0,   0, 
    132,   1,   0,   0, 224,   0, 
      0,   0,  97,   4,   0,   0, 
    132,   1,   0,   0, 232,   0, 
      0,   0, 126,   4,   0,   0, 
    152,   4,   0,   0, 240,   0, 
      0,   0, 188,   4,   0,   0, 
    132,   1,   0,   0, 248,   0, 
      0,   0, 211,   4,   0,   0, 
    132,   1,   0,   0,   0,   1, 
      0,   0, 234,   4,   0,   0, 
    132,   1,   0,   0,   8,   1, 
      0,   0,   8,   5,   0,   0, 
    132,   1,   0,   0,  16,   1, 
      0,   0,  32,   5,   0,   0, 
    132,   1,   0,   0,  24,   1, 
      0,   0,  63,   5,   0,   0, 
    132,   1,   0,   0,  32,   1, 
      0,   0,  98,   5,   0,   0, 
    132,   1,   0,   0,  40,   1, 
      0,   0, 140,   5,   0,   0, 
    132,   1,   0,   0,  48,   1, 
      0,   0, 171,   5,   0,   0, 
    132,   1,   0,   0,  56,   1, 
      0,   0, 212,   5,   0,   0, 
    252,   5,   0,   0,  64,   1, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  96,   0,   0,   0, 
     42,   0,  32,   6,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  90,   1, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
     73,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  79,  83, 
     71,  78,   8,   0,   0,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  83,  72,  69,  88, 
    248,   6,   0,   0,  80,   0, 
      5,   0, 190,   1,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  88,  64,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
    156,  24,   0,   4,   0, 224, 
     17,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  95,   0, 
      0,   2,  50,   0,   2,   0, 
    104,   0,   0,   2,   4,   0, 
      0,   0, 155,   0,   0,   4, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,   0, 
     41,   0,   0,   9,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,   2,   0,   2,  64, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     86,   0,   0,   5,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  63, 
      0,   0,   0,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   0,   0,   8,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0, 230, 138,  32,   0, 
      0,   0,   0,   0,  13,   0, 
      0,   0,  54,   0,   0,   8, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63, 109,   0, 
      0, 139,   2,   2,   0, 128, 
     67,  85,  21,   0, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,  10,  96, 
     16,   0,   0,   0,   0,   0, 
    109,   0,   0, 139,   2,   2, 
      0, 128,  67,  85,  21,   0, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,   3,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
     10,  96,  16,   0,   0,   0, 
      0,   0,  50,  32,   0,  14, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  86, 133,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  47,   0, 
      0,   5, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0, 166, 138,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  25,   0,   0,   5, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  50,  32, 
      0,  14, 242,   0,  16,   0, 
      1,   0,   0,   0,  86, 133, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     47,   0,   0,   5, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0, 166, 138, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  25,   0, 
      0,   5, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     51,   0,   0,   7,  50,   0, 
     16,   0,   3,   0,   0,   0, 
    214,   5,  16,   0,   1,   0, 
      0,   0, 134,   0,  16,   0, 
      1,   0,   0,   0,  52,   0, 
      0,   7,  50,   0,  16,   0, 
      1,   0,   0,   0, 214,   5, 
     16,   0,   1,   0,   0,   0, 
    134,   0,  16,   0,   1,   0, 
      0,   0,  52,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     51,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  51,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  51,   0,   0,   7, 
    194,   0,  16,   0,   1,   0, 
      0,   0,  86,  13,  16,   0, 
      2,   0,   0,   0,   6,   8, 
     16,   0,   2,   0,   0,   0, 
     52,   0,   0,   7,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    214,   5,  16,   0,   2,   0, 
      0,   0, 134,   0,  16,   0, 
      2,   0,   0,   0,  52,   0, 
      0,   7,  18,   0,  16,   0, 
      2,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  52,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     51,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  51,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   8, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  64, 
      0,   0,  64,  64, 109,   0, 
      0, 139,   2,   2,   0, 128, 
     67,  85,  21,   0, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,  10,  96, 
     16,   0,   0,   0,   0,   0, 
    109,   0,   0, 139,   2,   2, 
      0, 128,  67,  85,  21,   0, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,   3,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
     10,  96,  16,   0,   0,   0, 
      0,   0,  50,  32,   0,  14, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  86, 133,  32, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  47,   0, 
      0,   5, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0, 166, 138,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  25,   0,   0,   5, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  50,  32, 
      0,  14, 242,   0,  16,   0, 
      2,   0,   0,   0,  86, 133, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     47,   0,   0,   5, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0, 166, 138, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  25,   0, 
      0,   5, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     51,   0,   0,   7, 194,   0, 
     16,   0,   1,   0,   0,   0, 
     86,  13,  16,   0,   2,   0, 
      0,   0,   6,   8,  16,   0, 
      2,   0,   0,   0,  52,   0, 
      0,   7,  50,   0,  16,   0, 
      2,   0,   0,   0, 214,   5, 
     16,   0,   2,   0,   0,   0, 
    134,   0,  16,   0,   2,   0, 
      0,   0,  52,   0,   0,   7, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     52,   0,   0,   7,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  51,   0, 
      0,   7,  66,   0,  16,   0, 
      1,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  51,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     51,   0,   0,   7, 194,   0, 
     16,   0,   1,   0,   0,   0, 
     86,  13,  16,   0,   0,   0, 
      0,   0,   6,   8,  16,   0, 
      0,   0,   0,   0,  52,   0, 
      0,   7,  50,   0,  16,   0, 
      0,   0,   0,   0, 214,   5, 
     16,   0,   0,   0,   0,   0, 
    134,   0,  16,   0,   0,   0, 
      0,   0,  52,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     52,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  51,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  51,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   0,  32,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     47,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0, 205, 204,  76,  63, 
     25,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0, 164,   0,   0,   6, 
    242, 224,  17,   0,   0,   0, 
      0,   0,  70,   5,   2,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0,  56,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     46,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0
};