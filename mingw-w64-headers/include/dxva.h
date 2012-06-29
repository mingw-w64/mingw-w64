/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_DXVA
#define _INC_DXVA

#include <objbase.h>
#include <guiddef.h>
#ifdef __cplusplus
extern "C" {
#endif

DEFINE_GUID(DXVA_NoEncrypt, 0x1b81bed0, 0xa0c7,0x11d3, 0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

/* DXVA H264 */
typedef struct {
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            UCHAR Index7Bits     : 7;
            UCHAR AssociatedFlag : 1;
        };
        UCHAR bPicEntry;
    };
} DXVA_PicEntry_H264;

#pragma pack(push, 1)
typedef struct {
    USHORT  wFrameWidthInMbsMinus1;
    USHORT  wFrameHeightInMbsMinus1;
    DXVA_PicEntry_H264 InPic;
    DXVA_PicEntry_H264 OutPic;
    USHORT  PicOrderCnt_offset;
    INT     CurrPicOrderCnt;
    UINT    StatusReportFeedbackNumber;
    UCHAR   model_id;
    UCHAR   separate_colour_description_present_flag;
    UCHAR   film_grain_bit_depth_luma_minus8;
    UCHAR   film_grain_bit_depth_chroma_minus8;
    UCHAR   film_grain_full_range_flag;
    UCHAR   film_grain_colour_primaries;
    UCHAR   film_grain_transfer_characteristics;
    UCHAR   film_grain_matrix_coefficients;
    UCHAR   blending_mode_id;
    UCHAR   log2_scale_factor;
    UCHAR   comp_model_present_flag[4];
    UCHAR   num_intensity_intervals_minus1[4];
    UCHAR   num_model_values_minus1[4];
    UCHAR   intensity_interval_lower_bound[3][16];
    UCHAR   intensity_interval_upper_bound[3][16];
    SHORT   comp_model_value[3][16][8];
} DXVA_FilmGrainChar_H264;
#pragma pack(pop)

/* DXVA MPEG-I/II and VC-1 */
typedef struct _DXVA_PictureParameters {
    USHORT  wDecodedPictureIndex;
    USHORT  wDeblockedPictureIndex;
    USHORT  wForwardRefPictureIndex;
    USHORT  wBackwardRefPictureIndex;
    USHORT  wPicWidthInMBminus1;
    USHORT  wPicHeightInMBminus1;
    UCHAR   bMacroblockWidthMinus1;
    UCHAR   bMacroblockHeightMinus1;
    UCHAR   bBlockWidthMinus1;
    UCHAR   bBlockHeightMinus1;
    UCHAR   bBPPminus1;
    UCHAR   bPicStructure;
    UCHAR   bSecondField;
    UCHAR   bPicIntra;
    UCHAR   bPicBackwardPrediction;
    UCHAR   bBidirectionalAveragingMode;
    UCHAR   bMVprecisionAndChromaRelation;
    UCHAR   bChromaFormat;
    UCHAR   bPicScanFixed;
    UCHAR   bPicScanMethod;
    UCHAR   bPicReadbackRequests;
    UCHAR   bRcontrol;
    UCHAR   bPicSpatialResid8;
    UCHAR   bPicOverflowBlocks;
    UCHAR   bPicExtrapolation;
    UCHAR   bPicDeblocked;
    UCHAR   bPicDeblockConfined;
    UCHAR   bPic4MVallowed;
    UCHAR   bPicOBMC;
    UCHAR   bPicBinPB;
    UCHAR   bMV_RPS;
    UCHAR   bReservedBits;
    USHORT  wBitstreamFcodes;
    USHORT  wBitstreamPCEelements;
    UCHAR   bBitstreamConcealmentNeed;
    UCHAR   bBitstreamConcealmentMethod;
} DXVA_PictureParameters, *LPDXVA_PictureParameters;

typedef struct _DXVA_QmatrixData {
    BYTE    bNewQmatrix[4];
    WORD    Qmatrix[4][8 * 8];
} DXVA_QmatrixData, *LPDXVA_QmatrixData;

#pragma pack(push, 1)
typedef struct _DXVA_SliceInfo {
    USHORT  wHorizontalPosition;
    USHORT  wVerticalPosition;
    UINT    dwSliceBitsInBuffer;
    UINT    dwSliceDataLocation;
    UCHAR   bStartCodeBitOffset;
    UCHAR   bReservedBits;
    USHORT  wMBbitOffset;
    USHORT  wNumberMBsInSlice;
    USHORT  wQuantizerScaleCode;
    USHORT  wBadSliceChopping;
} DXVA_SliceInfo, *LPDXVA_SliceInfo;
#pragma pack(pop)

typedef struct {
    USHORT wFrameWidthInMbsMinus1;
    USHORT wFrameHeightInMbsMinus1;
    DXVA_PicEntry_H264 CurrPic;
    UCHAR  num_ref_frames;
    __C89_NAMELESS union {
        __C89_NAMELESS struct {
            USHORT field_pic_flag           : 1;
            USHORT MbaffFrameFlag           : 1;
            USHORT residual_colour_transform_flag : 1;
            USHORT sp_for_switch_flag       : 1;
            USHORT chroma_format_idc        : 2;
            USHORT RefPicFlag               : 1;
            USHORT constrained_intra_pred_flag : 1;
            USHORT weighted_pred_flag       : 1;
            USHORT weighted_bipred_idc      : 2;
            USHORT MbsConsecutiveFlag       : 1;
            USHORT frame_mbs_only_flag      : 1;
            USHORT transform_8x8_mode_flag  : 1;
            USHORT MinLumaBipredSize8x8Flag : 1;
            USHORT IntraPicFlag             : 1;
        };
        USHORT wBitFields;
    };
    UCHAR   bit_depth_luma_minus8;
    UCHAR   bit_depth_chroma_minus8;
    USHORT  Reserved16Bits;
    UINT    StatusReportFeedbackNumber;
    DXVA_PicEntry_H264 RefFrameList[16];
    INT     CurrFieldOrderCnt[2];
    INT     FieldOrderCntList[16][2];
    CHAR    pic_init_qs_minus26;
    CHAR    chroma_qp_index_offset;
    CHAR    second_chroma_qp_index_offset;
    UCHAR   ContinuationFlag;
    CHAR    pic_init_qp_minus26;
    UCHAR   num_ref_idx_l0_active_minus1;
    UCHAR   num_ref_idx_l1_active_minus1;
    UCHAR   Reserved8BitsA;
    USHORT  FrameNumList[16];
    UINT    UsedForReferenceFlags;
    USHORT  NonExistingFrameFlags;
    USHORT  frame_num;
    UCHAR   log2_max_frame_num_minus4;
    UCHAR   pic_order_cnt_type;
    UCHAR   log2_max_pic_order_cnt_lsb_minus4;
    UCHAR   delta_pic_order_always_zero_flag;
    UCHAR   direct_8x8_inference_flag;
    UCHAR   entropy_coding_mode_flag;
    UCHAR   pic_order_present_flag;
    UCHAR   num_slice_groups_minus1;
    UCHAR   slice_group_map_type;
    UCHAR   deblocking_filter_control_present_flag;
    UCHAR   redundant_pic_cnt_present_flag;
    UCHAR   Reserved8BitsB;
    USHORT  slice_group_change_rate_minus1;
    UCHAR   SliceGroupMap[810];
} DXVA_PicParams_H264;

typedef struct {
    UCHAR   bScalingLists4x4[6][16];
    UCHAR   bScalingLists8x8[2][64];
} DXVA_Qmatrix_H264;

typedef struct {
    UINT    BSNALunitDataLocation;
    UINT    SliceBytesInBuffer;
    USHORT  wBadSliceChopping;
    USHORT  first_mb_in_slice;
    USHORT  NumMbsForSlice;
    USHORT  BitOffsetToSliceData;
    UCHAR   slice_type;
    UCHAR   luma_log2_weight_denom;
    UCHAR   chroma_log2_weight_denom;
    UCHAR   num_ref_idx_l0_active_minus1;
    UCHAR   num_ref_idx_l1_active_minus1;
    CHAR    slice_alpha_c0_offset_div2;
    CHAR    slice_beta_offset_div2;
    UCHAR   Reserved8Bits;
    DXVA_PicEntry_H264 RefPicList[2][32];
    SHORT   Weights[2][32][3][2];
    CHAR    slice_qs_delta;
    CHAR    slice_qp_delta;
    UCHAR   redundant_pic_cnt;
    UCHAR   direct_spatial_mv_pred_flag;
    UCHAR   cabac_init_idc;
    UCHAR   disable_deblocking_filter_idc;
    USHORT  slice_id;
} DXVA_Slice_H264_Long;

#pragma pack(push, 1)
typedef struct {
    UINT    BSNALunitDataLocation;
    UINT    SliceBytesInBuffer;
    USHORT  wBadSliceChopping;
} DXVA_Slice_H264_Short;
#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /*_INC_DXVA */
