/* Copyright (c) 2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __QCOM_WLAN_SECIF_H__
#define __QCOM_WLAN_SECIF_H__

#include <crypto/hash.h>
#include <linux/kobject.h>

/*
 * Prototypes for WLAN Security Interface Functions
 */

extern struct crypto_ahash *
wcnss_wlan_crypto_alloc_ahash(const char *alg_name, u32 type, u32 mask);

extern int wcnss_wlan_crypto_ahash_digest(struct ahash_request *req);
extern void wcnss_wlan_crypto_free_ahash(struct crypto_ahash *tfm);
extern int wcnss_wlan_crypto_ahash_setkey(struct crypto_ahash *tfm,
					const u8 *key, unsigned int keylen);
extern struct crypto_ablkcipher *
wcnss_wlan_crypto_alloc_ablkcipher(const char *alg_name, u32 type, u32 mask);
extern void wcnss_wlan_ablkcipher_request_free(struct ablkcipher_request *req);
extern int wcnss_wlan_kobject_uevent_env(struct kobject *kobj, enum kobject_action action,
		       char *envp_ext[]);
extern int wcnss_wlan_add_uevent_var(struct kobj_uevent_env *env, const char *format, ...)
	__attribute__((format (printf, 2, 3)));

#endif /* __QCOM_WLAN_SECIF_H__ */
