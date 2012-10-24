#ifndef	_DECODE_H_
#define	_DECODE_H_

#include "common.h"

void decode_info(Bit_stream_struc*, frame_params*);
void III_get_side_info(Bit_stream_struc *bs, III_side_info_t *si, frame_params *fr_ps);
void III_get_scale_factors(III_scalefac_t *scalefac, III_side_info_t *si, int gr, int ch, frame_params *fr_ps);

void initialize_huffman();
void III_hufman_decode(long int is[SBLIMIT][SSLIMIT], III_side_info_t *si, int ch, int gr, int part2_start, frame_params *fr_ps);

void III_dequantize_sample(long int[SBLIMIT][SSLIMIT], double [SBLIMIT][SSLIMIT], III_scalefac_t *, struct gr_info_s *, int, frame_params *);
void III_reorder(double xr[SBLIMIT][SSLIMIT], double ro[SBLIMIT][SSLIMIT], struct gr_info_s *gr_info, frame_params *fr_ps);
void III_stereo(double xr[2][SBLIMIT][SSLIMIT], double lr[2][SBLIMIT][SSLIMIT], III_scalefac_t *scalefac, struct gr_info_s *gr_info, frame_params *fr_ps);
void III_antialias(double xr[SBLIMIT][SSLIMIT], double hybridIn[SBLIMIT][SSLIMIT], struct gr_info_s *gr_info, frame_params *fr_ps);

void inv_mdct(double in[18], double out[36], int block_type);
void III_hybrid(double fsIn[SSLIMIT], double tsOut[SSLIMIT], int sb, int ch, struct gr_info_s *gr_info, frame_params *fr_ps);

void create_syn_filter(double filter[64][SBLIMIT]);
void read_syn_window(double window[HAN_SIZE]);
int SubBandSynthesis (double *bandPtr, int channel, short *samples);

void out_fifo(short pcm_sample[2][SSLIMIT][SBLIMIT], int num, frame_params *fr_ps, int done, FILE *outFile, unsigned long *psampFrames);
void buffer_CRC(Bit_stream_struc *bs, unsigned int *old_crc);
int main_data_slots(frame_params fr_ps);

#endif	//_DECODE_H_