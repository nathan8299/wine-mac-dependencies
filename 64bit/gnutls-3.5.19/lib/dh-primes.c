/*
 * Copyright (C) 2016 Red Hat, Inc.
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GnuTLS.
 *
 * The GnuTLS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

#include "gnutls_int.h"
#include <gnutls/gnutls.h>

#if defined(ENABLE_DHE) || defined(ENABLE_ANON)

#include "dh.h"

static const unsigned char ffdhe_params_2048[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xAD, 0xF8, 0x54, 0x58, 0xA2, 0xBB, 
	0x4A, 0x9A, 0xAF, 0xDC, 0x56, 0x20, 0x27, 
	0x3D, 0x3C, 0xF1, 0xD8, 0xB9, 0xC5, 0x83, 
	0xCE, 0x2D, 0x36, 0x95, 0xA9, 0xE1, 0x36, 
	0x41, 0x14, 0x64, 0x33, 0xFB, 0xCC, 0x93, 
	0x9D, 0xCE, 0x24, 0x9B, 0x3E, 0xF9, 0x7D, 
	0x2F, 0xE3, 0x63, 0x63, 0x0C, 0x75, 0xD8, 
	0xF6, 0x81, 0xB2, 0x02, 0xAE, 0xC4, 0x61, 
	0x7A, 0xD3, 0xDF, 0x1E, 0xD5, 0xD5, 0xFD, 
	0x65, 0x61, 0x24, 0x33, 0xF5, 0x1F, 0x5F, 
	0x06, 0x6E, 0xD0, 0x85, 0x63, 0x65, 0x55, 
	0x3D, 0xED, 0x1A, 0xF3, 0xB5, 0x57, 0x13, 
	0x5E, 0x7F, 0x57, 0xC9, 0x35, 0x98, 0x4F, 
	0x0C, 0x70, 0xE0, 0xE6, 0x8B, 0x77, 0xE2, 
	0xA6, 0x89, 0xDA, 0xF3, 0xEF, 0xE8, 0x72, 
	0x1D, 0xF1, 0x58, 0xA1, 0x36, 0xAD, 0xE7, 
	0x35, 0x30, 0xAC, 0xCA, 0x4F, 0x48, 0x3A, 
	0x79, 0x7A, 0xBC, 0x0A, 0xB1, 0x82, 0xB3, 
	0x24, 0xFB, 0x61, 0xD1, 0x08, 0xA9, 0x4B, 
	0xB2, 0xC8, 0xE3, 0xFB, 0xB9, 0x6A, 0xDA, 
	0xB7, 0x60, 0xD7, 0xF4, 0x68, 0x1D, 0x4F, 
	0x42, 0xA3, 0xDE, 0x39, 0x4D, 0xF4, 0xAE, 
	0x56, 0xED, 0xE7, 0x63, 0x72, 0xBB, 0x19, 
	0x0B, 0x07, 0xA7, 0xC8, 0xEE, 0x0A, 0x6D, 
	0x70, 0x9E, 0x02, 0xFC, 0xE1, 0xCD, 0xF7, 
	0xE2, 0xEC, 0xC0, 0x34, 0x04, 0xCD, 0x28, 
	0x34, 0x2F, 0x61, 0x91, 0x72, 0xFE, 0x9C, 
	0xE9, 0x85, 0x83, 0xFF, 0x8E, 0x4F, 0x12, 
	0x32, 0xEE, 0xF2, 0x81, 0x83, 0xC3, 0xFE, 
	0x3B, 0x1B, 0x4C, 0x6F, 0xAD, 0x73, 0x3B, 
	0xB5, 0xFC, 0xBC, 0x2E, 0xC2, 0x20, 0x05, 
	0xC5, 0x8E, 0xF1, 0x83, 0x7D, 0x16, 0x83, 
	0xB2, 0xC6, 0xF3, 0x4A, 0x26, 0xC1, 0xB2, 
	0xEF, 0xFA, 0x88, 0x6B, 0x42, 0x38, 0x61, 
	0x28, 0x5C, 0x97, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF
};

const gnutls_datum_t gnutls_ffdhe_2048_group_prime = {
	(void *) ffdhe_params_2048, sizeof(ffdhe_params_2048)
};

static const unsigned char ffdhe_generator = 0x02;

const gnutls_datum_t gnutls_ffdhe_2048_group_generator = {
	(void *) &ffdhe_generator, sizeof(ffdhe_generator)
};
const unsigned int gnutls_ffdhe_2048_key_bits = 256;

static const unsigned char ffdhe_params_3072[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xAD, 0xF8, 0x54, 0x58, 0xA2, 0xBB, 
	0x4A, 0x9A, 0xAF, 0xDC, 0x56, 0x20, 0x27, 
	0x3D, 0x3C, 0xF1, 0xD8, 0xB9, 0xC5, 0x83, 
	0xCE, 0x2D, 0x36, 0x95, 0xA9, 0xE1, 0x36, 
	0x41, 0x14, 0x64, 0x33, 0xFB, 0xCC, 0x93, 
	0x9D, 0xCE, 0x24, 0x9B, 0x3E, 0xF9, 0x7D, 
	0x2F, 0xE3, 0x63, 0x63, 0x0C, 0x75, 0xD8, 
	0xF6, 0x81, 0xB2, 0x02, 0xAE, 0xC4, 0x61, 
	0x7A, 0xD3, 0xDF, 0x1E, 0xD5, 0xD5, 0xFD, 
	0x65, 0x61, 0x24, 0x33, 0xF5, 0x1F, 0x5F, 
	0x06, 0x6E, 0xD0, 0x85, 0x63, 0x65, 0x55, 
	0x3D, 0xED, 0x1A, 0xF3, 0xB5, 0x57, 0x13, 
	0x5E, 0x7F, 0x57, 0xC9, 0x35, 0x98, 0x4F, 
	0x0C, 0x70, 0xE0, 0xE6, 0x8B, 0x77, 0xE2, 
	0xA6, 0x89, 0xDA, 0xF3, 0xEF, 0xE8, 0x72, 
	0x1D, 0xF1, 0x58, 0xA1, 0x36, 0xAD, 0xE7, 
	0x35, 0x30, 0xAC, 0xCA, 0x4F, 0x48, 0x3A, 
	0x79, 0x7A, 0xBC, 0x0A, 0xB1, 0x82, 0xB3, 
	0x24, 0xFB, 0x61, 0xD1, 0x08, 0xA9, 0x4B, 
	0xB2, 0xC8, 0xE3, 0xFB, 0xB9, 0x6A, 0xDA, 
	0xB7, 0x60, 0xD7, 0xF4, 0x68, 0x1D, 0x4F, 
	0x42, 0xA3, 0xDE, 0x39, 0x4D, 0xF4, 0xAE, 
	0x56, 0xED, 0xE7, 0x63, 0x72, 0xBB, 0x19, 
	0x0B, 0x07, 0xA7, 0xC8, 0xEE, 0x0A, 0x6D, 
	0x70, 0x9E, 0x02, 0xFC, 0xE1, 0xCD, 0xF7, 
	0xE2, 0xEC, 0xC0, 0x34, 0x04, 0xCD, 0x28, 
	0x34, 0x2F, 0x61, 0x91, 0x72, 0xFE, 0x9C, 
	0xE9, 0x85, 0x83, 0xFF, 0x8E, 0x4F, 0x12, 
	0x32, 0xEE, 0xF2, 0x81, 0x83, 0xC3, 0xFE, 
	0x3B, 0x1B, 0x4C, 0x6F, 0xAD, 0x73, 0x3B, 
	0xB5, 0xFC, 0xBC, 0x2E, 0xC2, 0x20, 0x05, 
	0xC5, 0x8E, 0xF1, 0x83, 0x7D, 0x16, 0x83, 
	0xB2, 0xC6, 0xF3, 0x4A, 0x26, 0xC1, 0xB2, 
	0xEF, 0xFA, 0x88, 0x6B, 0x42, 0x38, 0x61, 
	0x1F, 0xCF, 0xDC, 0xDE, 0x35, 0x5B, 0x3B, 
	0x65, 0x19, 0x03, 0x5B, 0xBC, 0x34, 0xF4, 
	0xDE, 0xF9, 0x9C, 0x02, 0x38, 0x61, 0xB4, 
	0x6F, 0xC9, 0xD6, 0xE6, 0xC9, 0x07, 0x7A, 
	0xD9, 0x1D, 0x26, 0x91, 0xF7, 0xF7, 0xEE, 
	0x59, 0x8C, 0xB0, 0xFA, 0xC1, 0x86, 0xD9, 
	0x1C, 0xAE, 0xFE, 0x13, 0x09, 0x85, 0x13, 
	0x92, 0x70, 0xB4, 0x13, 0x0C, 0x93, 0xBC, 
	0x43, 0x79, 0x44, 0xF4, 0xFD, 0x44, 0x52, 
	0xE2, 0xD7, 0x4D, 0xD3, 0x64, 0xF2, 0xE2, 
	0x1E, 0x71, 0xF5, 0x4B, 0xFF, 0x5C, 0xAE, 
	0x82, 0xAB, 0x9C, 0x9D, 0xF6, 0x9E, 0xE8, 
	0x6D, 0x2B, 0xC5, 0x22, 0x36, 0x3A, 0x0D, 
	0xAB, 0xC5, 0x21, 0x97, 0x9B, 0x0D, 0xEA, 
	0xDA, 0x1D, 0xBF, 0x9A, 0x42, 0xD5, 0xC4, 
	0x48, 0x4E, 0x0A, 0xBC, 0xD0, 0x6B, 0xFA, 
	0x53, 0xDD, 0xEF, 0x3C, 0x1B, 0x20, 0xEE, 
	0x3F, 0xD5, 0x9D, 0x7C, 0x25, 0xE4, 0x1D, 
	0x2B, 0x66, 0xC6, 0x2E, 0x37, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const gnutls_datum_t gnutls_ffdhe_3072_group_generator = {
	(void *) &ffdhe_generator, sizeof(ffdhe_generator)
};

const gnutls_datum_t gnutls_ffdhe_3072_group_prime = {
	(void *) ffdhe_params_3072, sizeof(ffdhe_params_3072)
};
const unsigned int gnutls_ffdhe_3072_key_bits = 276;

static const unsigned char ffdhe_params_4096[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xAD, 0xF8, 0x54, 0x58, 0xA2, 0xBB, 
	0x4A, 0x9A, 0xAF, 0xDC, 0x56, 0x20, 0x27, 
	0x3D, 0x3C, 0xF1, 0xD8, 0xB9, 0xC5, 0x83, 
	0xCE, 0x2D, 0x36, 0x95, 0xA9, 0xE1, 0x36, 
	0x41, 0x14, 0x64, 0x33, 0xFB, 0xCC, 0x93, 
	0x9D, 0xCE, 0x24, 0x9B, 0x3E, 0xF9, 0x7D, 
	0x2F, 0xE3, 0x63, 0x63, 0x0C, 0x75, 0xD8, 
	0xF6, 0x81, 0xB2, 0x02, 0xAE, 0xC4, 0x61, 
	0x7A, 0xD3, 0xDF, 0x1E, 0xD5, 0xD5, 0xFD, 
	0x65, 0x61, 0x24, 0x33, 0xF5, 0x1F, 0x5F, 
	0x06, 0x6E, 0xD0, 0x85, 0x63, 0x65, 0x55, 
	0x3D, 0xED, 0x1A, 0xF3, 0xB5, 0x57, 0x13, 
	0x5E, 0x7F, 0x57, 0xC9, 0x35, 0x98, 0x4F, 
	0x0C, 0x70, 0xE0, 0xE6, 0x8B, 0x77, 0xE2, 
	0xA6, 0x89, 0xDA, 0xF3, 0xEF, 0xE8, 0x72, 
	0x1D, 0xF1, 0x58, 0xA1, 0x36, 0xAD, 0xE7, 
	0x35, 0x30, 0xAC, 0xCA, 0x4F, 0x48, 0x3A, 
	0x79, 0x7A, 0xBC, 0x0A, 0xB1, 0x82, 0xB3, 
	0x24, 0xFB, 0x61, 0xD1, 0x08, 0xA9, 0x4B, 
	0xB2, 0xC8, 0xE3, 0xFB, 0xB9, 0x6A, 0xDA, 
	0xB7, 0x60, 0xD7, 0xF4, 0x68, 0x1D, 0x4F, 
	0x42, 0xA3, 0xDE, 0x39, 0x4D, 0xF4, 0xAE, 
	0x56, 0xED, 0xE7, 0x63, 0x72, 0xBB, 0x19, 
	0x0B, 0x07, 0xA7, 0xC8, 0xEE, 0x0A, 0x6D, 
	0x70, 0x9E, 0x02, 0xFC, 0xE1, 0xCD, 0xF7, 
	0xE2, 0xEC, 0xC0, 0x34, 0x04, 0xCD, 0x28, 
	0x34, 0x2F, 0x61, 0x91, 0x72, 0xFE, 0x9C, 
	0xE9, 0x85, 0x83, 0xFF, 0x8E, 0x4F, 0x12, 
	0x32, 0xEE, 0xF2, 0x81, 0x83, 0xC3, 0xFE, 
	0x3B, 0x1B, 0x4C, 0x6F, 0xAD, 0x73, 0x3B, 
	0xB5, 0xFC, 0xBC, 0x2E, 0xC2, 0x20, 0x05, 
	0xC5, 0x8E, 0xF1, 0x83, 0x7D, 0x16, 0x83, 
	0xB2, 0xC6, 0xF3, 0x4A, 0x26, 0xC1, 0xB2, 
	0xEF, 0xFA, 0x88, 0x6B, 0x42, 0x38, 0x61, 
	0x1F, 0xCF, 0xDC, 0xDE, 0x35, 0x5B, 0x3B, 
	0x65, 0x19, 0x03, 0x5B, 0xBC, 0x34, 0xF4, 
	0xDE, 0xF9, 0x9C, 0x02, 0x38, 0x61, 0xB4, 
	0x6F, 0xC9, 0xD6, 0xE6, 0xC9, 0x07, 0x7A, 
	0xD9, 0x1D, 0x26, 0x91, 0xF7, 0xF7, 0xEE, 
	0x59, 0x8C, 0xB0, 0xFA, 0xC1, 0x86, 0xD9, 
	0x1C, 0xAE, 0xFE, 0x13, 0x09, 0x85, 0x13, 
	0x92, 0x70, 0xB4, 0x13, 0x0C, 0x93, 0xBC, 
	0x43, 0x79, 0x44, 0xF4, 0xFD, 0x44, 0x52, 
	0xE2, 0xD7, 0x4D, 0xD3, 0x64, 0xF2, 0xE2, 
	0x1E, 0x71, 0xF5, 0x4B, 0xFF, 0x5C, 0xAE, 
	0x82, 0xAB, 0x9C, 0x9D, 0xF6, 0x9E, 0xE8, 
	0x6D, 0x2B, 0xC5, 0x22, 0x36, 0x3A, 0x0D, 
	0xAB, 0xC5, 0x21, 0x97, 0x9B, 0x0D, 0xEA, 
	0xDA, 0x1D, 0xBF, 0x9A, 0x42, 0xD5, 0xC4, 
	0x48, 0x4E, 0x0A, 0xBC, 0xD0, 0x6B, 0xFA, 
	0x53, 0xDD, 0xEF, 0x3C, 0x1B, 0x20, 0xEE, 
	0x3F, 0xD5, 0x9D, 0x7C, 0x25, 0xE4, 0x1D, 
	0x2B, 0x66, 0x9E, 0x1E, 0xF1, 0x6E, 0x6F, 
	0x52, 0xC3, 0x16, 0x4D, 0xF4, 0xFB, 0x79, 
	0x30, 0xE9, 0xE4, 0xE5, 0x88, 0x57, 0xB6, 
	0xAC, 0x7D, 0x5F, 0x42, 0xD6, 0x9F, 0x6D, 
	0x18, 0x77, 0x63, 0xCF, 0x1D, 0x55, 0x03, 
	0x40, 0x04, 0x87, 0xF5, 0x5B, 0xA5, 0x7E, 
	0x31, 0xCC, 0x7A, 0x71, 0x35, 0xC8, 0x86, 
	0xEF, 0xB4, 0x31, 0x8A, 0xED, 0x6A, 0x1E, 
	0x01, 0x2D, 0x9E, 0x68, 0x32, 0xA9, 0x07, 
	0x60, 0x0A, 0x91, 0x81, 0x30, 0xC4, 0x6D, 
	0xC7, 0x78, 0xF9, 0x71, 0xAD, 0x00, 0x38, 
	0x09, 0x29, 0x99, 0xA3, 0x33, 0xCB, 0x8B, 
	0x7A, 0x1A, 0x1D, 0xB9, 0x3D, 0x71, 0x40, 
	0x00, 0x3C, 0x2A, 0x4E, 0xCE, 0xA9, 0xF9, 
	0x8D, 0x0A, 0xCC, 0x0A, 0x82, 0x91, 0xCD, 
	0xCE, 0xC9, 0x7D, 0xCF, 0x8E, 0xC9, 0xB5, 
	0x5A, 0x7F, 0x88, 0xA4, 0x6B, 0x4D, 0xB5, 
	0xA8, 0x51, 0xF4, 0x41, 0x82, 0xE1, 0xC6, 
	0x8A, 0x00, 0x7E, 0x5E, 0x65, 0x5F, 0x6A, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF
};

const gnutls_datum_t gnutls_ffdhe_4096_group_generator = {
	(void *) &ffdhe_generator, sizeof(ffdhe_generator)
};

const gnutls_datum_t gnutls_ffdhe_4096_group_prime = {
	(void *) ffdhe_params_4096, sizeof(ffdhe_params_4096)
};
const unsigned int gnutls_ffdhe_4096_key_bits = 336;

static const unsigned char ffdhe_params_8192[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xAD, 0xF8, 0x54, 0x58, 0xA2, 0xBB, 
	0x4A, 0x9A, 0xAF, 0xDC, 0x56, 0x20, 0x27, 
	0x3D, 0x3C, 0xF1, 0xD8, 0xB9, 0xC5, 0x83, 
	0xCE, 0x2D, 0x36, 0x95, 0xA9, 0xE1, 0x36, 
	0x41, 0x14, 0x64, 0x33, 0xFB, 0xCC, 0x93, 
	0x9D, 0xCE, 0x24, 0x9B, 0x3E, 0xF9, 0x7D, 
	0x2F, 0xE3, 0x63, 0x63, 0x0C, 0x75, 0xD8, 
	0xF6, 0x81, 0xB2, 0x02, 0xAE, 0xC4, 0x61, 
	0x7A, 0xD3, 0xDF, 0x1E, 0xD5, 0xD5, 0xFD, 
	0x65, 0x61, 0x24, 0x33, 0xF5, 0x1F, 0x5F, 
	0x06, 0x6E, 0xD0, 0x85, 0x63, 0x65, 0x55, 
	0x3D, 0xED, 0x1A, 0xF3, 0xB5, 0x57, 0x13, 
	0x5E, 0x7F, 0x57, 0xC9, 0x35, 0x98, 0x4F, 
	0x0C, 0x70, 0xE0, 0xE6, 0x8B, 0x77, 0xE2, 
	0xA6, 0x89, 0xDA, 0xF3, 0xEF, 0xE8, 0x72, 
	0x1D, 0xF1, 0x58, 0xA1, 0x36, 0xAD, 0xE7, 
	0x35, 0x30, 0xAC, 0xCA, 0x4F, 0x48, 0x3A, 
	0x79, 0x7A, 0xBC, 0x0A, 0xB1, 0x82, 0xB3, 
	0x24, 0xFB, 0x61, 0xD1, 0x08, 0xA9, 0x4B, 
	0xB2, 0xC8, 0xE3, 0xFB, 0xB9, 0x6A, 0xDA, 
	0xB7, 0x60, 0xD7, 0xF4, 0x68, 0x1D, 0x4F, 
	0x42, 0xA3, 0xDE, 0x39, 0x4D, 0xF4, 0xAE, 
	0x56, 0xED, 0xE7, 0x63, 0x72, 0xBB, 0x19, 
	0x0B, 0x07, 0xA7, 0xC8, 0xEE, 0x0A, 0x6D, 
	0x70, 0x9E, 0x02, 0xFC, 0xE1, 0xCD, 0xF7, 
	0xE2, 0xEC, 0xC0, 0x34, 0x04, 0xCD, 0x28, 
	0x34, 0x2F, 0x61, 0x91, 0x72, 0xFE, 0x9C, 
	0xE9, 0x85, 0x83, 0xFF, 0x8E, 0x4F, 0x12, 
	0x32, 0xEE, 0xF2, 0x81, 0x83, 0xC3, 0xFE, 
	0x3B, 0x1B, 0x4C, 0x6F, 0xAD, 0x73, 0x3B, 
	0xB5, 0xFC, 0xBC, 0x2E, 0xC2, 0x20, 0x05, 
	0xC5, 0x8E, 0xF1, 0x83, 0x7D, 0x16, 0x83, 
	0xB2, 0xC6, 0xF3, 0x4A, 0x26, 0xC1, 0xB2, 
	0xEF, 0xFA, 0x88, 0x6B, 0x42, 0x38, 0x61, 
	0x1F, 0xCF, 0xDC, 0xDE, 0x35, 0x5B, 0x3B, 
	0x65, 0x19, 0x03, 0x5B, 0xBC, 0x34, 0xF4, 
	0xDE, 0xF9, 0x9C, 0x02, 0x38, 0x61, 0xB4, 
	0x6F, 0xC9, 0xD6, 0xE6, 0xC9, 0x07, 0x7A, 
	0xD9, 0x1D, 0x26, 0x91, 0xF7, 0xF7, 0xEE, 
	0x59, 0x8C, 0xB0, 0xFA, 0xC1, 0x86, 0xD9, 
	0x1C, 0xAE, 0xFE, 0x13, 0x09, 0x85, 0x13, 
	0x92, 0x70, 0xB4, 0x13, 0x0C, 0x93, 0xBC, 
	0x43, 0x79, 0x44, 0xF4, 0xFD, 0x44, 0x52, 
	0xE2, 0xD7, 0x4D, 0xD3, 0x64, 0xF2, 0xE2, 
	0x1E, 0x71, 0xF5, 0x4B, 0xFF, 0x5C, 0xAE, 
	0x82, 0xAB, 0x9C, 0x9D, 0xF6, 0x9E, 0xE8, 
	0x6D, 0x2B, 0xC5, 0x22, 0x36, 0x3A, 0x0D, 
	0xAB, 0xC5, 0x21, 0x97, 0x9B, 0x0D, 0xEA, 
	0xDA, 0x1D, 0xBF, 0x9A, 0x42, 0xD5, 0xC4, 
	0x48, 0x4E, 0x0A, 0xBC, 0xD0, 0x6B, 0xFA, 
	0x53, 0xDD, 0xEF, 0x3C, 0x1B, 0x20, 0xEE, 
	0x3F, 0xD5, 0x9D, 0x7C, 0x25, 0xE4, 0x1D, 
	0x2B, 0x66, 0x9E, 0x1E, 0xF1, 0x6E, 0x6F, 
	0x52, 0xC3, 0x16, 0x4D, 0xF4, 0xFB, 0x79, 
	0x30, 0xE9, 0xE4, 0xE5, 0x88, 0x57, 0xB6, 
	0xAC, 0x7D, 0x5F, 0x42, 0xD6, 0x9F, 0x6D, 
	0x18, 0x77, 0x63, 0xCF, 0x1D, 0x55, 0x03, 
	0x40, 0x04, 0x87, 0xF5, 0x5B, 0xA5, 0x7E, 
	0x31, 0xCC, 0x7A, 0x71, 0x35, 0xC8, 0x86, 
	0xEF, 0xB4, 0x31, 0x8A, 0xED, 0x6A, 0x1E, 
	0x01, 0x2D, 0x9E, 0x68, 0x32, 0xA9, 0x07, 
	0x60, 0x0A, 0x91, 0x81, 0x30, 0xC4, 0x6D, 
	0xC7, 0x78, 0xF9, 0x71, 0xAD, 0x00, 0x38, 
	0x09, 0x29, 0x99, 0xA3, 0x33, 0xCB, 0x8B, 
	0x7A, 0x1A, 0x1D, 0xB9, 0x3D, 0x71, 0x40, 
	0x00, 0x3C, 0x2A, 0x4E, 0xCE, 0xA9, 0xF9, 
	0x8D, 0x0A, 0xCC, 0x0A, 0x82, 0x91, 0xCD, 
	0xCE, 0xC9, 0x7D, 0xCF, 0x8E, 0xC9, 0xB5, 
	0x5A, 0x7F, 0x88, 0xA4, 0x6B, 0x4D, 0xB5, 
	0xA8, 0x51, 0xF4, 0x41, 0x82, 0xE1, 0xC6, 
	0x8A, 0x00, 0x7E, 0x5E, 0x0D, 0xD9, 0x02, 
	0x0B, 0xFD, 0x64, 0xB6, 0x45, 0x03, 0x6C, 
	0x7A, 0x4E, 0x67, 0x7D, 0x2C, 0x38, 0x53, 
	0x2A, 0x3A, 0x23, 0xBA, 0x44, 0x42, 0xCA, 
	0xF5, 0x3E, 0xA6, 0x3B, 0xB4, 0x54, 0x32, 
	0x9B, 0x76, 0x24, 0xC8, 0x91, 0x7B, 0xDD, 
	0x64, 0xB1, 0xC0, 0xFD, 0x4C, 0xB3, 0x8E, 
	0x8C, 0x33, 0x4C, 0x70, 0x1C, 0x3A, 0xCD, 
	0xAD, 0x06, 0x57, 0xFC, 0xCF, 0xEC, 0x71, 
	0x9B, 0x1F, 0x5C, 0x3E, 0x4E, 0x46, 0x04, 
	0x1F, 0x38, 0x81, 0x47, 0xFB, 0x4C, 0xFD, 
	0xB4, 0x77, 0xA5, 0x24, 0x71, 0xF7, 0xA9, 
	0xA9, 0x69, 0x10, 0xB8, 0x55, 0x32, 0x2E, 
	0xDB, 0x63, 0x40, 0xD8, 0xA0, 0x0E, 0xF0, 
	0x92, 0x35, 0x05, 0x11, 0xE3, 0x0A, 0xBE, 
	0xC1, 0xFF, 0xF9, 0xE3, 0xA2, 0x6E, 0x7F, 
	0xB2, 0x9F, 0x8C, 0x18, 0x30, 0x23, 0xC3, 
	0x58, 0x7E, 0x38, 0xDA, 0x00, 0x77, 0xD9, 
	0xB4, 0x76, 0x3E, 0x4E, 0x4B, 0x94, 0xB2, 
	0xBB, 0xC1, 0x94, 0xC6, 0x65, 0x1E, 0x77, 
	0xCA, 0xF9, 0x92, 0xEE, 0xAA, 0xC0, 0x23, 
	0x2A, 0x28, 0x1B, 0xF6, 0xB3, 0xA7, 0x39, 
	0xC1, 0x22, 0x61, 0x16, 0x82, 0x0A, 0xE8, 
	0xDB, 0x58, 0x47, 0xA6, 0x7C, 0xBE, 0xF9, 
	0xC9, 0x09, 0x1B, 0x46, 0x2D, 0x53, 0x8C, 
	0xD7, 0x2B, 0x03, 0x74, 0x6A, 0xE7, 0x7F, 
	0x5E, 0x62, 0x29, 0x2C, 0x31, 0x15, 0x62, 
	0xA8, 0x46, 0x50, 0x5D, 0xC8, 0x2D, 0xB8, 
	0x54, 0x33, 0x8A, 0xE4, 0x9F, 0x52, 0x35, 
	0xC9, 0x5B, 0x91, 0x17, 0x8C, 0xCF, 0x2D, 
	0xD5, 0xCA, 0xCE, 0xF4, 0x03, 0xEC, 0x9D, 
	0x18, 0x10, 0xC6, 0x27, 0x2B, 0x04, 0x5B, 
	0x3B, 0x71, 0xF9, 0xDC, 0x6B, 0x80, 0xD6, 
	0x3F, 0xDD, 0x4A, 0x8E, 0x9A, 0xDB, 0x1E, 
	0x69, 0x62, 0xA6, 0x95, 0x26, 0xD4, 0x31, 
	0x61, 0xC1, 0xA4, 0x1D, 0x57, 0x0D, 0x79, 
	0x38, 0xDA, 0xD4, 0xA4, 0x0E, 0x32, 0x9C, 
	0xCF, 0xF4, 0x6A, 0xAA, 0x36, 0xAD, 0x00, 
	0x4C, 0xF6, 0x00, 0xC8, 0x38, 0x1E, 0x42, 
	0x5A, 0x31, 0xD9, 0x51, 0xAE, 0x64, 0xFD, 
	0xB2, 0x3F, 0xCE, 0xC9, 0x50, 0x9D, 0x43, 
	0x68, 0x7F, 0xEB, 0x69, 0xED, 0xD1, 0xCC, 
	0x5E, 0x0B, 0x8C, 0xC3, 0xBD, 0xF6, 0x4B, 
	0x10, 0xEF, 0x86, 0xB6, 0x31, 0x42, 0xA3, 
	0xAB, 0x88, 0x29, 0x55, 0x5B, 0x2F, 0x74, 
	0x7C, 0x93, 0x26, 0x65, 0xCB, 0x2C, 0x0F, 
	0x1C, 0xC0, 0x1B, 0xD7, 0x02, 0x29, 0x38, 
	0x88, 0x39, 0xD2, 0xAF, 0x05, 0xE4, 0x54, 
	0x50, 0x4A, 0xC7, 0x8B, 0x75, 0x82, 0x82, 
	0x28, 0x46, 0xC0, 0xBA, 0x35, 0xC3, 0x5F, 
	0x5C, 0x59, 0x16, 0x0C, 0xC0, 0x46, 0xFD, 
	0x82, 0x51, 0x54, 0x1F, 0xC6, 0x8C, 0x9C, 
	0x86, 0xB0, 0x22, 0xBB, 0x70, 0x99, 0x87, 
	0x6A, 0x46, 0x0E, 0x74, 0x51, 0xA8, 0xA9, 
	0x31, 0x09, 0x70, 0x3F, 0xEE, 0x1C, 0x21, 
	0x7E, 0x6C, 0x38, 0x26, 0xE5, 0x2C, 0x51, 
	0xAA, 0x69, 0x1E, 0x0E, 0x42, 0x3C, 0xFC, 
	0x99, 0xE9, 0xE3, 0x16, 0x50, 0xC1, 0x21, 
	0x7B, 0x62, 0x48, 0x16, 0xCD, 0xAD, 0x9A, 
	0x95, 0xF9, 0xD5, 0xB8, 0x01, 0x94, 0x88, 
	0xD9, 0xC0, 0xA0, 0xA1, 0xFE, 0x30, 0x75, 
	0xA5, 0x77, 0xE2, 0x31, 0x83, 0xF8, 0x1D, 
	0x4A, 0x3F, 0x2F, 0xA4, 0x57, 0x1E, 0xFC, 
	0x8C, 0xE0, 0xBA, 0x8A, 0x4F, 0xE8, 0xB6, 
	0x85, 0x5D, 0xFE, 0x72, 0xB0, 0xA6, 0x6E, 
	0xDE, 0xD2, 0xFB, 0xAB, 0xFB, 0xE5, 0x8A, 
	0x30, 0xFA, 0xFA, 0xBE, 0x1C, 0x5D, 0x71, 
	0xA8, 0x7E, 0x2F, 0x74, 0x1E, 0xF8, 0xC1, 
	0xFE, 0x86, 0xFE, 0xA6, 0xBB, 0xFD, 0xE5, 
	0x30, 0x67, 0x7F, 0x0D, 0x97, 0xD1, 0x1D, 
	0x49, 0xF7, 0xA8, 0x44, 0x3D, 0x08, 0x22, 
	0xE5, 0x06, 0xA9, 0xF4, 0x61, 0x4E, 0x01, 
	0x1E, 0x2A, 0x94, 0x83, 0x8F, 0xF8, 0x8C, 
	0xD6, 0x8C, 0x8B, 0xB7, 0xC5, 0xC6, 0x42, 
	0x4C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF
};

const gnutls_datum_t gnutls_ffdhe_8192_group_generator = {
	(void *) &ffdhe_generator, sizeof(ffdhe_generator)
};

const gnutls_datum_t gnutls_ffdhe_8192_group_prime = {
	(void *) ffdhe_params_8192, sizeof(ffdhe_params_8192)
};
const unsigned int gnutls_ffdhe_8192_key_bits = 512;


int _gnutls_set_cred_dh_params(gnutls_dh_params_t *cparams, gnutls_sec_param_t sec_param)
{
	gnutls_dh_params_t tmp_params;
	const gnutls_datum_t *p, *g;
	unsigned key_bits, est_bits;
	unsigned bits;
	int ret;

	bits = gnutls_sec_param_to_pk_bits(GNUTLS_PK_DH, sec_param);

	if (bits <= 2048) {
		p = &gnutls_ffdhe_2048_group_prime;
		g = &gnutls_ffdhe_2048_group_generator;
		key_bits = gnutls_ffdhe_2048_key_bits;
	} else if (bits <= 3072) {
		p = &gnutls_ffdhe_3072_group_prime;
		g = &gnutls_ffdhe_3072_group_generator;
		key_bits = gnutls_ffdhe_3072_key_bits;
	} else if (bits <= 4096) {
		p = &gnutls_ffdhe_4096_group_prime;
		g = &gnutls_ffdhe_4096_group_generator;
		key_bits = gnutls_ffdhe_4096_key_bits;
	} else {
		p = &gnutls_ffdhe_8192_group_prime;
		g = &gnutls_ffdhe_8192_group_generator;
		key_bits = gnutls_ffdhe_8192_key_bits;
	}

	/* if our estimation of subgroup bits is better/larger than
	 * the one provided by the rfc7919, use that one */
	est_bits = _gnutls_pk_bits_to_subgroup_bits(bits);
	if (key_bits < est_bits)
		key_bits = est_bits;

	ret = gnutls_dh_params_init(&tmp_params);
	if (ret < 0)
		return gnutls_assert_val(ret);

	ret = gnutls_dh_params_import_raw2(tmp_params, p, g, key_bits);
	if (ret < 0) {
		gnutls_dh_params_deinit(tmp_params);
		return gnutls_assert_val(ret);
	}

	*cparams = tmp_params;

	return 0;
}
#endif
